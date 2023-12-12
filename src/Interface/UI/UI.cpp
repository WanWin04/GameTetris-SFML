#include "UI.hpp"

UserInterface::UserInterface(const sf::Vector2f& position) : _position(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_SIZE);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(_position);
    _text.setScale(2, 2);
}