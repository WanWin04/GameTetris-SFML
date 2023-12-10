#include "GameState.hpp"

GameState::GameState() {
    Grid grid;
    blocks = { LBlock() };

    truthBlock = randomBlock();
    nextBlock = randomBlock();
}

Block GameState::randomBlock() {
    int randomItem = rand() % blocks.size();

    Block block = blocks[randomItem];
    blocks.erase(blocks.begin() + randomItem);

    return block;
}

void GameState::Draw(sf::RenderWindow& window) {
    grid.Draw(window);
    truthBlock.Draw(window);
}