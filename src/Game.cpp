#include "Game.h"
#include <cmath>
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Flappy Bird"),
      bird(window.getSize().y, gameState) {
  window.setFramerateLimit(60);
  gameState = GameState::Start;
  score = 0;
  glowDirection = true;
  speedMultiplier = 1.0f;

  if (!font.loadFromFile("./VeniteAdoremusStraight-Yzo6v.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  // Score text
  scoreText.setFont(font);
  scoreText.setCharacterSize(40);
  scoreText.setFillColor(sf::Color::Red);
  scoreText.setPosition(10, 10);

  // Start screen text
  startText.setFont(font);
  startText.setCharacterSize(30);
  startText.setFillColor(sf::Color::Blue);
  startText.setString("PRESS SPACE TO START GAME");
  startText.setStyle(sf::Text::Bold);
  centerText(startText);
  startText.setPosition(startText.getPosition().x, 500);

  // Game over text
  gameOverText.setFont(font);
  gameOverText.setCharacterSize(70);
  gameOverText.setFillColor(sf::Color::White);
  gameOverText.setString("GAME OVER");
  gameOverText.setStyle(sf::Text::Bold);
  centerText(gameOverText, true, true);
  gameOverText.setPosition(gameOverText.getPosition().x, 150);

  // Play again text
  playAgainText.setFont(font);
  playAgainText.setCharacterSize(30);
  playAgainText.setFillColor(sf::Color::Blue);
  playAgainText.setString("PRESS SPACE TO PLAY AGAIN");
  playAgainText.setStyle(sf::Text::Bold);
  centerText(playAgainText);
  playAgainText.setPosition(playAgainText.getPosition().x, 500);
}

void Game::run() {
  while (window.isOpen()) {
    handleEvents();
    update();
    render();
  }
}

void Game::handleEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Space) {
        if (gameState == GameState::Start) {
          gameState = GameState::Playing;
        } else if (gameState == GameState::Playing) {
          bird.jump();
        } else if (gameState == GameState::End) {
          reset();
        }
      }
    }
  }
}

void Game::update() {
  if (gameState == GameState::Playing) {
    bird.update(speedMultiplier, window.getSize().y);

    // Update pipes
    for (auto &pipe : pipes) {
      pipe.update(speedMultiplier);
    }

    // Remove off-screen pipes
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(),
                               [](Pipe &pipe) { return pipe.isOffScreen(); }),
                pipes.end());

    // Spawn new pipes
    if (spawnTimer.getElapsedTime().asSeconds() > 2) {
      pipes.emplace_back(window.getSize().x, rand() % 300 + 100);
      spawnTimer.restart();
    }

    // Check for collisions
    for (auto &pipe : pipes) {
      if (bird.getBounds().intersects(pipe.getTopBounds()) ||
          bird.getBounds().intersects(pipe.getBottomBounds())) {
        gameState = GameState::End;
      }
    }

    // Update score
    score += 1;
    scoreText.setString("Score: " + std::to_string(score / 10));

    // Increase speed multiplier over time
    speedMultiplier =
        1.0f + (score / 1000.0f); // Increase speed by 1% every 10 points
  }
}

void Game::render() {
  window.clear();

  // Draw background (paused game state)
  bird.draw(window);
  for (auto &pipe : pipes) {
    pipe.draw(window);
  }

  // Draw screens based on game state
  switch (gameState) {
  case GameState::Start:
    drawStartScreen();
    break;
  case GameState::Playing:
    window.draw(scoreText);
    break;
  case GameState::End:
    drawEndScreen();
    break;
  }

  window.display();
}

void Game::drawStartScreen() {
  // Glowing effect for start text
  float glowValue =
      128 + 127 * std::sin(glowClock.getElapsedTime().asSeconds() * 2);
  startText.setFillColor(
      sf::Color(255, 255, 255, static_cast<sf::Uint8>(glowValue)));
  window.draw(startText);
}

void Game::drawEndScreen() {
  // Glowing effect for game over text
  float glowValue =
      128 + 127 * std::sin(glowClock.getElapsedTime().asSeconds() * 2);
  gameOverText.setFillColor(
      sf::Color(255, 255, 255, static_cast<sf::Uint8>(glowValue)));
  window.draw(gameOverText);

  // Draw score text
  scoreText.setPosition(
      window.getSize().x / 2.0f - scoreText.getLocalBounds().width / 2, 300);
  window.draw(scoreText);

  // Draw play again text
  playAgainText.setFillColor(
      sf::Color(255, 255, 255, static_cast<sf::Uint8>(glowValue)));
  window.draw(playAgainText);

  // reset the game state when the player preses space
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    reset(); // reset the game
  }
}

void Game::reset() {
  gameState = GameState::Playing;
  bird.reset(window.getSize().y); // Reset the bird's state
  pipes.clear();
  score = 0;
  scoreText.setString("Score: 0"); // update score text
  scoreText.setPosition(10, 10);   // reset score text position
}

void Game::centerText(sf::Text &text, bool centerHorizontally,
                      bool centerVertically) {
  sf::FloatRect textBounds = text.getLocalBounds();

  if (centerHorizontally) {
    text.setOrigin(textBounds.left + textBounds.width / 2.0f,
                   text.getOrigin().y);
    text.setPosition(window.getSize().x / 2.0f, text.getPosition().y);
  }

  if (centerVertically) {
    text.setOrigin(text.getOrigin().x,
                   textBounds.top + textBounds.height / 2.0f);
    text.setPosition(text.getPosition().x, window.getSize().y / 2.0f);
  }
}
