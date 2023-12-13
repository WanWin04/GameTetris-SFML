#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <string>

#include "../GameState/GameState.hpp"
#include "../Interface/Score/Score.hpp"
#include "../Interface/Next/Next.hpp"
#include "../Interface/UpdateScore/UpdateScore.hpp"
#include "../Interface/GameOver/GameOver.hpp"
#include "../Interface/Control/Control.hpp"
#include "../Music/Music.hpp"
#include "../../global/DEFINITIONS.hpp"

class Application {
public:
    Application(int width, int height, std::string title);
    ~Application();

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
};

#endif