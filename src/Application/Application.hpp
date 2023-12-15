#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <iostream>

#include "../GameState/GameState.hpp"
#include "../Interface/Score/Score.hpp"
#include "../Interface/Next/Next.hpp"
#include "../Interface/UpdateScore/UpdateScore.hpp"
#include "../Interface/GameOver/GameOver.hpp"
#include "../Interface/Control/Control.hpp"
#include "../Interface/Medal/Medal.hpp"
#include "../Interface/PlayAgain/PlayAgain.hpp"
#include "../Music/Music.hpp"
#include "../Colors/Colors.hpp"
#include "../Animation/Animation.hpp"
#include "../../global/DEFINITIONS.hpp"

class Application {
public:
    Application(int width, int height, std::string title);
    ~Application();

    void SetNextBlock();
    void HandleEvents(sf::RenderWindow& window, GameState& gameState);
    void HandleInput(GameState& gameState);
    void UpdateAndDrawGameOver(sf::RenderWindow& window, GameState& gameState);

    bool EventActivation(double period);

private:
    double _currentTime;
    sf::Color _lightGreen;
    Score _score;
    Next _next;
    UpdateScore _updateScore;
    GameOver _gameOver;
    Music _playMusic;
    Control _control;
    sf::Texture _background;
    sf::RectangleShape _rect;
    Medal _medal;
    PlayAgain _playAgain;
};

#endif