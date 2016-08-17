#include <jni.h>
#include <substrate.h>

#include "minecraftpe/Common.h"
#include "minecraftpe/locale/Localization.h"

#include "emeraldmod/Emerald.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

std::string sVersion = "v1.4.6";

//bool bl_setArmorTexture(int, std::string const&);

//Hooking Functions
static void (*_Block$initBlocks)();
static void Block$initBlocks()
{
	_Block$initBlocks();
	
	Emerald::initBlocks();
}

static void (*_Item$initItems)();
static void Item$initItems()
{
	Emerald::initItems();
	//Emerald::initBlockItems();
	
	_Item$initItems();
	
	//bl_setArmorTexture(2000, "armor/emerald_1.png");
	//bl_setArmorTexture(2001, "armor/emerald_1.png");
	//bl_setArmorTexture(2002, "armor/emerald_2.png");
	//bl_setArmorTexture(2003, "armor/emerald_1.png");
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems()
{
	_Item$initCreativeItems();

	Emerald::initCreativeItems();
	//Emerald::initCreativeBlocks();
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR" || langCode == "ko_KR")
		self->_appendTranslations("loc/emeraldmod/" + langCode + "-pocket.lang");
}

/*void (*_SmallHut$postProcess)(SmallHut*, BlockSource*, Random&, const BoundingBox&);
void SmallHut$postProcess(SmallHut *self, BlockSource *region, Random &random, const BoundingBox &bounds) {
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
}*/

static void (*_Recipes$init)(Recipes*);
static void Recipes$init(Recipes *self)
{	
	_Recipes$init(self);	

	EmeraldRecipes::initRecipes(self);
}

static std::string (*_Common$getGameDevVersionString)();
static std::string Common$getGameDevVersionString()
{
	return "Emerald Mod " + sVersion + " by The Lucky Coder";
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	//MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	//MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	//MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	//MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	//MSHookFunction((void*) &SmallHut::postProcess, (void*) &SmallHut$postProcess, (void**) &_SmallHut$postProcess);
	//MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);
	MSHookFunction((void*) &Common::getGameDevVersionString, (void*) &Common$getGameDevVersionString, (void**) &_Common$getGameDevVersionString);

	return JNI_VERSION_1_2;
}

