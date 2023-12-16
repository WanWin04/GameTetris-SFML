#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../UI/UI.hpp"

class Level : public UserInterface {
public:
    Level(const sf::Vector2f& position = sf::Vector2f(WIDTH_LEVEL, HEIGHT_LEVEL));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif