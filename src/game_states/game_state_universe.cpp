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

#include "game_states/game_state_universe.h"

#include <nucleus/logging.h>
#include <SFML/Graphics/RenderTarget.hpp>

#include "ui/views/button.h"
#include "ui/views/linear_sizer_view.h"
#include "universe/universe_view.h"

GameStateUniverse::GameStateUniverse(const sf::Vector2f& viewportSize)
  : m_universe(std::make_unique<Universe>(viewportSize)) {
  // Add the user interface to the UI tree.
  createUserInterface(m_uiContext.get(), m_uiContext->getRoot());
}

GameStateUniverse::~GameStateUniverse() {
}

void GameStateUniverse::onButtonClicked(ui::Button* sender) {
  if (sender == m_testButton) {
    LOG(Info) << "Test button clicked";
  }
}

void GameStateUniverse::createUserInterface(ui::Context* context,
                                            ui::GroupView* parent) {
  // Add the universe view.
  auto universeView = std::make_unique<UniverseView>(context, m_universe.get());
  universeView->setName("universe");
  universeView->setExpand(ui::View::ExpandBoth);
  parent->addChild(universeView.release());

  // Create a container for all the buttons.
  ui::LinearSizerView* buttonContainer = new ui::LinearSizerView(
      context, ui::LinearSizerView::OrientationVertical);
  buttonContainer->setName("buttonContainer");
  buttonContainer->setExpand(ui::View::ExpandVertical);
  buttonContainer->setHorizontalAlign(ui::View::AlignLeft);

  // Create a test button.
  m_testButton = new ui::Button(context, "Test Button", this);
  m_testButton->setName("testButton");
  m_testButton->setMinSize(sf::Vector2i{300, 0});
  buttonContainer->addChild(m_testButton);

  m_createPowerGeneratorButton =
      new ui::Button(context, "Power Generator", this);
  m_createPowerGeneratorButton->setName("createPowerGenerator");
  m_createPowerGeneratorButton->setMinSize(sf::Vector2i{300, 0});
  buttonContainer->addChild(m_createPowerGeneratorButton);

  parent->addChild(buttonContainer);
}
