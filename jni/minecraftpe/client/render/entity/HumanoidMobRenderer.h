#pragma once

#include <vector>

#include "MobRenderer.h"
#include "minecraftpe/client/render/TexturePtr.h"

class HumanoidModel;

class HumanoidMobRenderer : public MobRenderer
{
public:
	char filler[652]; // 4
	std::vector<mce::TexturePtr> armorTextures; // 656

	HumanoidMobRenderer(EntityRenderDispatcher&, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, mce::TexturePtr, float);
	HumanoidMobRenderer(EntityRenderDispatcher&, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, std::unique_ptr<HumanoidModel, std::default_delete<HumanoidModel>>, mce::TexturePtr, float);

	virtual ~HumanoidMobRenderer();
	virtual void render(Entity&, const Vec3&, float, float);
	virtual void prepareArmor(Mob&, ArmorSlot, float);
	virtual void prepareCarriedItem(Model&, Mob&, const ItemInstance&);
	virtual void setupRotations(const Entity&, float, float, Matrix&, float) const;
	virtual void additionalRendering(Model&, Mob&, float, float, float, float, float, float, float);
	virtual void prepareCarriedOffhandItem(Model&, Mob&, ItemInstance*);

	static void initTextures();
};
