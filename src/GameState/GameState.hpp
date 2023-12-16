#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

#include <random>
#include <ctime>

#include "../Grid/Grid.hpp"
#include "../Block/Block.hpp"
#include "../TypeBlocks/TypeBlocks.hpp"
#include "../Sound/Sound.hpp"
#include "../Music/Music.hpp"
#include "../Interface/Time/Time.hpp"

class GameState {
public:
    GameState(sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window);

    // Handle Input 
    void HandleInput();

    // Handle Block
    void MoveDown();

    void LockBlock();

    void Ghost(sf::RenderWindow& window);

    void Freeze();

    // variables
    bool gameOver;
    int score;

private:
    sf::RenderWindow& window;
    Grid _grid;
    Block _currentBlock;
    Block _nextBlock;
    std::vector<Block> _blocks;
    Sound _playSound;
    Music _playMusic;
    Time _time;
    Block _ghostBlock;

    // Random Block
    Block RandomBlock();
    std::vector<Block> GetAllBlocks();

    // Handle Input 
    void HandleGameInput(sf::Keyboard::Key key);

    // Handle Block
    void MoveLeft();
    void MoveRight();
    void RotatingBlock();
    void SlideDown();

    bool IsBlockOutside();
    bool IsExistBlock();

    bool IsGhostOutside();
    bool IsExistGhost();

    // Game Reset
    void GameReset();

    // Update Score
    void UpdateScores(int rowsCompleted, int bonus);
};

#endif