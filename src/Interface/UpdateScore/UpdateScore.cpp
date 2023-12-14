#include "UpdateScore.hpp"

UpdateScore::UpdateScore(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_UPDATE_SIZE);
    _text.setFillColor(sf::Color::Red);
}

void UpdateScore::Update(int newScore) {
    _score = newScore;
    _text.setString(std::to_string(_score));
}

void UpdateScore::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}