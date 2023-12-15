#include "Application.hpp"

Application::Application(int width, int height, std::string title) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    if (_background.loadFromFile("resource/Image/sky.png")) {
        sf::Sprite backgroundSprite(_background);

        // Set background full screen
        backgroundSprite.setScale(static_cast<float>(SCREEN_WIDTH) / _background.getSize().x, static_cast<float>(SCREEN_HEIGHT) / _background.getSize().y);

        GameState gameState(window);

        // Draw rectangle for next block
        SetNextBlock();

        while (window.isOpen())
        {
            HandleInput(gameState);
            HandleEvents(window, gameState);

            if (EventActivation(TIME_DOWN)) {
                gameState.MoveDown();
            }

            _updateScore.Update(gameState.score);

            window.draw(backgroundSprite);

            window.draw(_score);
            window.draw(_next);
            window.draw(_rect);

            gameState.Draw(window);

            window.draw(_updateScore);

            window.draw(_control);

            if (gameState.gameOver) {
                UpdateAndDrawGameOver(window, gameState);
                window.draw(_medal);            
            }

            window.display();
        }
    }
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

void Application::SetNextBlock() {
    _rect.setSize(sf::Vector2f(WIDTH_RECT_SIZE, HEIGHT_RECT_SIZE));
    _rect.setFillColor(sf::Color::White);
    _rect.setPosition(sf::Vector2f(WIDTH_RECT, HEIGHT_RECT));

    _rect.setOutlineColor(orangeColor);
    _rect.setOutlineThickness(RECT_THICKNESS);
}

void Application::HandleInput(GameState& gameState) {
    gameState.HandleInput();
}

void Application::UpdateAndDrawGameOver(sf::RenderWindow& window, GameState& gameState) {
    window.draw(_gameOver);
    window.draw(_playAgain);
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