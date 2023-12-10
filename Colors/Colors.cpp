#include "Colors.hpp"

const sf::Color darkGrey(26, 31, 40, 255);
const sf::Color green(47, 230, 23, 255);
const sf::Color red(255, 0, 0, 255);
const sf::Color orange(226, 116, 17, 255);
const sf::Color yellow(237, 234, 4, 255);
const sf::Color purple(166, 0, 247, 255);
const sf::Color cyan(21, 204, 209, 255);
const sf::Color blue(13, 64, 216, 255);

std::vector<sf::Color> getColors() {
    return { darkGrey, green, red, orange, yellow, purple, cyan, blue} ;
}