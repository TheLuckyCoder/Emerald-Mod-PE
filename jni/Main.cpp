#include <jni.h>
#include <substrate.h>

#include "minecraftpe/Common.h"
#include "minecraftpe/locale/Localization.h"

#include "emeraldmod/EmeraldMod.h"

bool bl_setArmorTexture(int, std::string const&);

//Hooking Functions
static void (*_initItems)();
static void initItems()
{
	_initItems();
	EmeraldMod::initItems();
	
	//Set Armor Textures
	bl_setArmorTexture(2000, "armor/emerald_1.png");
	bl_setArmorTexture(2001, "armor/emerald_1.png");
	bl_setArmorTexture(2002, "armor/emerald_2.png");
	bl_setArmorTexture(2003, "armor/emerald_1.png");
}

static void (*_initCreativeItems)();
static void initCreativeItems()
{
	_initCreativeItems();

	EmeraldMod::initCreativeItems();
}


static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR" || langCode == "ko_KR" || langCode == "zh_CN" )
		self->_appendTranslations("emeraldmod/" + langCode + ".lang");
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) 
{
	MSHookFunction((void*) &Item::initClientData, (void*) &initItems, (void**) &_initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);

	return JNI_VERSION_1_6;
}

