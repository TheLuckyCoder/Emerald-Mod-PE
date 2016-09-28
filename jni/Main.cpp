#include <jni.h>
#include <substrate.h>

#include "minecraftpe/Common.h"
#include "minecraftpe/locale/Localization.h"
#include "minecraftpe/world/level/block/BlockHelper.h"

#include "emeraldmod/EmeraldMod.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

//bool bl_setArmorTexture(int, std::string const&);

//Hooking Functions
static void (*_Block$initBlocks)();
static void Block$initBlocks()
{
	_Block$initBlocks();
	
	EmeraldMod::initBlocks();
}

static void (*_Item$initItems)();
static void Item$initItems()
{
	EmeraldMod::initItems();
	EmeraldMod::initBlockItems();
	
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

	EmeraldMod::initCreativeItems();
	EmeraldMod::initCreativeBlocks();
}

static void (*_BlockGraphics$initBlocks)();
static void BlockGraphics$initBlocks() {
	_BlockGraphics$initBlocks();
	
	BlockHelper::setupBlockGraphics();
}


static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR" || langCode == "ko_KR")
		self->_appendTranslations("loc/emeraldmod/" + langCode + "-pocket.lang");
}


static void (*_Recipes$init)(Recipes*);
static void Recipes$init(Recipes *self)
{	
	_Recipes$init(self);	

	EmeraldRecipes::initRecipes(self);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	MSHookFunction((void*) &Block::initBlocks, (void*) &Block$initBlocks, (void**) &_Block$initBlocks);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	//MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	//MSHookFunction((void*) &Recipes::init, (void*) &Recipes$init, (void**) &_Recipes$init);

	return JNI_VERSION_1_2;
}

