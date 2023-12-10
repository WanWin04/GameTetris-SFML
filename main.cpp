#include <SFML/Graphics.hpp>

#include "./GameState/GameState.hpp"

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

        window.clear(darkBlue);
        game.Draw(window);
        window.display();
    }

    return 0;
}