#pragma once

#include <memory>

class ItemInstance;

class FurnaceRecipes
{
public:
	FurnaceRecipes();

	bool isFurnaceItem(const ItemInstance*) const;
	ItemInstance getResult(const ItemInstance*) const;
	void addFurnaceRecipe(int, const ItemInstance&);
	void addFurnaceRecipeAuxData(short, short, const ItemInstance&);
	void getResult(const ItemInstance*);
	bool isFurnaceItem(const ItemInstance*);
	void _init();

	// static
	static void init();
	static void teardownFurnaceRecipes();
	static FurnaceRecipes* getInstance();

	// static fields
	static std::unique_ptr<FurnaceRecipes> mInstance;
};
