#include <jni.h>
#include <substrate.h>

#include "minecraftpe/Common.h"
#include "minecraftpe/locale/Localization.h"

#include "emeraldmod/EmeraldMod.h"

//bool bl_setArmorTexture(int, std::string const&);

//Hooking Functions
static void (*_Item$initItems)();
static void Item$initItems()
{
	_Item$initItems();
        EmeraldMod::initItems();
	//EmeraldMod::initBlockItems();
	
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
}


static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization *self, const std::string &langCode)
{
	_Localization$_load(self, langCode);
	
	if(langCode == "en_US" || langCode == "de_DE" || langCode == "pt_BR" || langCode == "ko_KR")
		self->_appendTranslations("loc/emeraldmod/" + langCode + "-pocket.lang");
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 
{
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);

	return JNI_VERSION_1_2;
}

