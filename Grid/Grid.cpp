#include "Grid.hpp"
#include "../Colors/Colors.hpp"

Grid::Grid() : _numRows(25), _numCols(15), _cellSize(50) {
    Initialize();
    _colors = getColors();
}

void Grid::Initialize() {
    for (int row = 0; row < _numRows; ++row) {
        for (int col = 0; col < _numCols; ++col) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Draw(sf::RenderWindow& window) {
    for (int row = 0; row < _numRows; ++row) {
        for (int col = 0; col < _numCols; ++ col) {
            int cellValue = grid[row][col];
            
            sf::Color cellColor = _colors[cellValue];
            float x = col * _cellSize + 1;
            float y = row * _cellSize + 1;
            sf::RectangleShape rect(sf::Vector2f(_cellSize - 1, _cellSize - 1));
            rect.setPosition(x, y);
            rect.setFillColor(cellColor);

            window.draw(rect);
        }
    }
}

bool Grid::IsOutside(int rowObject, int columnObject) {
    if (rowObject < 0 || rowObject >= _numRows || columnObject < 0 || columnObject >= _numCols) {
        return true;
    }
    return false;
}

bool Grid::IsEmpty(int rowObject, int columnObject) {
    if (grid[rowObject][columnObject] == 0) {
        return true;
    }
    return false;
}

bool Grid::IsFullBlock(int rowGrid) {
    for (int col = 0; col < _numRows; ++col) {
        if (grid[rowGrid][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::CleanRowGrid(int rowGrid) {
    for (int col = 0; col < _numRows; ++col) {
        grid[rowGrid][col] = 0;
    }
}

void Grid::CompensationRow(int rowGrid, int numRows) {
    for (int col = 0; col < _numCols; ++col) {
        grid[rowGrid + numRows][col] = grid[rowGrid][col];
        grid[rowGrid][col] = 0;
    }
}

int Grid::CleanFullRowGrid() {
    int pefect = 0;

    for (int rowClean = _numCols - 1; rowClean >= 0; --rowClean) {
        if (IsFullBlock(rowClean)) {
            CleanRowGrid(rowClean);
            pefect++;
        }
        else if (pefect > 0) CompensationRow(rowClean, pefect);
    }
    return pefect;
}