#include "Next.hpp"

Next::Next(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_SIZE);
    _text.setFillColor(sf::Color::White);
    _text.setString("NEXT BLOCK");
}

void Next::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}