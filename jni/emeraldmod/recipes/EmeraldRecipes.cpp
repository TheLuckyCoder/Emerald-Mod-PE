#include "EmeraldRecipes.h"

#include "minecraftpe/world/item/Item.h"

Recipes* EmeraldRecipes::_Instance;
std::vector<Recipes::Type> EmeraldRecipes::_ingredients;

void EmeraldRecipes::initRecipes(Recipes* instance)
{	
	_Instance = instance;
	
	/*//Helmet
	pushIngredient(388, 'e');
	addRecipe(3800, 1, 0, {"eee", "e e", "   "});
	
	//Chestplate
	pushIngredient(388, 'e');
	addRecipe(3801, 1, 0, {"e e", "eee", "eee"});
	
	//Leggings
	pushIngredient(388, 'e');
	addRecipe(3802, 1, 0, {"eee", "e e", "e e"});
	
	//Boots
	pushIngredient(388, 'e');
	addRecipe(3803, 1, 0, {"   ", "e e", "e e"});*/
	
	//Sword
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3804, 1, 0, {" e ", " e ", " s "});
	
	//Super Sword
	pushIngredient(388, 'e');
	pushIngredient(3813, 'r');
	addRecipe(3805, 1, 0, {" e ", " e ", " r "});
	
	//Pickaxe
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3806, 1, 0, {"eee", " s ", " s "});
	
	//Axe
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3807, 1, 0, {"ee ", "es ", " s "});
	
	//Pax
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3808, 1, 0, {"eee", "es ", " s "});
	
	//Shovel
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3809, 1, 0, {" e ", " s ", " s "});
	
	//Hoe
	pushIngredient(388, 'e');
	pushIngredient(280, 's');
	addRecipe(3810, 1, 0, {"ee ", " s ", " s "});
	
	//Flint and Emerald
	pushIngredient(388, 'e');
	pushIngredient(318, 'f');
	addRecipe(3811, 1, 0, {"f ", " e"});
	
	/*//Bow
	pushIngredient(287, 's');
	pushIngredient(3813, 'r');
	addRecipe(3812, 1, 0, {" rs", "r s", " rs"});*/
	
	//Stick
	pushIngredient(388, 'e');
	addRecipe(3813, 5, 0, {"e ", "e "});
}

void EmeraldRecipes::pushIngredient(int id, char letter)
{
	pushIngredient(id, 0, letter);
}

void EmeraldRecipes::pushIngredient(int id, int data, char letter)
{
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void EmeraldRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string>& shape)
{
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}

