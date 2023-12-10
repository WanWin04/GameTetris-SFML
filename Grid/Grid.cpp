#include "Grid.hpp"
#include "../Colors/Colors.hpp"

Grid::Grid() {
    numRows = 40;
    numCols = 100;
    cellSize = 50;
    Initialize();
    colors = getCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++ col) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw(sf::RenderWindow& window) {
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++ col) {
            int cellValue = grid[row][col];
            
            sf::Color cellColor = colors[cellValue];
            float x = col * cellSize + 1;
            float y = row * cellSize + 1;
            sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));
            rect.setPosition(x, y);
            rect.setFillColor(cellColor);

            window.draw(rect);
        }
    }
}