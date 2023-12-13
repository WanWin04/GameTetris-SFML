#include "Block.hpp"

Block::Block() : _cellSize(CELL_SIZE), _rotationState(0), _rowShelf(0), _columnShelf(0) {
    _colors = getColors(); 
}

void Block::Draw(sf::RenderWindow& window, int rowShelf, int columnShelf) {
    std::vector<Position> states = GetPositions();

    for (Position object : states) {
        sf::Color cellColor = _colors[ID];
        float x = object.column * _cellSize + rowShelf;
        float y = object.row * _cellSize + columnShelf;
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

std::vector<Position> Block::GetPositions() {
    std::vector<Position> states = cells[_rotationState];
    std::vector<Position> changeStates;

    for (Position object : states) {
        Position newPositon = Position(object.row + _rowShelf, object.column + _columnShelf);
        changeStates.push_back(newPositon);
    }
    return changeStates;
}

void Block::RotateBlock() {
    ++_rotationState;

    if (_rotationState == (int)cells.size()) {
        _rotationState = 0;
    }
}

void Block::LimitRotation() {
    --_rotationState;

    if (_rotationState == -1) {
        _rotationState = cells.size() - 1;
    }
}