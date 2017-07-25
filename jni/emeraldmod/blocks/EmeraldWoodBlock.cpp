#include "EmeraldWoodBlock.h"
#include "minecraftpe/world/level/block/FireBlock.h"

EmeraldWoodBlock::EmeraldWoodBlock(const std::string &name, short id) : Block(name, id, Material::getMaterial(MaterialType::WOOD))
{
	mBlocks[id] = this;
	init();
	setCategory(CreativeItemCategory::BLOCKS);
	setExplodeable(10);
	setDestroyTime(2);

	((FireBlock*)mFire)->setFlammable(BlockID(id), 50, 10);
}

int EmeraldWoodBlock::getSpawnResourcesAuxValue(unsigned char)const
{
	return 0;
}

int EmeraldWoodBlock::getPlacementDataValue(Entity&, BlockPos const&, signed char side, Vec3 const&, int)const
{
	if (side == 2 || side == 3)
		return 1;
	else if (side == 4 || side == 5)
		return 2;
	return 0;
}

