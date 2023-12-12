#ifndef USER_HPP
#define USER_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

#include "../../../global/DEFINITIONS.hpp"

class UserInterface : public sf::Drawable {
public:
    UserInterface(const sf::Vector2f& position);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

protected:
    sf::Font _font;
    sf::Text _text;
    sf::Vector2f _position;
};

#endif