#include "EmeraldRecipes.h"

#include "Emerald.h"

Recipes* EmeraldRecipes::_Instance;
std::vector<Recipes::Type> EmeraldRecipes::_ingredients;

void EmeraldRecipes::initRecipes(Recipes *recipes)
{	
	_Instance = recipes;
	
	/*// Helmet
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mHelmet->itemId, 1, 0, {"eee", "e e", "   "});
	
	// Chestplate
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mChestplate->itemId, 1, 0, {"e e", "eee", "eee"});
	
	// Leggings
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mLeggings->itemId, 1, 0, {"eee", "e e", "e e"});
	
	// Boots
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mBoots->itemId, 1, 0, {"   ", "e e", "e e"});*/
	
	// Sword
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mSword->itemId, 1, 0, {" e ", " e ", " s "});
	
	// Super Sword
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Emerald::mStick, 'r');
	addRecipe(Emerald::mSuperSword->itemId, 1, 0, {" e ", " e ", " r "});
	
	// Pickaxe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mPickaxe->itemId, 1, 0, {"eee", " s ", " s "});
	
	// Super Pickaxe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Emerald::mStick, 's');
	addRecipe(Emerald::mPickaxe->itemId, 1, 0, {"eee", " s ", " s "});
	
	// Axe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mAxe->itemId, 1, 0, {"ee ", "es ", " s "});
	
	// Super Axe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Emerald::mStick, 's');
	addRecipe(Emerald::mAxe->itemId, 1, 0, {"ee ", "es ", " s "});
	
	// Pax
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mPax->itemId, 1, 0, {"eee", "es ", " s "});
	
	// Shovel
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mShovel->itemId, 1, 0, {" e ", " s ", " s "});
	
	// Super Shovel
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Emerald::mStick, 's');
	addRecipe(Emerald::mShovel->itemId, 1, 0, {" e ", " s ", " s "});
	
	// Hoe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(Emerald::mHoe->itemId, 1, 0, {"ee ", " s ", " s "});
	
	// Super Hoe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Emerald::mStick, 's');
	addRecipe(Emerald::mHoe->itemId, 1, 0, {"ee ", " s ", " s "});
	
	// Flint and Emerald
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mFlint, 'f');
	addRecipe(Emerald::mFlintAndEmerald->itemId, 1, 0, {"f ", " e"});
	
	// Battle Axe
	pushIngredient(Item::mStick, 's');
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mBattleAxe->itemId, 1, 0, {"eee", " s ", " s "});
	
	// Stick
	pushIngredient(Emerald::mNugget, 'n');
	addRecipe(Emerald::mStick->itemId, 1, 0, {"  n", " n ", "n  "});
	
	// Nugget
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(Emerald::mNugget->itemId, 9, 0, {"e ", "  "});
	
	// Emerald
	pushIngredient(Emerald::mNugget, 'n');
	addRecipe(Item::mEmerald->itemId, 5, 0, {"nnn", "nnn", "nnn"});
	
	/* BLOCKS */
	// Planks
	pushIngredient(Emerald::mNugget, 'n');
	pushIngredient(5, 0, 'b');
	addRecipe(Emerald::mPlanks->blockId, 1, 0, {" n ", "nbn", " n "});
	
	// Bricks
	pushIngredient(Emerald::mNugget, 'n');
	pushIngredient(98, 0, 'b');
	addRecipe(Emerald::mBrick->blockId, 1, 0, {" n ", "nbn", " n "});
	
	// Fence
	pushIngredient(Emerald::mStick, 's');
	pushIngredient(Emerald::mPlanks, 'p');
	addRecipe(Emerald::mBrick->blockId, 1, 0, {" n ", "nbn", " n "});
}

void EmeraldRecipes::initFurnaceRecipes(FurnaceRecipes *recipes)
{
	recipes->addFurnaceRecipe(Emerald::mSword->itemId, ItemInstance(Emerald::mNugget->itemId, 2, 0));
	recipes->addFurnaceRecipe(Emerald::mPickaxe->itemId, ItemInstance(Emerald::mNugget->itemId, 3, 0));
	recipes->addFurnaceRecipe(Emerald::mAxe->itemId, ItemInstance(Emerald::mNugget->itemId, 3, 0));
	recipes->addFurnaceRecipe(Emerald::mPax->itemId, ItemInstance(Emerald::mNugget->itemId, 4, 0));
	recipes->addFurnaceRecipe(Emerald::mShovel->itemId, ItemInstance(Emerald::mNugget->itemId, 1, 0));
	recipes->addFurnaceRecipe(Emerald::mHoe->itemId, ItemInstance(Emerald::mNugget->itemId, 2, 0));
}

void EmeraldRecipes::pushIngredient(Block *block, char letter)
{
	Recipes::Type type {NULL, block, ItemInstance(*block, 1, 0), letter};
	_ingredients.push_back(type);
}

void EmeraldRecipes::pushIngredient(Item *item, char letter)
{
	Recipes::Type type {item, NULL, ItemInstance(*item, 1, 0), letter};
	_ingredients.push_back(type);
}

void EmeraldRecipes::pushIngredient(short id, short data, char letter)
{
	Recipes::Type type {Item::mItems[id], NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
}

void EmeraldRecipes::addRecipe(short outputId, short outputCount, short outputData, const std::vector<std::string> &shape)
{
	_Instance->addShapedRecipe(ItemInstance(outputId, outputCount, outputData), shape, _ingredients);	
	_ingredients.clear();
}

