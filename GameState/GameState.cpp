#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) : window(window) {
    Grid grid;
    blocks = { LBlock(), TBlock() };

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
    truthBlock.FallBlock(0, -1);
}

void GameState::MoveRight() {
    truthBlock.FallBlock(0, 1);
}

void GameState::MoveDown() {
    truthBlock.FallBlock(1, 0);
}
