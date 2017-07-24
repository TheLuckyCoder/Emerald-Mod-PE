#include "EmeraldMushroomBlock.h"

EmeraldMushroomBlock::EmeraldMushroomBlock(short id) : Block("emeraldMushroom", id, Material::getMaterial(MaterialType::PLANT))
{
	mBlocks[id] = this;
	init();
	setSolid(false);
	setCategory(CreativeItemCategory::DECORATIONS);
	setDestroyTime(1);
	setExplodeable(2);
	renderLayer = mSapling->renderLayer;
}

bool EmeraldMushroomBlock::mayPlaceOn(const Block &block) const
{
	return mSapling->mayPlaceOn(block);
}

const AABB& EmeraldMushroomBlock::getCollisionShape(AABB &aabb, BlockSource &region, const BlockPos &pos, Entity *entity) const
{
	return mSapling->getCollisionShape(aabb, region, pos, entity);
}

void EmeraldMushroomBlock::onGraphicsModeChanged(bool, bool, bool)
{
	renderLayer = mSapling->renderLayer;
}

int EmeraldMushroomBlock::getRenderLayer(BlockSource &region, const BlockPos &pos) const
{
	return mSapling->getRenderLayer(region, pos);
}

int EmeraldMushroomBlock::getExtraRenderLayers() const
{
	return mSapling->getExtraRenderLayers();
}

