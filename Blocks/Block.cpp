#include "Block.hpp"

Block::Block() : cellSize(50), rotationState(0), rowShelf(0), columnShelf(0) {
    colors = getColors(); 
}

void Block::Draw(sf::RenderWindow& window) {
    std::vector<Position> states = getPositions();

    for (Position object : states) {
        sf::Color cellColor = colors[ID];
        float x = object.column * cellSize + 1;
        float y = object.row * cellSize + 1;
        sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));
        rect.setPosition(x, y);
        rect.setFillColor(cellColor);

        window.draw(rect);
    }
}

void Block::FallBlock(int rows, int columns) {
    rowShelf += rows;
    columnShelf += columns;
}

std::vector<Position> Block::getPositions() {
    std::vector<Position> states = cells[rotationState];
    std::vector<Position> changeStates;

    for (Position object : states) {
        Position newPositon = Position(object.row + rowShelf, object.column + columnShelf);
        changeStates.push_back(newPositon);
    }

    return changeStates;
}