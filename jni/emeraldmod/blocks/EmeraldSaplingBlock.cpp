#include "EmeraldSaplingBlock.h"

EmeraldSaplingBlock::EmeraldSaplingBlock(short id) : Block("emeraldMushroom", id, Material::getMaterial(MaterialType::PLANT))
{
	mBlocks[id] = this;
	init();
	setSolid(false);
	setCategory(CreativeItemCategory::Decorations);
	setDestroyTime(1);
	setExplodeable(2);
	renderLayer = mSapling->renderLayer;
}

bool EmeraldSaplingBlock::mayPlaceOn(const Block &block) const
{
	return mSapling->mayPlaceOn(block);
}

AABB& EmeraldSaplingBlock::getCollisionShape(AABB &aabb, BlockSource &region, const BlockPos &pos, Entity *entity) const
{
	return mSapling->getCollisionShape(aabb, region, pos, entity);
}

void EmeraldSaplingBlock::onGraphicsModeChanged(bool, bool, bool)
{
	renderLayer = mSapling->renderLayer;
}

int EmeraldSaplingBlock::getRenderLayer(BlockSource &region, const BlockPos &pos) const
{
	return mSapling->getRenderLayer(region, pos);
}

int EmeraldSaplingBlock::getExtraRenderLayers() const
{
	return mSapling->getExtraRenderLayers();
}

