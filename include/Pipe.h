#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

class Pipe {
public:
  Pipe(float x, float gapY);
  void update(float speedMultiplier = 1.0f);
  void draw(sf::RenderWindow &window);
  bool isOffScreen() const;
  sf::FloatRect getTopBounds() const;
  sf::FloatRect getBottomBounds() const;

private:
  sf::RectangleShape topPipe;
  sf::RectangleShape bottomPipe;
};

#endif
