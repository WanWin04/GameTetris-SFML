#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include <string>

#include "../GameState/GameState.hpp"
#include "../ScoreInterface/ScoreInterface.hpp"
#include "../NextInterface/NextInterface.hpp"
#include "../DEFNITIONS.hpp"

class Game {
public:
    Game(int width, int height, std::string title);

    bool EventActivation(double period);

private:
    double currentTime;
    sf::Color _darkBlue;
};

#endif