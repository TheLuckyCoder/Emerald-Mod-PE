#pragma once 

#include "minecraftpe/world/item/recipes/Recipes.h" 

class EmeraldRecipes
{ 
public: 
	static void initRecipes(Recipes*);
	
private: 	
	static Recipes* _Instance; 	
	static std::vector<Recipes::Type> _ingredients; 	 	
	static void pushIngredient(int, int, char); 
	static void addRecipe(int, int, int, const std::vector<std::string>&); 
};

