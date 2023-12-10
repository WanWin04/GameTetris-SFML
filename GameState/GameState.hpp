#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

#include <random>

#include "../Grid/Grid.hpp"
#include "../Block/Block.hpp"
#include "../TypeBlocks/TypeBlocks.hpp"

class GameState {
public:
    GameState(sf::RenderWindow& window);
    Block randomBlock();
    void Draw(sf::RenderWindow& window);
    void HandleInput();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    bool IsBlockOutside();

private:
    Grid _grid;
    Block _truthBlock;
    Block _nextBlock;
    std::vector<Block> _blocks;
    sf::RenderWindow& window;
};

#endif