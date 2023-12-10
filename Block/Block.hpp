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
    void RotateBlock();
    void LimitRotation();
    std::vector<Position> getPositions();

    int getRowOffset() const;
    int getColumnOffset() const;

    int ID;
    std::map<int, std::vector<Position>> cells;

private:
    int _cellSize;
    int _rotationState;
    int _rowShelf;
    int _columnShelf;
    std::vector<sf::Color> _colors;
};

#endif