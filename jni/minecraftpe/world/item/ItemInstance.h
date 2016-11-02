#pragma once

#include <memory>
#include "../../UseAnimation.h"

class CompoundTag;
class Item;
class Block;
class ItemEnchants;
class Mob;
class Player;
class Level;

class ItemInstance {
public:
    unsigned char count;
    unsigned short aux;
    CompoundTag* userData;
    bool valid;
    Item* item;
    Block* block;

    ItemInstance(Block const*);
    ItemInstance(Block const*,int);
    ItemInstance(Block const*,int,int);
    ItemInstance(Item const*);
    ItemInstance(Item const*,int);
    ItemInstance(Item const*,int,int);
    ItemInstance(Item const*,int,int,CompoundTag const*);
    ItemInstance(ItemInstance const&);
    ItemInstance(bool);
    ItemInstance(int,int,int);
    ItemInstance(int,int,int,CompoundTag const*);
    ItemInstance();

    void _getHoverFormattingPrefix();
    void _setItem(int);
    void add(int);
    bool canDestroySpecial(Block *);
    int getAttackDamage();
    int getAuxValue() const;
    int getBaseRepairCost();
    std::string getCustomName()const;
    int getDamageValue() const;
    float getDestroySpeed(Block *);
    std::string getEffectName()const;
    int getEnchantSlot();
    int getEnchantValue();
    void getEnchantsFromUserData();
    void getFormattedHovertext();
    std::string getHoverName()const;
    void getIcon(int,bool);
    int getId() const;
    int getIdAux();
    void getIdAuxEnchanted();
    int getMaxDamage()const;
    int getMaxStackSize() const;
    int getMaxUseDuration();
    void getName();
    void getNetworkUserData();
    UseAnimation getUseAnimation()const;
    void getUserData();
    bool hasCustomHoverName();
    bool hasSameUserData(ItemInstance const&);
    bool hasUserData();
    void hurtAndBreak(int,Mob *);
    void hurtEnemy(Mob *,Mob *);
    void init(int,int,int);
    void interactEnemy(Mob *,Player *);
    bool isArmorItem(ItemInstance const*);
    bool isDamageableItem();
    bool isDamaged()const;
    bool isEnchanted();
    bool isEnchantingBook();
    bool isFoil();
    bool isFullStack();
    bool isItem(ItemInstance const*);
    bool isLiquidClipItem();
    bool isNull();
    bool isStackable(ItemInstance const*,ItemInstance const*);
    bool isStackable();
    bool isStackedByData();
    bool isThrowable();
    void load(CompoundTag const&);
    void matches(ItemInstance const*);
    void matches(ItemInstance const*,ItemInstance const*);
    void matchesNulls(ItemInstance const*,ItemInstance const*);
    void operator!=(ItemInstance const&);
    void operator=(ItemInstance const&);
    void operator==(ItemInstance const&);
    void releaseUsing(Player *,int);
    void remove(int);
    void resetHoverName();
    bool sameItemAndAux(ItemInstance const*) const;
    CompoundTag* save();
    void saveEnchantsToUserData(ItemEnchants const&);
    void set(int);
    void setAuxValue(short);
    void setCustomName(std::string const&);
    void setDescriptionId(std::string const&);
    void setNull();
    void setRepairCost(int);
    void setUserData(std::unique_ptr<CompoundTag>);
    void snap(Player*);
    void toString();
    void use(Player &);
    void useAsFuel();
    void useOn(Player *,int,int,int,signed char,float,float,float);
    void useTimeDepleted(Level *,Player *);
	void onCraftedBy(Level&,Player&);

    static ItemInstance* clone(ItemInstance const*);
    static ItemInstance* cloneSafe(ItemInstance const*);
    static ItemInstance* fromTag(CompoundTag const&);
};
