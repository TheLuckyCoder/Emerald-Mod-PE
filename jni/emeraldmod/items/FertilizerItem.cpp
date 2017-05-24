#include "FertilizerItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/BlockSource.h"
#include "minecraftpe/world/entity/Entity.h"
#include "emeraldmod/Emerald.h"

FertilizerItem::FertilizerItem(short id) : Item("emeraldFertilizer", id - 256)
{
	mItems[id] = this;
}

bool FertilizerItem::useOn(ItemInstance &item, Entity &entity, int x, int y, int z, signed char, float, float, float)
{
	BlockSource& region = entity.getRegion();
	if (region.getBlock(x, y, z) == Block::mSapling) {
		region.setBlockAndData({x, y + 1, x}, FullBlock(237, 0), 3, 0); // not working
		item.remove(1);
	}
	return true;
}

