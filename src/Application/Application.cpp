#include "Application.hpp"

#include <iostream>

double keyUpdateTime = 0;

Application::Application(int width, int height, std::string title) : _lightGreen(28, 177, 138, 1) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    if (_background.loadFromFile("resource/Image/sky.png")) {
        sf::Sprite backgroundSprite(_background);

        backgroundSprite.setScale(static_cast<float>(SCREEN_WIDTH) / _background.getSize().x, static_cast<float>(SCREEN_HEIGHT) / _background.getSize().y);

        GameState gameState(window);

        _playMusic.play();

        while (window.isOpen())
        {
            HandleInput(gameState);
            HandleEvents(window, gameState);

            if (EventActivation(TIME_DOWN)) {
                gameState.MoveDown();
            }

            _updateScore.Update(gameState.score);

            // window.clear(_lightGreen);
            window.draw(backgroundSprite);
            gameState.Draw(window);

            window.draw(_score);
            window.draw(_next);

            window.draw(_updateScore);

            window.draw(_control);

            if (gameState.gameOver) {
                UpdateAndDrawGameOver(window, gameState);
                _playMusic.stop();
            }

            window.display();
        }
    }
}

Application::~Application() {
    _playMusic.stop();
}

void Application::HandleEvents(sf::RenderWindow& window, GameState& gameState) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Application::HandleInput(GameState& gameState) {
    gameState.HandleInput();
}

void Application::UpdateAndDrawGameOver(sf::RenderWindow& window, GameState& gameState) {
    window.draw(_gameOver);
}

bool Application::EventActivation(double period) {
    static sf::Clock clock;
    _currentTime = clock.getElapsedTime().asSeconds();

    if ((_currentTime - keyUpdateTime) >= period) {
        keyUpdateTime = _currentTime;

        return true;
    }
    return false;
}