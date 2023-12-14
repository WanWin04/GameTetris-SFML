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
   _currentBlock.Draw(window, 1, 1);
   _nextBlock.Draw(window, WIDTH_NEXT_BLOCK, HEIGHT_NEXT_BLOCK);

   // Time
   _time.UpdateTime();
   window.draw(_time);
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
                    _time.Reset();
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
        case sf::Keyboard::A:
            MoveLeft();
            break;

        case sf::Keyboard::Right:
        case sf::Keyboard::D:
            MoveRight();
            break;

        case sf::Keyboard::Up:
        case sf::Keyboard::W:
            RotatingBlock();
            break;

        case sf::Keyboard::Down:
        case sf::Keyboard::S:
            MoveDown();

            // Solve update score
            UpdateScores(0, 1);
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
        _playMusic.stop();
        _time.Pause();
    }

    _nextBlock = RandomBlock();
    int rowCompleted = _grid.CleanFullRowGrid();

    // Solve update score and play sound
    if (rowCompleted > 0) {
        _playSound.play();
        UpdateScores(rowCompleted, 0);
        _playSound.stop();
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

    // Solve update score
    score = 0;

    _playMusic.play();
}

// Update Scores
void GameState::UpdateScores(int rowsCompleted, int bonus) {
    switch (rowsCompleted)
    {
    case 1:
        score += 100;
        break;

    case 2:
        score += 300;
        break;

    case 3:
        score += 500;
        break;

    case 4:
        score += 700;
        break;
    
    default:
        break;
    }

    score += bonus;
}