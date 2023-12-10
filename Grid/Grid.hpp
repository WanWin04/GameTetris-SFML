#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

const int ROWS = 40;
const int COLUMNS = 100;

class Grid {
public:
    Grid();
    void Initialize();
    void Draw(sf::RenderWindow& window);
    bool IsOutside(int rowObject, int columnObject);

    int grid[ROWS][COLUMNS];

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<sf::Color> colors;
};

#endif