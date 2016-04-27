#pragma once

#include <string>
#include <vector>

class MinecraftClient;
class Config;
class Tessellator;
class RectangleArea;
class ItemInstance;
class MobEffectsLayout;
class Font;
enum class InputMode;

struct Gui {
  // virtual methods
  virtual ~Gui();
  virtual void onAppSuspended();
  virtual void onConfigChanged(Config const&);

  // non-virtual methods
  void renderHearts();
  void displayLocalizableMessage(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
  void displayChatMessage(std::string const&, std::string const&);
  void displayClientMessage(std::string const&);
  void displaySystemMessage(std::string const&);
  void postError(int);
  void addMessage(std::string const&, std::string const&, int, bool);
  void renderVignette(float, int, int);
  void _buildOuterFeedbackCircle(int, float, float);
  void _buildInnerFeedbackCircle(int, float);
  void drawRectangleArea(Tessellator&, RectangleArea const*, int, int, float);
  void drawRectangleArea(Tessellator&, RectangleArea const*, int, int, float, float);
  void _buildFeedbackCircle();
  void renderBubbles();
  void renderSleepAnimation(int, int);
  void onLevelGenerated();
  void renderOnSelectItemNameText(int, Font*, int);
  void renderSlotText(ItemInstance const*, float, float, bool, bool, bool);
  void tickItemDrop();
  void cubeSmoothStep(float, float, float);
  void renderExperience();
  Gui(MinecraftClient&);
  void setNowPlaying(std::string const&);
  void showTipMessage(std::string const&);
  void renderSlot(int, int, int, float);
  void inventoryUpdated();
  void _updateHudPositions();
  void itemCountItoa(char*, int);
  void floorAlignToScreenPixel(float);
  void onMobEffectsChanged(MobEffectsLayout const&);
  int getNumSlots() const;
  void getSlotIdAt(int, int) const;
  void isInside(int, int);
  void getSlotPos(int, int&, int&);
  void flashSlot(int);
  void handleClick();
  void updatePointerLocation(short, short);
  void clearMessages();
  void setShowProgress(bool);
  void setTouchToolbarArea(RectangleArea const&);
  void wasToolbarClicked() const;
  void toggleMuteChat();
  void forceMuteChat();
  void renderChatMessages(int, int, unsigned int, bool, Font*);
  void tick();
  void showPopupNotice(std::string const&, std::string const&);
  void render(float, bool, int, int);
  void renderHunger();
  void renderProgressIndicator(InputMode, int, int, float);
  void renderPortalOverlay(float, int, int);
  void renderToolBar(float, float, bool);

  // static variables
  static float GuiScale;
  static float BUTTONS_TRANSPARENCY;
  static float DropTicks;
  static float InvGuiScale;
};
