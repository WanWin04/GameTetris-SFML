#include "Control.hpp"

Control::Control(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_CONTROL_SIZE);
    _text.setFillColor(sf::Color::White);
    _text.setString("A : move right       D : move left \n\nW : rotate          S : move down \n\nX : exit game");
}

void Control::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}