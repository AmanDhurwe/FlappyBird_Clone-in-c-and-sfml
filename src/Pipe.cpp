#include "Pipe.h"

Pipe::Pipe(float x, float gapY) {
  topPipe.setSize(sf::Vector2f(50, gapY));
  topPipe.setFillColor(sf::Color::Green);
  topPipe.setPosition(x, 0);

  bottomPipe.setSize(sf::Vector2f(50, 600 - gapY - 150));
  bottomPipe.setFillColor(sf::Color::Green);
  bottomPipe.setPosition(x, gapY + 150);
}

void Pipe::update(float speedMultiplier) {
  float movementSpeed = -2.0f * speedMultiplier; // Spply speed multiplier
  topPipe.move(movementSpeed, 0);
  bottomPipe.move(movementSpeed, 0);
}

void Pipe::draw(sf::RenderWindow &window) {
  window.draw(topPipe);
  window.draw(bottomPipe);
}

bool Pipe::isOffScreen() const {
  return topPipe.getPosition().x + topPipe.getSize().x < 0;
}

sf::FloatRect Pipe::getTopBounds() const { return topPipe.getGlobalBounds(); }

sf::FloatRect Pipe::getBottomBounds() const {
  return bottomPipe.getGlobalBounds();
}
