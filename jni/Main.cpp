#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/item/recipes/FurnaceRecipes.h"
#include "minecraftpe/world/entity/player/Player.h"
#include "minecraftpe/world/level/BlockSource.h"

#include "emeraldmod/EmeraldMod.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

#define LOG_TAG "Emerald-Mod"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

void (*_initClientData)();
void initClientData()
{
	_initClientData();
	
	LOG("Init Items");
	EmeraldMod::initItems();
	LOG("Items Initiated");
	
	LOG("Init BlockItems");
	EmeraldMod::initBlockItems();
	LOG("BlockItems Initiated");
}

void (*_initCreativeItems)();
void initCreativeItems()
{
	_initCreativeItems();
	
	LOG("Add Items to Creative Inventory");
	EmeraldMod::initCreativeItems();
	LOG("Items added to Creative Inventory");
	
	LOG("Add Blocks to Creative Inventory");
	EmeraldMod::initCreativeBlocks();
	LOG("Blocks added to Creative Inventory");
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();

	LOG("Init Blocks");
	EmeraldMod::initBlocks();
	LOG("Blocks Initiated");
}

void (*_initBlockGraphics)();
void initBlockGraphics()
{
	_initBlockGraphics();

	LOG("Init Block Graphics");
	EmeraldMod::initBlockGraphics();
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
	
	recipes->addFurnaceRecipe(3804, ItemInstance(388, 2, 0));
	recipes->addFurnaceRecipe(3805, ItemInstance(388, 5, 0));
	recipes->addFurnaceRecipe(3806, ItemInstance(388, 3, 0));
	recipes->addFurnaceRecipe(3807, ItemInstance(388, 3, 0));
	recipes->addFurnaceRecipe(3808, ItemInstance(388, 5, 0));
	recipes->addFurnaceRecipe(3809, ItemInstance(388, 1, 0));
	recipes->addFurnaceRecipe(3810, ItemInstance(388, 2, 0));
	LOG("Furnace Recipes Initiated");
}

bool (*_Player$onLadder)(Player*, bool);
bool Player$onLadder(Player *self, bool idk)
{
	if(self->getRegion().getBlockID(self->getPos().x, self->getPos().y, self->getPos().z) == 237)
		return true;
	return _Player$onLadder(self, idk);
}

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

