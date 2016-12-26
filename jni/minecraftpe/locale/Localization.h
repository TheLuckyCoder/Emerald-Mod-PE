#pragma once

#include <string>
#include <vector>

class ResourcePackManager;
class State;

class Localization {
public:
	Localization(const std::string&, ResourcePackManager&);

	void _appendTranslations(const std::string&);
	void _get(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
	void _getSimple(std::string const&);
	State _getState();
	void _getStrings();
	void _load(std::string const&);
	void _parseFormattedString(std::string const&);
	void _replaceTokens(std::string &, std::vector<std::string, std::allocator<std::string>> const&);
	void _setState(State);
	void get(std::string const&, std::string &, std::vector<std::string, std::allocator<std::string>> const&);
	void* getCommaSeperator();
	std::string getFullLanguageCode();
	std::string getLanguageCode(const std::string&);
	std::string getLanguageCode();
	std::string getRegionCode(const std::string&);
	std::string getRegionCode();
	void* getStringIdExists(const std::string&);
	bool isFormattedString(const std::string&);
};
