#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

#include <random>
#include <ctime>

#include "../Grid/Grid.hpp"
#include "../Block/Block.hpp"
#include "../TypeBlocks/TypeBlocks.hpp"

class GameState {
public:
    GameState(sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window);

    // Handle Input 
    void HandleInput();

    // Handle Block
    void MoveDown();

    // variables
    bool gameOver;

private:
    sf::RenderWindow& window;
    Grid _grid;
    Block _currentBlock;
    Block _nextBlock;
    std::vector<Block> _blocks;

    // Random Block
    Block RandomBlock();
    std::vector<Block> GetAllBlocks();

    // Handle Input 
    void HandleGameInput(sf::Keyboard::Key key);

    // Handle Block
    void MoveLeft();
    void MoveRight();
    void RotatingBlock();
    void LockBlock();

    bool IsBlockOutside();
    bool IsExistBlock();

    // Game Reset
    void GameReset();
};

#endif