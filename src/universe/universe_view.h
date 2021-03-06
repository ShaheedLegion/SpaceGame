// Copyright (c) 2015, Tiaan Louw
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef UNIVERSE_UNIVERSE_VIEW_H_
#define UNIVERSE_UNIVERSE_VIEW_H_

#include <memory>

#include <elastic/views/color_view.h>
#include <nucleus/config.h>

#include "universe/camera.h"
#include "universe/hud.h"

#if BUILD(DEBUG)
#define SHOW_UNIVERSE_MOUSE_POS 1
#endif

class Universe;
class Object;
class Link;

class UniverseView : public el::View {
public:
  explicit UniverseView(el::Context* context, Universe* universe = nullptr);
  virtual ~UniverseView() override;

  // Return the universe we are observing.
  Universe* getUniverse() const { return m_universe; }

  // Return the camera we use in this view.
  const Camera& getCamera() const { return m_camera; }

  // Start placing the given object.
  void startPlacingObject(std::unique_ptr<Object> object);

  // Stop placing an object (if we have one).  place specifies whether the
  // existing ghost object should be inserted into the universe or not.
  void stopPlacingObject(bool place);

  // Override: ui::View
  bool handlesInput() const { return true; }
  bool onMousePressed(sf::Event& event) override;
  bool onMouseDragged(sf::Event& event) override;
  void onMouseMoved(sf::Event& event) override;
  void onMouseReleased(sf::Event& event) override;
  void onMouseWheel(sf::Event& event) override;
  void onKeyPressed(sf::Event& event) override;
  void onKeyReleased(sf::Event& event) override;
  void tick(float adjustment) override;
  void layout(const sf::IntRect& rect) override;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
  enum class MouseHandler {
    None,
    Camera,
    Hud,
    Object,
  };

  // Make the needed changes to the view if the perceived mouse position
  // changed.
  void updateGhostPosition(const sf::Vector2f& universeMousePos);

  // Place an enemy ship at the given universe location.
  void placeEnemyShip(const sf::Vector2f& pos);

  // The universe we are looking at.
  Universe* m_universe;

  // The camera we use to look into the universe.
  Camera m_camera;

  // The HUD we render over the view.
  Hud m_hud;

  // Keep track of who has the mouse control after an onMousePressed event.
  MouseHandler m_mouseHandler{MouseHandler::None};

  // The position in view coordinates where we started to drag.
  sf::Vector2i m_mouseStartDragPos;

  // The object that we pressed the mouse on.
  Object* m_mousePressedObject{nullptr};

  // Whether moving the camera has moved past the threshold.
  bool m_cameraMovedPastThreshold{false};

  // The last postition where the mouse cursor was in view coordinates.
  sf::Vector2i m_viewMousePos;

  // The current ghost object.  We own this pointer as it's not part of the
  // universe yet.
  std::unique_ptr<Object> m_ghostObject;

#if SHOW_UNIVERSE_MOUSE_POS
  // A shape to show where the current mouse position is in the universe.
  sf::CircleShape m_mousePosShape;
#endif

  DISALLOW_IMPLICIT_CONSTRUCTORS(UniverseView);
};

#endif  // UNIVERSE_UNIVERSE_VIEW_H_
