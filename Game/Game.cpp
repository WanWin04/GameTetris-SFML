#include "Game.hpp"

#include <iostream>

double keyUpdateTime = 0;

Game::Game(int width, int height, std::string title) : _lightGreen(28, 177, 138, 1) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    GameState gameState(window);

    while (window.isOpen())
    {
        gameState.HandleInput();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (EventActivation(TIME_DOWN)) {
            gameState.MoveDown();
        }

        window.clear(_lightGreen);
        gameState.Draw(window);
        window.draw(_score);
        window.draw(_next);

        if (gameState.gameOver) {
            window.draw(_gameOver);
        }

        window.display();
    }
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