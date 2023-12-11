#include "Game.hpp"

double keyUpdateTime = 0;

Game::Game(int width, int height, std::string title) : _darkBlue(44, 44, 127, 255) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    GameState game(window);

    while (window.isOpen())
    {
        game.HandleInput();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (EventActivation(0.5)) {
            game.MoveDown();
        }

        window.clear(_darkBlue);
        game.Draw(window);
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