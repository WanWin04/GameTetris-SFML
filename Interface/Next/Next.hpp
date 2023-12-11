#ifndef NEXT_HPP
#define NEXT_HPP

#include "../UI/UI.hpp"

class Next : public UserInterface {
public:
    Next(const sf::Vector2f& position = sf::Vector2f(WIDTH_NEXT, HEIGHT_NEXT));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif