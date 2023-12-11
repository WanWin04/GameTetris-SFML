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
    Block randomBlock();
    std::vector<Block> getAllBlocks();
    void Draw(sf::RenderWindow& window);
    void HandleInput();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    bool IsBlockOutside();
    void RotatingBlock();
    void SlideDown();
    void LockBlock();
    bool IsExistBlock();

    sf::RenderWindow& window;

private:
    Grid _grid;
    Block _currentBlock;
    Block _nextBlock;
    std::vector<Block> _blocks;
};

#endif