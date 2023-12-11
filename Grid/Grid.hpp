#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "../DEFNITIONS.hpp"

class Grid {
public:
    Grid();

    void Initialize();
    void Draw(sf::RenderWindow& window);
    void CleanRowGrid(int rowGrid);
    void CompensationRow(int rowGrid, int numRows);

    int CleanFullRowGrid();

    bool IsOutside(int rowObject, int columnObject);
    bool IsEmpty(int rowObject, int columnObject);
    bool IsFullBlock(int rowGrid);

    // variables
    int grid[NUMBER_ROWS][NUMBER_COLUMNS];

private:
    int _numRows;
    int _numCols;
    int _cellSize;
    std::vector<sf::Color> _colors;
};

#endif