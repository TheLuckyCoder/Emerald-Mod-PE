#pragma once

class Entity;
struct BlockPos;
class FullBlock;

class ItemUseCallback
{
public:
	virtual ~ItemUseCallback();
	virtual void onPlacingBlock(const BlockPos&, const FullBlock&, const FullBlock&) = 0;
	virtual void onBlockPlaced(const BlockPos&, const FullBlock&, const FullBlock&) = 0;
	virtual void onModifyingBlock(const BlockPos&, const FullBlock&, const FullBlock&) = 0;
	virtual void onBlockModified(const BlockPos&, const FullBlock&, const FullBlock&) = 0;
	virtual void onSpawningEntity(const Entity&) = 0;
	virtual void onEntitySpawned(const Entity&) = 0;
	virtual void onModifyingEntity(const Entity&) = 0;
	virtual void onEntityModified(const Entity&) = 0;
	virtual void onRemovingEntity(const Entity&) = 0;
	virtual void onEntityRemoved(const Entity&) = 0;
};
