#include <SFML/Graphics.hpp>

#include "./GameState/GameState.hpp"

double keyUpdateTime = 0;

bool EventActivation(double period) {
    static sf::Clock clock;

    double currentTime = clock.getElapsedTime().asSeconds();

    if (currentTime - keyUpdateTime >= period) {
        keyUpdateTime = currentTime;

        return true;
    }
    return false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 1250), "GAME TETRIS");
    window.setFramerateLimit(60);

    sf::Color darkBlue(44, 44, 127, 255);

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

        window.clear(darkBlue);
        game.Draw(window);
        window.display();
    }

    return 0;
}