#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) : window(window) {
    Grid grid;

    _blocks = GetAllBlocks();

    _currentBlock = RandomBlock();
    _nextBlock = RandomBlock();

    gameOver = false;
}

std::vector<Block> GameState::GetAllBlocks() {
    return { LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

Block GameState::RandomBlock() {
    if (_blocks.empty()) _blocks = GetAllBlocks();

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
    if (!gameOver) {
        _currentBlock.FallBlock(0, -1);

        if (IsBlockOutside() || !IsExistBlock()) {
            _currentBlock.FallBlock(0, 1);
        }
    }
}

void GameState::MoveRight() {
    if (!gameOver) {
        _currentBlock.FallBlock(0, 1);

        if (IsBlockOutside() || !IsExistBlock()) {
            _currentBlock.FallBlock(0, -1);
        } 
    }
}

void GameState::MoveDown() {
    if (!gameOver) {
        _currentBlock.FallBlock(1, 0);

        if (IsBlockOutside() || !IsExistBlock()) {
            _currentBlock.FallBlock(-1, 0);
            LockBlock();
        }
    }
}

bool GameState::IsBlockOutside() {
    std::vector<Position> states = _currentBlock.GetPositions();

    for (Position object : states) {
        if (_grid.IsOutside(object.row, object.column)) {
            return true;
        }
    }
    return false;
}

void GameState::RotatingBlock() {
    if (!gameOver) {
        _currentBlock.RotateBlock();

        if (IsBlockOutside() || !IsExistBlock()) {
            _currentBlock.LimitRotation();
        }
    }
}

void GameState::LockBlock() {
    std::vector<Position> states = _currentBlock.GetPositions();

    for (Position object : states) {
        _grid.grid[object.row][object.column] = _currentBlock.ID;
    }
    _currentBlock = _nextBlock;

    if (!IsExistBlock()) {
        gameOver = true;
    }

    _nextBlock = RandomBlock();
    _grid.CleanFullRowGrid();
}

bool GameState::IsExistBlock() {
    std::vector<Position> states = _currentBlock.GetPositions();

    for (Position object : states) {
        if (!_grid.IsEmpty(object.row, object.column)) {
            return false;
        }
    }
    return true;
}