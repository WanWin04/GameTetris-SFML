#include "Block.hpp"

Block::Block() : cellSize(50), rotationState(0) { colors = getCellColors(); }

void Block::Draw(sf::RenderWindow& window) {
    std::vector<Position> states = cells[rotationState];

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