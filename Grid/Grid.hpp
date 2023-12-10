#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

const int ROWS = 25;
const int COLUMNS = 15;

class Grid {
public:
    Grid();
    void Initialize();
    void Draw(sf::RenderWindow& window);
    bool IsOutside(int rowObject, int columnObject);

    int grid[ROWS][COLUMNS];

private:
    int _numRows;
    int _numCols;
    int _cellSize;
    std::vector<sf::Color> _colors;
};

#endif