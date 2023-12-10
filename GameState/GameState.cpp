#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) : window(window) {
    Grid grid;
    _blocks = { LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };

    _currentBlock = randomBlock();
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
   _currentBlock.Draw(window);
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
            else if (event.key.code == sf::Keyboard::Up) {
                RotatingBlock();
            }
            else if (event.key.code == sf::Keyboard::Down) {
                MoveDown();
            }
        }
    }
}

void GameState::MoveLeft() {
    _currentBlock.FallBlock(0, -1);

    if (IsBlockOutside()) _currentBlock.FallBlock(0, 1);
}

void GameState::MoveRight() {
    _currentBlock.FallBlock(0, 1);

    if (IsBlockOutside()) _currentBlock.FallBlock(0, -1);
}

void GameState::MoveDown() {
    _currentBlock.FallBlock(1, 0);

    if (IsBlockOutside()) _currentBlock.FallBlock(-1, 0);
}

bool GameState::IsBlockOutside() {
    std::vector<Position> states = _currentBlock.getPositions();

    for (Position object : states) {

        if (_grid.IsOutside(object.row, object.column)) {
            return true;
        }
    }

    return false;
}

void GameState::RotatingBlock() {
    _currentBlock.RotateBlock();

    if (IsBlockOutside()) {
        _currentBlock.LimitRotation();
    }
}

void GameState::SlideDown() {
    _currentBlock.FallBlock(1, 0);

    if (IsBlockOutside()) {
        _currentBlock.FallBlock(-1, 0);
        LockBlock();
    }
}

void GameState::LockBlock() {
    std::vector<Position> states = _currentBlock.getPositions();

    for (Position object : states) {
        _grid.grid[object.row][object.column] = _currentBlock.ID;
    }
    _currentBlock = _nextBlock;
    _nextBlock = randomBlock();
}

// bool GameState::IsExistBlock() {
//     std::vector<Position> states = _currentBlock.getPositions();

//     for (Position object : states) {
//         if (_grid.IsEmpty(object.row, object.column == false)) {
//             return false;
//         }
//     }
//     return true;
// }