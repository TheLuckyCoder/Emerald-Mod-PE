#include "AppleItem.h"

#include "minecraftpe/world/item/FoodItemComponent.h"

AppleItem::AppleItem(const std::string &name, short id) : Item(name, id)
{
    setCategory(CreativeItemCategory::ITEMS);
	setUseAnimation(UseAnimation::EAT);
	setMaxUseDuration(32);
	foodComponent = std::unique_ptr<FoodItemComponent>(new FoodItemComponent(*this));
	foodComponent->nutrition = 20;
	foodComponent->saturationModifier = 4.0f;
	foodComponent->isMeat = false;
}
