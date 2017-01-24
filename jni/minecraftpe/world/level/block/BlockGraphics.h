#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Block.h"
#include "BlockShape.h"
#include "BlockSoundType.h"

class TextureAtlas;
class TextureAtlasTextureItem;
namespace Json { class Value; }

class BlockGraphics 
{
public:
	void**vtable;
	char filler[500];

	static std::shared_ptr<TextureAtlas> mTerrainTextureAtlas;
	static std::vector<std::unique_ptr<BlockGraphics>> mOwnedBlocks;
	static BlockGraphics* mBlocks[256];

	BlockGraphics(const std::string&);

	virtual ~BlockGraphics();

	bool shouldRenderFace(BlockSource&, const BlockPos&, signed char, const AABB&) const;
	int getIconYOffset() const;
	int getColor(int) const;
	int getColor(BlockSource&, const BlockPos&) const;
	int getColorForParticle(BlockSource&, const BlockPos&, int) const;
	bool isSeasonTinted(BlockSource&, const BlockPos&) const;
	void prepareRender(BlockSource&, const BlockPos&);
	void onGraphicsModeChanged(bool, bool);
	int getRenderLayer(BlockSource&, const BlockPos&) const;
	int getExtraRenderLayers();
	const AABB& getVisualShape(BlockSource&, const BlockPos&, AABB&, bool);
	const AABB& getVisualShape(unsigned char, AABB&, bool);
	const TextureUVCoordinateSet& getCarriedTexture(signed char, int) const;
	bool animateTick(BlockSource&, const BlockPos&, Random&);
	void randomlyModifyPosition(const BlockPos&, int&) const;
	void randomlyModifyPosition(const BlockPos&) const;
	void setVisualShape(const AABB&);
	void setVisualShape(const Vec3&, const Vec3&);
	void setSoundType(BlockSoundType);
	Block& getBlock() const;
	BlockShape getBlockShape() const;
	void getFaceTextureIsotropic();
	Color getMapColor(const FullBlock) const;
	Color getMapColor() const;
	int getRenderLayer() const;
	BlockSoundType getSoundType();
	const TextureUVCoordinateSet& getTexture(signed char) const;
	const TextureUVCoordinateSet& getTexture(signed char, int) const;
	bool isAlphaTested();
	bool isFullAndOpaque(const Block&);
	bool isFullAndOpaque();
	void lookupByName(const std::string&, bool);
	void reloadBlockUVs(TextureAtlas&);
	void setAllFacesIsotropic();
	void setBlockShape(BlockGraphics&, const Json::Value&);
	void setBlockShape(BlockShape);
	void setCarriedTextureItem(const std::string&);
	void setCarriedTextureItem(const std::string&, const std::string&, const std::string&);
	void setCarriedTextures(BlockGraphics&, const Json::Value&);
	void setMapColor(const Color&);
	void setTextureAtlas(std::shared_ptr<TextureAtlas>);
	void setTextureIsotropic(BlockGraphics&, const Json::Value&);
	void setTextureIsotropic(unsigned int);
	void setTextureItem(const std::string&);
	void setTextureItem(const std::string&, const std::string&, const std::string&);
	void setTextureItem(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
	void setTextures(BlockGraphics&, const Json::Value&);

	static void initBlocks();
	static void teardownBlocks();
	static TextureUVCoordinateSet getTextureUVCoordinateSet(const std::string&, int);
	static TextureAtlasTextureItem getTextureItem(const std::string&);
};
