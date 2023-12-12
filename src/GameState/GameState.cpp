#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) : window(window) {
    Grid grid;

    _blocks = GetAllBlocks();

    _currentBlock = RandomBlock();
    _nextBlock = RandomBlock();

    gameOver = false;
    score = 0;
}

void GameState::Draw(sf::RenderWindow& window) {
   _grid.Draw(window);
   _currentBlock.Draw(window);
}

// Random Block
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
// End of Random Block

// Handle Input 
void GameState::HandleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (gameOver) {
                    gameOver = false;
                    GameReset();
                } else {
                    HandleGameInput(event.key.code);
                }
                break;

            default:
                break;
        }
    }
}

void GameState::HandleGameInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Left:
            MoveLeft();
            break;

        case sf::Keyboard::Right:
            MoveRight();
            break;

        case sf::Keyboard::Up:
            RotatingBlock();
            break;

        case sf::Keyboard::Down:
            MoveDown();
            break;

        default:
            break;
    }
}
// End of Handle Input  

// Handle Block 
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

bool GameState::IsBlockOutside() {
    std::vector<Position> states = _currentBlock.GetPositions();

    for (Position object : states) {
        if (_grid.IsOutside(object.row, object.column)) {
            return true;
        }
    }
    return false;
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
// End of Handle Block 

// Game Reset
void GameState::GameReset() {
    _grid.Initialize();

    _blocks = GetAllBlocks();
    _currentBlock = RandomBlock();
    _nextBlock = RandomBlock();
}

// Update Scores
void GameState::UpdateScores(int rowsCompleted, int bonus) {
    
}