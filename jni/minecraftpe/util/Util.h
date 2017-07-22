#pragma once

#include <vector>
#include <string>
#include <sstream>

class Util
{
public:
	static std::string EMPTY_STRING;
	static std::string EMPTY_GUID;
	
	static std::vector<std::string> split(const std::string &, char);
	static void splitString(std::string const &, char, std::vector<std::string> &);
	static std::string toString(float);
	static std::string toNiceString(int);
	static std::string toLower(const std::string &);
};

