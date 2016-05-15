#pragma once

#include <vector>

class Random;
class Container;

class WeighedTreasureItem
{
public:
	void addChestItems(Random&, std::vector<WeighedTreasureItem, const std::allocator<WeighedTreasureItem>>&, Container&, int);
};
