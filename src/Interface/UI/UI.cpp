#include "UI.hpp"

UserInterface::UserInterface(const sf::Vector2f& position) : _position(position) {
    _text.setPosition(_position);
    _text.setScale(2, 2);
}