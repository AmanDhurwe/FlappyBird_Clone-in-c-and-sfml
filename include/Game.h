#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"
#include "Pipe.h"
#include "GameState.h" // Include GameState

class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update();
    void render();
    void reset();
    void drawStartScreen();
    void drawEndScreen();
    void centerText(sf::Text& text, bool centerHorizontally = true, bool centerVertically = true);

    sf::RenderWindow window;
    GameState gameState;
    Bird bird;
    std::vector<Pipe> pipes;
    sf::Clock spawnTimer;
    int score;
    sf::Font font;
    sf::Text scoreText;
    sf::Text startText;
    sf::Text gameOverText;
    sf::Text playAgainText;
    sf::Clock glowClock;
    bool glowDirection;
    float speedMultiplier;
};

#endif
