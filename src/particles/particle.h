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

#ifndef PARTICLES_PARTICLE_H_
#define PARTICLES_PARTICLE_H_

#include <nucleus/macros.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>

class ParticleEmitter;

class Particle : public sf::Drawable {
public:
  Particle(ParticleEmitter* emitter, const sf::Vector2f& pos);
  ~Particle();

  // Get/set position.
  const sf::Vector2f& getPos() const { return m_pos; }
  void setPos(const sf::Vector2f& pos);

  // Returns true if the particle is dead and should be removed.
  bool isDead() const { return m_life <= 0; }

  // Tick the particle.
  virtual void tick(float adjustment);

  // Override: sf::Drawable
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
  // The emitter that created us.
  ParticleEmitter* m_emitter;

  // Our position.
  sf::Vector2f m_pos;

  // The lifetime of the particle.
  float m_lifeTime{100.f};

  // The current life of the particle.
  float m_life{m_lifeTime};

  // The shape we use to render the particle.
  sf::CircleShape m_shape;

  DISALLOW_IMPLICIT_CONSTRUCTORS(Particle);
};

#endif  // PARTICLES_PARTICLE_H_
