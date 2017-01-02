#pragma once 

#include "minecraftpe/world/item/recipes/Recipes.h" 

class EmeraldRecipes
{ 
public: 
	static void initRecipes(Recipes *recipes);
	
private: 	
	static Recipes* _Instance;
	static std::vector<Recipes::Type> _ingredients;
	static void pushIngredient(int id, char letter);
	static void pushIngredient(int id, int data, char letter);
	static void addRecipe(int, int, int, const std::vector<std::string>&);
};

