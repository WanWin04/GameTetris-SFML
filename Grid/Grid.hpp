#ifndef GRID_HPP
#define GRID_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class Grid {
public:
    Grid();
    void Initialize();
    void Draw(sf::RenderWindow& window);
    void Print();

    int grid[40][100];

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<sf::Color> colors;
};

#endif