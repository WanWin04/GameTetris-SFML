#include "Grid.hpp"

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

std::vector<sf::Color> Grid::getCellColors() {
    sf::Color darkGrey(26, 31, 40, 255);
    sf::Color green(47, 230, 23, 255);
    sf::Color orange(226, 116, 17, 255);
    sf::Color yellow(237, 234, 4, 255);
    sf::Color purple(166, 0, 247, 255);
    sf::Color cyan(21, 204, 209, 255);
    sf::Color blue(13, 64, 216, 255);

    return {darkGrey, green, orange, yellow, purple, cyan, blue};
}