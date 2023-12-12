#include "Game.hpp"

#include <iostream>

double keyUpdateTime = 0;

Game::Game(int width, int height, std::string title) : _lightGreen(28, 177, 138, 1) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    GameState gameState(window);

    while (window.isOpen())
    {
        HandleInput(gameState);
        HandleEvents(window, gameState);

        if (EventActivation(TIME_DOWN)) {
            gameState.MoveDown();
        }

        window.clear(_lightGreen);
        gameState.Draw(window);

        window.draw(_score);
        window.draw(_next);

        if (gameState.gameOver) {
            UpdateAndDrawGameOver(window, gameState);
        }

        window.display();
    }
}

void Game::HandleEvents(sf::RenderWindow& window, GameState& gameState) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::HandleInput(GameState& gameState) {
    gameState.HandleInput();
}

void Game::UpdateAndDrawGameOver(sf::RenderWindow& window, GameState& gameState) {
    window.draw(_gameOver);
}

bool Game::EventActivation(double period) {
    static sf::Clock clock;
    currentTime = clock.getElapsedTime().asSeconds();

    if ((currentTime - keyUpdateTime) >= period) {
        keyUpdateTime = currentTime;

        return true;
    }
    return false;
}