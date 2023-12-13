#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "../UI/UI.hpp"

class Control : public UserInterface {
public:
    Control(const sf::Vector2f& position = sf::Vector2f(WIDTH_CONTROL, HEIGHT_CONTROL));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif