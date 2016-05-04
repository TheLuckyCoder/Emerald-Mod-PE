#include "EmeraldRecipes.h"

#include "mcpe/world/item/Item.h"
#include "mcpe/world/level/block/Block.h"

Recipes* EmeraldRecipes::_Instance;
std::vector<Recipes::Type> EmeraldRecipes::_ingredients;

void EmeraldRecipes::initRecipes(Recipes* instance) {	
	_Instance = instance;
	
	//Helmet
	pushIngredient(388, 0, 'e');
	addRecipe(Item::mItems[2000]->itemId, 1, 0, {"eee", "e e", "   "});
	
	//Chestplate
	pushIngredient(388, 0, 'e');
	addRecipe(Item::mItems[2001]->itemId, 1, 0, {"e e", "eee", "eee"});
	
	//Leggings
	pushIngredient(388, 0, 'e');
	addRecipe(Item::mItems[2002]->itemId, 1, 0, {"eee", "e e", "e e"});
	
	//Boots
	pushIngredient(388, 0, 'e');
	addRecipe(Item::mItems[2003]->itemId, 1, 0, {"   ", "e e", "e e"});
	
	//Sword
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2004]->itemId, 1, 0, {" e ", " e ", " s "});
	
	//Super Sword
	pushIngredient(388, 0, 'e');
	pushIngredient(2013, 0, 'r');
	addRecipe(Item::mItems[2005]->itemId, 1, 0, {" e ", " e ", " r "});
	
	//Pickaxe
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2006]->itemId, 1, 0, {"eee", " s ", " s "});
	
	//Axe
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2007]->itemId, 1, 0, {"ee ", "es ", " s "});
	
	//Pax
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2008]->itemId, 1, 0, {"eee", "es ", " s "});
	
	//Shovel
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2009]->itemId, 1, 0, {" e ", " s ", " s "});
	
	//Hoe
	pushIngredient(388, 0, 'e');
	pushIngredient(280, 0, 's');
	addRecipe(Item::mItems[2010]->itemId, 1, 0, {"ee ", " s ", " s "});
	
	//Flint and Emerald
	pushIngredient(388, 0, 'e');
	pushIngredient(318, 0, 'f');
	addRecipe(Item::mItems[2011]->itemId, 1, 0, {"f ", " e"});
	
	//Bow
	pushIngredient(287, 0, 's');
	pushIngredient(2013, 0, 'r');
	addRecipe(Item::mItems[2012]->itemId, 1, 0, {" rs", "r s", " rs"});
	
	//Rod
	pushIngredient(388, 0, 'e');
	addRecipe(Item::mItems[2013]->itemId, 5, 0, {"e ", "e "});
	
	//Dust
	pushIngredient(2013, 0, 'r');
	addRecipe(Item::mItems[2014]->itemId, 4, 0, {"r ", "  "});
	
	//Apple
	pushIngredient(388, 0, 'e');
	pushIngredient(260, 0, 'a');
	addRecipe(Item::mItems[512]->itemId, 1, 0, {"ea", "  "});
	
	///Blocks
	//Slab
	pushIngredient(133, 0, 'b');
	pushIngredient(2014, 0, 'd');
	addRecipe(Block::mBlocks[233]->blockId, 1, 0, {"bbb", "   ", "   "});
	
	//Brick
	pushIngredient(98, 0, 's');
	pushIngredient(2014, 0, 'd');
	addRecipe(Block::mBlocks[231]->blockId, 1, 0, {"sd", "  "});
	
	//Planks
	pushIngredient(4, 0, 'p');
	pushIngredient(2014, 0, 'd');
	addRecipe(Block::mBlocks[232]->blockId, 1, 0, {"pd", "  "});
	
}

void EmeraldRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void EmeraldRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string>& shape) {
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}
