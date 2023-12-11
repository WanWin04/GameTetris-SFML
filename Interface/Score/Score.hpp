#ifndef SCORE_HPP
#define SCORE_HPP

#include "../UI/UI.hpp"

class Score : public UserInterface {
public:
    Score(const sf::Vector2f& position = sf::Vector2f(WIDTH_SCORE, HEIGHT_SCORE));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif