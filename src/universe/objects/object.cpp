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

#include "universe/objects/object.h"

#include <cmath>

Object::Object(Universe* universe) : m_universe(universe) {
}

Object::~Object() {
}

void Object::moveTo(const sf::Vector2f& pos) {
  m_pos = pos;
}

sf::FloatRect Object::getBounds() const {
  return sf::FloatRect{};
}

float Object::calculateDistanceFrom(const sf::Vector2f& pos) const {
  const float x = (pos.x - m_pos.x) * (pos.x - m_pos.x);
  const float y = (pos.y - m_pos.y) * (pos.y - m_pos.y);
  return std::sqrtf(x + y);
}
