#include <jni.h>
#include <android/log.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/entity/player/Player.h"
#include "minecraftpe/world/level/BlockSource.h"

#include "emeraldmod/EmeraldMod.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

#define LOG_TAG "Emerald-Mod"
#define LOG(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static void (*_initClientData)();
static void initClientData()
{
	LOG("Init Items");
	_initClientData();
	
	EmeraldMod::initItems();
	EmeraldMod::initBlockItems();
	LOG("Items Initiated");
}

static void (*_initCreativeItems)();
static void initCreativeItems()
{
	LOG("Add Items to Creative Inventory");
	_initCreativeItems();

	EmeraldMod::initCreativeItems();
	LOG("Items added to Creative Inventory")
}

static void (*_initBlocks)();
static void initBlocks()
{
	LOG("Init Blocks");
	_initBlocks();

	EmeraldMod::initBlocks();
	LOG("Blocks Initiated");
}

static void (*_initBlockGraphics)();
static void initBlockGraphics()
{
	LOG("Init Block Graphics");
	_initBlockGraphics();

	EmeraldMod::initBlockGraphics();
	LOG("Block Graphics Initiated");
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self)
{
	_initRecipes(self);

	EmeraldRecipes:initRecipes(self);
}

/*bool (*_Player$onLadder)(Player*, bool);
bool Player$onLadder(Player* self, bool idk)
{
	if(self->getRegion().getBlockID(self->pos.x, self->pos.y, self->pos.z) == 237)
		return true;
	return _Player$onLadder(self, idk);
}*/

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	LOG("Load Languages");
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR"
		|| langCode == "ko_KR" || langCode == "zh_CN")
		_Localization$_load(self, "emeraldmod/" + langCode);
	LOG("Languages loaded")
}

static std::string (*_MinecraftScreenModel$getVersionString)();
static std::string MinecraftScreenModel$getVersionString()
{
	LOG("Set Screen Version");
	return "Emerald Mod v1.5.1/MCPE " + _MinecraftScreenModel$getVersionString();
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	void* getVersion = dlsym(dlopen("libminecraftpe.so", RTLD_LAZY), "_ZNK20MinecraftScreenModel16getVersionStringEv");
	
	MSHookFunction((void*) &Item::registerItems, (void*) &registerItems, (void**) &_registerItems);
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	//MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	//MSHookFunction((void*) &Player::onLadder, (void*) &Player$onLadder, (void**) &_Player$onLadder);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
    MSHookFunction(getVersion, (void*) &MinecraftScreenModel$getVersionString, (void**) &_MinecraftScreenModel$getVersionString);

	
	return JNI_VERSION_1_6;
}

