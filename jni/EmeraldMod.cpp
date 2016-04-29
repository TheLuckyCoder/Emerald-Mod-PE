#include <jni.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <substrate.h>
#include "tinyhook.h"
#include "dl_internal.h"

#include "mcpe/Common.h"
#include "mcpe/client/MinecraftClient.h"
#include "mcpe/locale/Localization.h"
#include "mcpe/world/level/levelgen/structure/village/components/SmallHut.h"

#include "emerald/Emerald.h"
#include "emerald/recipes/EmeraldRecipes.h"
#include "emerald/dimension/EmeraldDimension.h"

#define LOG_TAG "Emerald-Mod"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

std::string MOD_NAME = "Emerald Mod";
std::string MOD_VERSION = "v1.4.3";

Emerald* emerald;
bool bl_setArmorTexture(int, std::string const&);

//Hook functions
void (*_MinecraftClient$onPlayerLoaded)(MinecraftClient*, Player&);
void MinecraftClient$onPlayerLoaded(MinecraftClient *self, Player &player){
	_MinecraftClient$onPlayerLoaded(self, player);
	
	self->sendLocalMessage(MOD_NAME, "Made by Razvan MCrafter");
}

static void (*_Block$initBlocks)();
static void Block$initBlocks() {
	_Block$initBlocks();
	
	emerald->initBlocks();
}

static void (*_Item$initItems)();
static void Item$initItems(){
	emerald->initItems();
	emerald->initBlockItems();
	
	_Item$initItems();
	
	bl_setArmorTexture(2000, "armor/emerald_1.png");
	bl_setArmorTexture(2001, "armor/emerald_1.png");
	bl_setArmorTexture(2002, "armor/emerald_2.png");
	bl_setArmorTexture(2003, "armor/emerald_1.png");
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();

	emerald->initCreativeItems();
	//emerald->initCreativeBlocks();
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization *self, const std::string &langCode) {
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR" || langCode == "ko_KR")
		self->_appendTranslations("loc/emerald/" + langCode + "-pocket.lang");
}

void (*_SmallHut$postProcess)(SmallHut*, BlockSource*, Random&, BoundingBox const&);
void SmallHut$postProcess(SmallHut *self, BlockSource *region, Random &random, BoundingBox const &bounds) {
	int y = 5;
	
	if(region->getBlockID(0, 4, 0).blockId == 0) y = 4;
	if(region->getBlockID(0, 3, 0).blockId == 0) y = 3;
	if(region->getBlockID(0, 2, 0).blockId == 0) y = 2;
	if(region->getBlockID(0, 1, 0).blockId == 0) y = 1;
	if(region->getBlockID(0, 0, 0).blockId == 0) y = 0;
	if(region->getBlockID(0, -1, 0).blockId == 0) y = -1;
	if(region->getBlockID(0, -2, 0).blockId == 0) y = -2;
	if(region->getBlockID(0, -3, 0).blockId == 0) y = -3;
	if(region->getBlockID(0, -4, 0).blockId == 0) y = -4;
	if(region->getBlockID(0, -5, 0).blockId == 0) y = -5;
	if(region->getBlockID(0, -6, 0).blockId == 0) y = -6;
	if(region->getBlockID(0, -7, 0).blockId == 0) y = -7;
	
	self->generateBox(region, bounds, 0, y, 0, 4, y+4, 4, {Emerald::mBrick->blockId, 0}, {0, 0}, false);
	//floor
	self->generateBox(region, bounds, 1, y, 1, 3, y, 3, {Emerald::mPlanks->blockId, 0}, {Emerald::mPlanks->blockId, 0}, true);
	//front
	self->generateBox(region, bounds, 1, y+1, 0, 3, y+3, 0, {Emerald::mPlanks->blockId, 0}, {Emerald::mPlanks->blockId, 0}, true);
	//back
	self->generateBox(region, bounds, 1, y+1, 4, 3, y+3, 4, {Emerald::mPlanks->blockId, 0}, {Emerald::mPlanks->blockId, 0}, true);
	//right
	self->generateBox(region, bounds, 0, y+1, 1, 0, y+3, 3, {Emerald::mPlanks->blockId, 0}, {Emerald::mPlanks->blockId, 0}, true);
	self->placeBlock(region, {Block::mGlassPane->blockId, 0}, 0, y+2, 2, bounds);
	//left
	self->generateBox(region, bounds, 4, y+1, 1, 4, y+3, 3, {Emerald::mPlanks->blockId, 0}, {Emerald::mPlanks->blockId, 0}, true);
	self->placeBlock(region, {Block::mGlassPane->blockId, 0}, 4, y+2, 2, bounds);
		
	//other
	self->createDoor(region, bounds, random, 2, y+1, 0, 0);
	self->placeBlock(region, {Block::mWorkBench->blockId, 0}, 3, y+1, 3, bounds);
	//under
	self->generateBox(region, bounds, 1, y-1, 1, 3, y-3, 3, {Block::mCobblestone->blockId, 0}, {Block::mCobblestone->blockId, 0}, false);
}

static void (*_Recipes$init)(Recipes*);
static void Recipes$init(Recipes *self) {	
	_Recipes$init(self);	

	EmeraldRecipes::initRecipes(self);
}

static std::string (*_Common$getGameDevVersionString)();
static std::string Common$getGameDevVersionString() {
	return (MOD_NAME + " " + MOD_VERSION);
}

static std::unique_ptr<Dimension> (*Dimension$createNew_real)(DimensionId, Level &);
static std::unique_ptr<Dimension> Dimension$createNew_hook(DimensionId id, Level &level)
{
	if(id == DimensionId::EMERALD)
		return std::unique_ptr<Dimension>(new EmeraldDimension(level));

	return Dimension$createNew_real(id, level);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	soinfo2 *tinyHandle = (soinfo2 *) dlopen("libminecraftpe.so", RTLD_LAZY);

	MSHookFunction((void*) &MinecraftClient::onPlayerLoaded, (void*) &MinecraftClient$onPlayerLoaded, (void**) &_MinecraftClient$onPlayerLoaded);
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction((void*) &SmallHut::postProcess, (void*) &SmallHut$postProcess, (void**) &_SmallHut$postProcess);
	MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);
	//MSHookFunction((void*) &Dimension::createNew, (void *) &Dimension$createNew_hook, (void **) &Dimension$createNew_real);

	return JNI_VERSION_1_2;
}
