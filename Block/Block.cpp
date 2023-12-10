#include "Block.hpp"

Block::Block() : _cellSize(50), _rotationState(0), _rowShelf(0), _columnShelf(0) {
    _colors = getColors(); 
}

void Block::Draw(sf::RenderWindow& window) {
    std::vector<Position> states = getPositions();

    for (Position object : states) {
        sf::Color cellColor = _colors[ID];
        float x = object.column * _cellSize + 1;
        float y = object.row * _cellSize + 1;
        sf::RectangleShape rect(sf::Vector2f(_cellSize - 1, _cellSize - 1));
        rect.setPosition(x, y);
        rect.setFillColor(cellColor);

        window.draw(rect);
    }
}

void Block::FallBlock(int rows, int columns) {
    _rowShelf += rows;
    _columnShelf += columns;
}

std::vector<Position> Block::getPositions() {
    std::vector<Position> states = cells[_rotationState];
    std::vector<Position> changeStates;

    for (Position object : states) {
        Position newPositon = Position(object.row + _rowShelf, object.column + _columnShelf);
        changeStates.push_back(newPositon);
    }

    return changeStates;
}

int Block::getRowOffset() const { return _rowShelf; }

int Block::getColumnOffset() const { return _columnShelf; }