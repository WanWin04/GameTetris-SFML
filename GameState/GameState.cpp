#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) : window(window) {
    Grid grid;
    _blocks = { LBlock(), TBlock() };

    _truthBlock = randomBlock();
    _nextBlock = randomBlock();
}

Block GameState::randomBlock() {
    int randomItem = rand() % _blocks.size();

    Block block = _blocks[randomItem];
    _blocks.erase(_blocks.begin() + randomItem);

    return block;
}

void GameState::Draw(sf::RenderWindow& window) {
   _grid.Draw(window);
   _truthBlock.Draw(window);
}

void GameState::HandleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                MoveLeft();
            }
            else if (event.key.code == sf::Keyboard::Right) {
                MoveRight();
            }
            else if (event.key.code == sf::Keyboard::Down) {
                MoveDown();
            }
        }
    }
}

void GameState::MoveLeft() {
    _truthBlock.FallBlock(0, -1);

    if (!IsBlockOutside()) _truthBlock.FallBlock(0, 1);
}

void GameState::MoveRight() {
    _truthBlock.FallBlock(0, 1);

    if (!IsBlockOutside()) _truthBlock.FallBlock(0, -1);
}

void GameState::MoveDown() {
    _truthBlock.FallBlock(1, 0);

    if (!IsBlockOutside()) _truthBlock.FallBlock(-1, 0);
}


bool GameState::IsBlockOutside() {
    std::vector<Position> states = _truthBlock.getPositions();

    for (Position object : states) {
        if (_grid.IsOutside(object.row, object.column)) return true;
    }

    return false;
}