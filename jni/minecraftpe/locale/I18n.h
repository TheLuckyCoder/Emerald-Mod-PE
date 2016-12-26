#pragma once

#include "Localization.h"

class I18n {
private:
	I18n* mLanguages;
	I18n* mCurrentLanguage;
	I18n* mFormatDictionary;
	I18n* mLanguageSupportsHypenSplitting;

public:
	void _addFormatToDictionary(const std::string&, const std::vector<std::string, std::allocator<std::string>>&);
	void _getFormatParmas(const std::string&, std::vector<std::string, std::allocator<std::string>>&);
	void _getKeyExists(const std::string&);
	void _initFormatDictionary();
	void _setLanguageSupportsHypenSplitting(const Localization&);
	static std::string get(const std::string&, const std::vector<std::string>&);
	static std::string get(const std::string&);
	static I18n* getCurrentLanguage(); //returns mCurrentLanguage
	static I18n* getLocaleFor(const std::string&);
	static I18n* getSupportedLocales(); //returns mLanguages
	static I18n* languageSupportsHypenSplitting(); //returns mLanguageSupportsHypenSplitting
	static void loadLanguages(ResourcePackManager&);
	static void chooseLanguage(const Localization&);
	static void chooseLanguage(const std::string&);
};
