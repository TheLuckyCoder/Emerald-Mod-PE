#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/item/recipes/FurnaceRecipes.h"
#include "minecraftpe/world/entity/player/Player.h"
#include "minecraftpe/world/level/BlockSource.h"

#include "emeraldmod/Emerald.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

#define LOG_TAG "EmeraldModPE"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

//bool bl_setArmorTexture(int, const std::string&);

void (*_initClientData)();
void initClientData()
{
	_initClientData();
	
	LOG("Init Items");
	Emerald::initItems();
	LOG("Items Initiated");
	
	LOG("Init BlockItems");
	Emerald::initBlockItems();
	LOG("BlockItems Initiated");
	
	//bl_setArmorTexture(3800, "textures/models/armor/emerald_1.png");
	//bl_setArmorTexture(3801, "textures/models/armor/emerald_1.png");
	//bl_setArmorTexture(3802, "textures/models/armor/emerald_2.png");
	//bl_setArmorTexture(3803, "models/armor/emerald_1.png");
}

void (*_initCreativeItems)();
void initCreativeItems()
{
	_initCreativeItems();
	
	LOG("Add Items to Creative Inventory");
	Emerald::initCreativeItems();
	LOG("Items added to Creative Inventory");
	
	LOG("Add Blocks to Creative Inventory");
	Emerald::initCreativeBlocks();
	LOG("Blocks added to Creative Inventory");
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();

	LOG("Init Blocks");
	Emerald::initBlocks();
	LOG("Blocks Initiated");
}

void (*_initBlockGraphics)(ResourcePackManager&);
void initBlockGraphics(ResourcePackManager &rpm)
{
	_initBlockGraphics(rpm);

	LOG("Init Block Graphics");
	Emerald::initBlockGraphics();
	LOG("Block Graphics Initiated");
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self)
{
	_initRecipes(self);

	EmeraldRecipes::initRecipes(self);
	LOG("Recipes Initiated");
}

void (*_initFurnaceRecipes)(FurnaceRecipes*);
void initFurnaceRecipes(FurnaceRecipes *recipes)
{
	_initFurnaceRecipes(recipes);
	
	EmeraldRecipes::initFurnaceRecipes(recipes);
	LOG("Furnace Recipes Initiated");
}

/*bool (*_Player$onLadder)(Player*, bool);
bool Player$onLadder(Player *self, bool idk)
{
	if (self->getRegion()->getBlockID(self->getPos().pos.x, self->getPos().pos.y, self->getPos().pos.z) == 237)
		return true;
	return _Player$onLadder(self, idk);
}*/

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR"
		|| langCode == "ko_KR" || langCode == "zh_CN")
		_Localization$_load(self, "emeraldmod/" + langCode);
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	LOG("Function Hooking Started");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	//MSHookFunction((void*) &Player::onLadder, (void*) &Player$onLadder, (void**) &_Player$onLadder);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);

	return JNI_VERSION_1_6;
}

