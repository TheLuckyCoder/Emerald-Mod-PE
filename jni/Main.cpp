#include <jni.h>
#include "substrate.h"

#include "minecraftpe/client/locale/Localization.h"
#include "emeraldmod/EmeraldMod.h"
#include "emeraldmod/recipes/EmeraldRecipes.h"

static void (*_initItems)();
static void initItems()
{
	_initItems();
	
	EmeraldMod::initItems();
	EmeraldMod::initBlockItems();
}

static void (*_initCreativeItems)();
static void initCreativeItems()
{
	_initCreativeItems();

	EmeraldMod::initCreativeItems();
}

static void (*_initBlocks)();
static void initBlocks()
{
	_initBlocks();

	EmeraldMod::initBlocks();
}

static void (*_initBlockGraphics)();
static void initBlockGraphics()
{
	_initBlockGraphics();

	EmeraldMod::initBlockGraphics();
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self)
{
	_initRecipes(self);

	EmeraldRecipes:initRecipes(self);
}

void (*_Localization$_load)(Localization*, const std::string&);
void Localization$_load(Localization *self, const std::string &langCode)
{
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR"
		|| langCode == "ko_KR" || langCode == "zh_CN")
		self->_appendTranslations("texts/emeraldmod/" + langCode + ".lang");
	
	_Localization$_load(self, langCode);
}

static std::string (*_MinecraftScreenModel$getVersionString)();
static std::string MinecraftScreenModel$getVersionString()
{
	return "Emerald Mod v1.5.0/MCPE " + _MinecraftScreenModel$getVersionString();
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	void* getVersion = dlsym(dlopen("libminecraftpe.so", RTLD_LAZY), "_ZNK20MinecraftScreenModel16getVersionStringEv");
	
	MSHookFunction((void*) &Item::initClientData, (void*) &initItems, (void**) &_initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	//MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	//MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
    MSHookFunction(getVersion, (void*) &MinecraftScreenModel$getVersionString, (void**) &_MinecraftScreenModel$getVersionString);

	
	return JNI_VERSION_1_6;
}

