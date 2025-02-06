#include "Bird.h"

Bird::Bird(float windowHeight, GameState &gameState)
    : windowHeight(windowHeight), gameState(gameState) {
  shape.setSize(sf::Vector2f(50, 50));
  shape.setFillColor(sf::Color::Yellow);
  shape.setPosition(100, windowHeight / 2 - 25); // Center bird vertically
  velocity = 0;
}

void Bird::update(float speedMultiplier, float windowHeight) {
  velocity += 0.5f * speedMultiplier; // Apply gravity
  shape.move(0, velocity);

  // Prevent bird from going above the window
  float birdTop = shape.getPosition().y;
  float birdBottom = birdTop + shape.getSize().y;
  float windowTop = 0;
  float windowBottom = windowHeight;

  // Check top boundary
  if (birdTop < windowTop) {
    shape.setPosition(shape.getPosition().x, windowTop);
    velocity = 0; // Stop upward movement
  }

  // Check bottom boundary (kill the bird)
  if (birdBottom > windowBottom) {
    gameState = GameState::End; // Trigger game over
  }
}

void Bird::jump() {
  velocity = -10; // Make the bird jump
}

void Bird::reset(float windowHeight) {
  shape.setPosition(100,
                    windowHeight / 2.0f - 25.0f); // Reset position to center
  velocity = 0;                                   // reset velocity;
}
void Bird::draw(sf::RenderWindow &window) { window.draw(shape); }

sf::FloatRect Bird::getBounds() const { return shape.getGlobalBounds(); }

void Bird::setPosition(float x, float y) { shape.setPosition(x, y); }

sf::Vector2f Bird::getPosition() const { return shape.getPosition(); }

sf::Vector2f Bird::getSize() const { return shape.getSize(); }
