#ifndef SCOREINTERFACE_HPP
#define SCOREINTERFACE_HPP

#include "../UI/UI.hpp"

class ScoreInterface : public UserInterface {
public:
    ScoreInterface(const sf::Vector2f& position = sf::Vector2f(WIDTH_SCORE, HEIGHT_SCORE));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif