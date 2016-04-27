#pragma once

#include "FillingContainer.h"
class Block;
class Entity;

struct Inventory : public FillingContainer {
    // virtual methods
    virtual ~Inventory();
    virtual int getContainerSize() const;
    virtual bool add(ItemInstance*);
    virtual bool canAdd(ItemInstance const*) const;
    virtual void dropAll(bool);
    virtual void clearSlot(int);
    virtual void load(ListTag const&);
    virtual void doDrop(ItemInstance*, bool);
    virtual int getEmptySlotsCount() const;
    virtual void setContainerSize(int);

    // non-virtual methods
    ItemInstance* getSelectedItem() const;
    void* selectSlot(int);
    bool moveToSelectedSlot(int);
    int getSelectedSlot() const;
    static int getSelectionSize();
    void setupDefault();
    void tick();
    Inventory(Player*);
    void clearInventoryWithDefault(bool);
    bool canDestroy(Block&);
    float getDestroySpeed(Block&);
    int getAttackDamage();
    int getLinkedSlotForItem(int);
    void moveToSelectionSlot(int, int);
    void moveToEmptySelectionSlot(int);
    bool removeItemInstance(ItemInstance const*);
    int getLinkedSlotForItemIdAndAux(int, int);
    int getLinkedSlotForExactItem(ItemInstance const&) const;
};
