#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "../DEFINITIONS/DEFINITIONS.hpp"

class Grid {
public:
    Grid();

    void Initialize();
    void Draw(sf::RenderWindow& window);

    void Print();

    int CleanFullRowGrid();

    bool IsOutside(int rowObject, int columnObject);
    bool IsEmpty(int rowObject, int columnObject);

    // variables
    int grid[NUMBER_ROWS][NUMBER_COLUMNS];

private:
    int _numRows;
    int _numCols;
    int _cellSize;
    std::vector<sf::Color> _colors;

    // Functions 
    bool IsFullBlock(int rowGrid);
    void CleanRowGrid(int rowGrid);
    void CompensationRow(int rowGrid, int numRows);
};

#endif