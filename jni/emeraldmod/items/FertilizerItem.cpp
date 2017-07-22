#include "FertilizerItem.h"
#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/level/BlockSource.h"
#include "minecraftpe/world/entity/Entity.h"
#include "emeraldmod/Emerald.h"

FertilizerItem::FertilizerItem(short id) : Item("emerald_fertilizer", id - 256)
{
	mItems[id] = this;
}

bool FertilizerItem::_useOn(ItemInstance &item, Entity &entity, BlockPos pos, signed char, float, float, float) const
{
	BlockSource& region = entity.getRegion();
	if (region.getBlock(pos) == Block::mSapling) {
		region.setBlockAndData({pos.x, pos.y + 1, pos.x}, FullBlock(237, 0), 3, 0); // not working
		item.remove(1);
	}
	return true;
}

