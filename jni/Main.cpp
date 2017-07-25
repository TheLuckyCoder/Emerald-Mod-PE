#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "emeraldmod/Emerald.h"
#include "emeraldmod/EmeraldRecipes.h"

bool loaded = false;

void (*_loadMinecraft)();
void loadMinecraft()
{
	_loadMinecraft();

	if (!loaded) {
		LOG("Init Items");
		Emerald::registerItems();
		LOG("Items Initiated");

		LOG("Init Blocks");
		Emerald::registerBlocks();
		LOG("Blocks Initiated");

		LOG("Init BlockItems");
		Emerald::registerBlockItems();
		LOG("BlockItems Initiated");

		loaded = true;
	}

	LOG("Add Items and Blocks to Creative");
	Emerald::initCreativeItems();
	Emerald::initCreativeBlocks();
	LOG("Items and Blocks added to Creative");
}

void (*_initClientData)();
void initClientData()
{
	_initClientData();
		
	LOG("Init Item Textures");
	Emerald::setItemTextures();
	LOG("Item Textures Initiated");
}

Item* (*_getArmorForSlot)(ArmorSlot, int);
Item* getArmorForSlot(ArmorSlot armorSlot, int type)
{
	Item* result = null;
	switch (armorSlot) {
		case 0:
			if (type == 6)
				result = Emerald::mHelmet;
			break;
		case 1:
			if (type == 6)
				result = Emerald::mChestplate;
			break;
		case 2:
			if (type == 6)
				result = Emerald::mLeggings;
			break;
		case 3:
			if (type == 6)
				result = Emerald::mBoots;
			break;
	}
	if (result != null)
		return result;
	else
		return _getArmorForSlot(armorSlot, type);
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

void(*_Localization$loadFromPack)(Localization*, std::string const&, PackAccessStrategy&, std::vector<std::string> const&);
void Localization$loadFromPack(Localization *self, std::string const& s1, PackAccessStrategy& pas, std::vector<std::string> const& stringVec) {
	_Localization$loadFromPack(self, s1, pas, stringVec);
	
	if (self->langCode == "en_US" || self->langCode == "de_DE" || self->langCode == "pt_BR"
		|| self->langCode == "ko_KR" || self->langCode == "zh_CN" || self->langCode == "es_ES") {
		std::string backupString = self->langCode;
		self->langCode = "exnihilope/" + self->langCode;
		_Localization$loadFromPack(self, s1, pas, stringVec);
		self->langCode = backupString;
	}
}

void(*_Localization$loadFromResourcePackManager)(Localization*, ResourcePackManager&, std::vector<std::string> const&);
void Localization$loadFromResourcePackManager(Localization *self, ResourcePackManager& rpm, std::vector<std::string> const& stringVec) {
	_Localization$loadFromResourcePackManager(self, rpm, stringVec);
	
	if (self->langCode == "en_US" || self->langCode == "de_DE" || self->langCode == "pt_BR"
		|| self->langCode == "ko_KR" || self->langCode == "zh_CN" || self->langCode == "es_ES") {
		std::string backupString = self->langCode;
		self->langCode = "exnihilope/" + self->langCode;
		_Localization$loadFromResourcePackManager(self, rpm, stringVec);
		self->langCode = backupString;
	}
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
	
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &loadMinecraft, (void**) &_loadMinecraft);
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	//MSHookFunction((void*) &ArmorItem::getArmorForSlot, (void*) &getArmorForSlot, (void**) &_getArmorForSlot);
	//MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	//MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	//MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	MSHookFunction((void*) &Localization::loadFromPack, (void*) &Localization$loadFromPack, (void**) &_Localization$loadFromPack);
	MSHookFunction((void*) &Localization::loadFromResourcePackManager, (void*) &Localization$loadFromResourcePackManager, (void**) &_Localization$loadFromResourcePackManager);
	MSHookFunction(getVersionHook, (void*) &MinecraftScreenModel$getVersionString, (void**) &_MinecraftScreenModel$getVersionString);
	
	dlclose(lib);
	return JNI_VERSION_1_6;
}

