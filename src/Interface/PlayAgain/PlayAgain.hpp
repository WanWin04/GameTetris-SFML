#ifndef PLAYAGAIN_HPP
#define PLAYAGAIN_HPP

#include "../UI/UI.hpp"
#include "../../Colors/Colors.hpp"

class PlayAgain : public UserInterface {
public:
    PlayAgain(const sf::Vector2f& position = sf::Vector2f(WIDTH_PLAY_AGAIN, HEIGHT_PLAY_AGAIN));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif