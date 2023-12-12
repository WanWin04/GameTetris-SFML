#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include <string>

#include "../GameState/GameState.hpp"
#include "../Interface/Score/Score.hpp"
#include "../Interface/Next/Next.hpp"
#include "../Interface/UpdateScore/UpdateScore.hpp"
#include "../Interface/GameOver/GameOver.hpp"
#include "../Music/Music.hpp"
#include "../../global/DEFINITIONS.hpp"

class Game {
public:
    Game(int width, int height, std::string title);
    ~Game();

    void HandleEvents(sf::RenderWindow& window, GameState& gameState);
    void HandleInput(GameState& gameState);
    void UpdateAndDrawGameOver(sf::RenderWindow& window, GameState& gameState);

    bool EventActivation(double period);

private:
    double currentTime;
    sf::Color _lightGreen;
    Score _score;
    Next _next;
    UpdateScore _updateScore;
    GameOver _gameOver;
    Music _playMusic;
};

#endif