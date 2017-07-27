#pragma once 

#include "minecraftpe/world/item/recipes/Recipes.h"
#include "minecraftpe/world/item/recipes/FurnaceRecipes.h"

class EmeraldRecipes
{ 
public: 
	static void initRecipes(Recipes *recipes);
	static void initFurnaceRecipes(FurnaceRecipes *recipes);
	
private: 	
	static Recipes* _Instance;
	static std::vector<Recipes::Type> _ingredients;
	static void pushIngredient(Block *block, char letter);
	static void pushIngredient(Item *item, char letter);
	static void pushIngredient(short id, short data, char letter);
	static void addRecipe(short outputId, short outputCount, short outputData, const std::vector<std::string> &shape);
};

