#include "EmeraldAppleItem.h"

EmeraldAppleItem::EmeraldAppleItem(short itemId) : Item("emeraldApple", itemId)
{
	creativeCategory = CreativeItemCategory::ITEMS;
	setIcon("emerald_apple", 0);
	setStackedByData(true);
	useAnimation = UseAnimation::Eat;
	useDuration = 32;
}

/*void EmeraldAppleItem::init(Json::Value &json) {
	"food": {
		"nutrition": 8,
		"saturation_modifier": "supernatural",
		"is_meat": false,
		"effects": [{
			"name": "regeneration",
			"chance": 1.0,
			"duration": 150,
			"amplifier": 5
		},
		{
			"name": "absorption",
			"chance": 1.0,
			"duration": 150,
			"amplifier": 2
		},
		{
			"name": "resistance",
			"chance": 1.0,
			"duration": 150,
			"amplifier": 2
		}]
	}
}*/

bool EmeraldAppleItem::isFoil(const ItemInstance *item) const {
	return true;
}
