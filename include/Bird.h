#ifndef BIRD_H
#define BIRD_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Bird {
public:
  Bird(float windowHeight, GameState &gameState);
  void update(float speedMultiplier, float windowHeight);
  void jump();
  void draw(sf::RenderWindow &window);
  sf::FloatRect getBounds() const;
  void setPosition(float x, float y);
  sf::Vector2f getPosition() const;
  sf::Vector2f getSize() const;
  void reset(float windowHeight); // Add reset method

private:
  sf::RectangleShape shape;
  float velocity;
  float windowHeight;
  GameState &gameState;
};

#endif
