#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "minecraftpe/client/render/entity/HumanoidMobRenderer.h"
#include "minecraftpe/client/render/TextureGroup.h"
#include "minecraftpe/client/resource/ResourceLocation.h"
#include "minecraftpe/client/resource/ResourceFileSystem.h"
#include "minecraftpe/world/item/ArmorItem.h"
#include "emeraldmod/Emerald.h"
#include "emeraldmod/EmeraldRecipes.h"

#define LOG_TAG "EmeraldMod"
#define LOG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

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
	Emerald::addCreativeItems();
	Emerald::addCreativeBlocks();
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

Item* (*_getArmorForSlot)(ArmorSlot, int);
Item* getArmorForSlot(ArmorSlot armorSlot, int type)
{
	Item* result = NULL;
	switch (armorSlot) {
		case ArmorSlot::HELMET:
			if (type == 40)
				result = Emerald::mHelmet;
			break;
		case ArmorSlot::CHESTPLATE:
			if (type == 40)
				result = Emerald::mChestplate;
			break;
		case ArmorSlot::LEGGINGS:
			if (type == 40)
				result = Emerald::mLeggings;
			break;
		case ArmorSlot::BOOTS:
			if (type == 40)
				result = Emerald::mBoots;
			break;
	}
	if (result != NULL)
		return result;
	else
		return _getArmorForSlot(armorSlot, type);
}

void (*_initArmorTextures)(HumanoidMobRenderer*);
void initArmorTextures(HumanoidMobRenderer *self)
{
	_initArmorTextures(self);

	LOG("Init Armor Textures");
	mce::TextureGroup* group = self->armorTextures[0].getGroup();
	self->armorTextures[40] = group->getTexture(ResourceLocation("textures/models/armor/emerald_1", ResourceFileSystem::InUserPackage), false);
	self->armorTextures[41] = group->getTexture(ResourceLocation("textures/models/armor/emerald_2", ResourceFileSystem::InUserPackage), false);
}

void (*_Localization$loadFromResourcePackManager)(Localization*, ResourcePackManager&, const std::vector<std::string>&);
void Localization$loadFromResourcePackManager(Localization *self, ResourcePackManager &rpm, const std::vector<std::string> &stringVec) {
	_Localization$loadFromResourcePackManager(self, rpm, stringVec);
	
	LOG("Load lang from ResourcePackManager");
	if (self->langCode == "en_US" || self->langCode == "de_DE" || self->langCode == "pt_BR"
		|| self->langCode == "ko_KR" || self->langCode == "zh_CN" || self->langCode == "es_ES") {
		std::string backupString = self->langCode;
		self->langCode = "emeraldmod/" + self->langCode;
		_Localization$loadFromResourcePackManager(self, rpm, stringVec);
		self->langCode = backupString;
	}
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	LOG("Function Hooking Started");
		
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &loadMinecraft, (void**) &_loadMinecraft);
	MSHookFunction((void*) &Item::initClientData, (void*) &initClientData, (void**) &_initClientData);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	MSHookFunction((void*) &FurnaceRecipes::_init, (void*) &initFurnaceRecipes, (void**) &_initFurnaceRecipes);
	MSHookFunction((void*) &ArmorItem::getArmorForSlot, (void*) &getArmorForSlot, (void**) &_getArmorForSlot);
	MSHookFunction((void*) &HumanoidMobRenderer::initTextures, (void*) &initArmorTextures, (void**) &_initArmorTextures);
	MSHookFunction((void*) &Localization::loadFromResourcePackManager, (void*) &Localization$loadFromResourcePackManager, (void**) &_Localization$loadFromResourcePackManager);
	
	return JNI_VERSION_1_6;
}

