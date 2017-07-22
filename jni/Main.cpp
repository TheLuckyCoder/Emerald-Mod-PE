#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/world/entity/player/Player.h"
#include "minecraftpe/world/level/BlockSource.h"
#include "emeraldmod/Emerald.h"
#include "emeraldmod/EmeraldRecipes.h"

void (*_registerItems)();
void registerItems()
{
	_registerItems();
	
	LOG("Init Items");
	Emerald::registerItems();
	LOG("Items Initiated");
	
	/*LOG("Init BlockItems");
	Emerald::registerBlockItems();
	LOG("BlockItems Initiated");*/
}

void (*_initClientData)();
void initClientData()
{
	_initClientData();
	
	Emerald::registerItems();
	
	LOG("Init Item Textures");
	Emerald::initClientData();
	LOG("Item Textures Initiated");
}

void (*_initCreativeItems)();
void initCreativeItems()
{
	_initCreativeItems();
	
	Emerald::registerItems();
	
	LOG("Add Items to Creative");
	Emerald::initCreativeItems();
	LOG("Items added to Creative");
	
	/*LOG("Add Blocks to Creative");
	Emerald::initCreativeBlocks();
	LOG("Blocks added to Creative");*/
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();

	LOG("Init Blocks");
	Emerald::registerBlocks();
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

	LOG("Add Recipes");
	EmeraldRecipes::initRecipes(self);
	LOG("Recipes Added");
}

void (*_initFurnaceRecipes)(FurnaceRecipes*);
void initFurnaceRecipes(FurnaceRecipes *self)
{
	_initFurnaceRecipes(self);
	
	LOG("Add Furnace Recipes");
	EmeraldRecipes::initFurnaceRecipes(self);
	LOG("Furnace Recipes Added");
}

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR"
		|| langCode == "ko_KR" || langCode == "zh_CN")
		_Localization$_load(self, "emeraldmod/" + langCode);
}

std::string (*_MinecraftScreenModel$getVersionString)();
std::string MinecraftScreenModel$getVersionString()
{
	return "Emerald Mod 1.6.1/" + _MinecraftScreenModel$getVersionString();
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	LOG("Function Hooking Started");
	
	void* lib = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* getVersionHook = dlsym(lib, "_ZNK20MinecraftScreenModel16getVersionStringEv");
	
	MSHookFunction((void*) &Item::registerItems, (void*) &registerItems, (void**) &_registerItems);
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	//MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	//MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	//MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	//MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	//MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction(getVersionHook, (void*) &MinecraftScreenModel$getVersionString, (void**) &_MinecraftScreenModel$getVersionString);
	
	dlclose(lib);
	return JNI_VERSION_1_6;
}

