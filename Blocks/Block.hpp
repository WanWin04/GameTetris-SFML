#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <map>

#include "../Position/Position.hpp"
#include "../Colors/Colors.hpp"

class Block {
public:
    Block();
    void Draw(sf::RenderWindow& window);

    int ID;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<sf::Color> colors;
};

#endif