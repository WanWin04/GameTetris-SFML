#include <SFML/Graphics.hpp>

#include "./Grid/Grid.hpp"
#include "./Blocks/Blocks.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 1600), "GAME TETRIS");
    window.setFramerateLimit(60);

    sf::Color darkBlue(44, 44, 127, 255);

    Grid grid;
    LBlock lblock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(darkBlue);
        grid.Draw(window);
        lblock.Draw(window);
        window.display();
    }

    return 0;
}