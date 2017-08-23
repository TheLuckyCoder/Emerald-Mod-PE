#pragma once

#include "ItemUseCallback.h"

class ApiItemUseCallback : ItemUseCallback
{
public: 
	virtual ~ApiItemUseCallback();
	virtual void onPlacingBlock(const BlockPos&, const FullBlock&, const FullBlock&);
	virtual void onBlockPlaced(const BlockPos&, const FullBlock&, const FullBlock&);
	virtual void onModifyingBlock(const BlockPos&, const FullBlock&, const FullBlock&);
	virtual void onBlockModified(const BlockPos&, const FullBlock&, const FullBlock&);
	virtual void onSpawningEntity(const Entity&);
	virtual void onEntitySpawned(const Entity&);
	virtual void onModifyingEntity(const Entity&);
	virtual void onEntityModified(const Entity&);
	virtual void onRemovingEntity(const Entity&);
	virtual void onEntityRemoved(const Entity&);
};
