#include "EmeraldRecipes.h"

#include "../EmeraldMod.h"

Recipes* EmeraldRecipes::_Instance;
std::vector<Recipes::Type> EmeraldRecipes::_ingredients;

void EmeraldRecipes::initRecipes(Recipes *recipes)
{	
	_Instance = recipes;
	
	/*// Helmet
	pushIngredient(388, 'e');
	addRecipe(EmeraldMod::mHelmet->itemId, 1, 0, {"eee", "e e", "   "});
	
	// Chestplate
	pushIngredient(388, 'e');
	addRecipe(EmeraldMod::mChestplate->itemId, 1, 0, {"e e", "eee", "eee"});
	
	// Leggings
	pushIngredient(388, 'e');
	addRecipe(EmeraldMod::mLeggings->itemId, 1, 0, {"eee", "e e", "e e"});
	
	// Boots
	pushIngredient(388, 'e');
	addRecipe(EmeraldMod::mBoots->itemId, 1, 0, {"   ", "e e", "e e"});*/
	
	// Sword
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mSword->itemId, 1, 0, {" e ", " e ", " s "});
	
	// Super Sword
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(EmeraldMod::mStick, 'r');
	addRecipe(EmeraldMod::mSuperSword->itemId, 1, 0, {" e ", " e ", " r "});
	
	// Pickaxe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mPickaxe->itemId, 1, 0, {"eee", " s ", " s "});
	
	// Axe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mAxe->itemId, 1, 0, {"ee ", "es ", " s "});
	
	// Pax
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mPax->itemId, 1, 0, {"eee", "es ", " s "});
	
	// Shovel
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mShovel->itemId, 1, 0, {" e ", " s ", " s "});
	
	// Hoe
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mStick, 's');
	addRecipe(EmeraldMod::mHoe->itemId, 1, 0, {"ee ", " s ", " s "});
	
	// Flint and Emerald
	pushIngredient(Item::mEmerald, 'e');
	pushIngredient(Item::mFlint, 'f');
	addRecipe(EmeraldMod::mFlintAndEmerald->itemId, 1, 0, {"f ", " e"});
	
	/*// Bow
	pushIngredient(287, 's');
	pushIngredient(3813, 'r');
	addRecipe(EmeraldMod::mBow->itemId, 1, 0, {" rs", "r s", " rs"});*/
	
	// Stick
	pushIngredient(EmeraldMod::mNugget, 'n');
	addRecipe(EmeraldMod::mStick->itemId, 1, 0, {"  n", " n ", "n  "});
	
	// Nugget
	pushIngredient(Item::mEmerald, 'e');
	addRecipe(EmeraldMod::mNugget->itemId, 9, 0, {"e ", "  "});
	
	// Emerald
	pushIngredient(EmeraldMod::mNugget, 'n');
	addRecipe(Item::mEmerald->itemId, 5, 0, {"nnn", "nnn", "nnn"});
	
	/* BLOCKS */
	// Planks
	pushIngredient(EmeraldMod::mNugget, 'n');
	pushIngredient(5, 0, 'b');
	addRecipe(EmeraldMod::mPlanks->blockId, 1, 0, {" n ", "nbn", " n "});
	
	// Bricks
	pushIngredient(EmeraldMod::mNugget, 'n');
	pushIngredient(98, 0, 'b');
	addRecipe(EmeraldMod::mBrick->blockId, 1, 0, {" n ", "nbn", " n "});
	
	// Fence
	pushIngredient(EmeraldMod::mStick, 's');
	pushIngredient(EmeraldMod::mPlanks->blockId, 0, 'p');
	addRecipe(EmeraldMod::mBrick->blockId, 1, 0, {" n ", "nbn", " n "});
}

void EmeraldRecipes::initFurnaceRecipes(FurnaceRecipes *recipes)
{
	recipes->addFurnaceRecipe(EmeraldMod::mSword->itemId, ItemInstance(388, 2, 0));
	recipes->addFurnaceRecipe(EmeraldMod::mPickaxe->itemId, ItemInstance(388, 3, 0));
	recipes->addFurnaceRecipe(EmeraldMod::mAxe->itemId, ItemInstance(388, 3, 0));
	recipes->addFurnaceRecipe(EmeraldMod::mPax->itemId, ItemInstance(388, 5, 0));
	recipes->addFurnaceRecipe(EmeraldMod::mShovel->itemId, ItemInstance(388, 1, 0));
	recipes->addFurnaceRecipe(EmeraldMod::mHoe->itemId, ItemInstance(388, 2, 0));
}

void EmeraldRecipes::pushIngredient(Item *item, char letter)
{
	pushIngredient(item->itemId, 0, letter);
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

