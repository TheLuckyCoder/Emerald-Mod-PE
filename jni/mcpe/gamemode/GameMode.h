#pragma once

#include <functional>

class InputMode;
class Player;
class BlockPos;
class ItemInstance;
class Entity;
class PacketSender;
class Level;
class Vec3;
class SoundPlayer;
class Vibration;

struct GameMode {
    // virtual methods
    virtual ~GameMode();
    virtual void* startDestroyBlock(Player&, BlockPos, signed char);
    virtual void* destroyBlock(Player&, BlockPos, signed char);
    virtual void* continueDestroyBlock(Player&, BlockPos, signed char);
    virtual void* stopDestroyBlock(Player&);
    virtual void* startBuildBlock(Player&, BlockPos, signed char);
    virtual void* buildBlock(Player&, BlockPos, signed char);
    virtual void* continueBuildBlock(Player&, BlockPos, signed char);
    virtual void* stopBuildBlock(Player&);
    virtual void* tick();
    virtual void* getPickRange(Player*, InputMode const&);
    virtual void* useItem(Player&, ItemInstance&);
    virtual void* useItemOn(Player&, ItemInstance*, BlockPos const&, signed char, Vec3 const&);
    virtual void* interact(Player&, Entity&);
    virtual void* attack(Player&, Entity&);
    virtual void* releaseUsingItem(Player&);
    virtual void* setTrialMode(bool);
    virtual void* isInTrialMode();
    virtual void* registerUpsellScreenCallback(std::function<void (bool)>);

    // non-virtual methods
    GameMode(PacketSender&, Level&, SoundPlayer&, Vibration&);
    void* _creativeDestroyBlock(Player&, BlockPos, signed char);
    void* getDestroyProgress();
    void* getOldDestroyProgress();
    void* _releaseUsingItemInternal(Player&);
    void* getHitProgress(float);
    void* toggleLongPickRange();
    void* _destroyBlockInternal(Player&, BlockPos, signed char);
};
