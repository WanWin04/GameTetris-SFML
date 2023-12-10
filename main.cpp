#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1300), "GAME TETRIS");
    window.setFramerateLimit(60);

    sf::Color darkBlue(44, 44, 127, 255);

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
        window.display();
    }

    return 0;
}