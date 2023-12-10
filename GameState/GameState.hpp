#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <random>

#include "../Grid/Grid.hpp"
#include "../Blocks/Block.hpp"

class GameState {
public:
    GameState();
    Block randomBlock();
    void Draw(sf::RenderWindow& window);

private:
    Grid grid;
    Block truthBlock;
    Block nextBlock;
    std::vector<Block> blocks;
};

#endif