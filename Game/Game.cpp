#include "Game.hpp"

double keyUpdateTime = 0;

Game::Game(int width, int height, std::string title) : _lightGreen(28, 177, 138, 1) {
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    window.setFramerateLimit(FRAME_LIMIT);

    ScoreInterface score;
    NextInterface next;

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

        if (EventActivation(TIME_DOWN)) {
            game.MoveDown();
        }

        window.clear(_lightGreen);
        game.Draw(window);
        window.draw(score);
        window.draw(next);
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