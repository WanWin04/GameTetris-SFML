#include "PlayAgain.hpp"

PlayAgain::PlayAgain(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_PLAY_AGAIN_SIZE);
    _text.setFillColor(sf::Color::Black);
    _text.setString("Press random key : new game");
}

void PlayAgain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}