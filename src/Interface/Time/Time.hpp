#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "../UI/UI.hpp"
#include "../../Colors/Colors.hpp"

class Time : public UserInterface {
public:
    Time(const sf::Vector2f& position = sf::Vector2f(WIDTH_TIME, HEIGHT_TIME));

    void UpdateTime();
    void Pause();
    void Reset();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    int _totalSeconds, _hours, _minutes, _seconds;
    bool _paused;
    sf::Clock _clock;
    sf::Time _elapsedTime;
    sf::Time _totalPausedTime;
};

#endif