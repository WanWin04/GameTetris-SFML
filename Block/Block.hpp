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
    void FallBlock(int rows, int columns);
    std::vector<Position> getPositions();

    int ID;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    int rowShelf;
    int columnShelf;
    std::vector<sf::Color> colors;
};

#endif