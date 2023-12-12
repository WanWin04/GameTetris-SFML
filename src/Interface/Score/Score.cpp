#include "Score.hpp"

Score::Score(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_SCORE_SIZE);
    _text.setFillColor(sf::Color::White);
    _text.setString("SCORE :");
}

void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}