#include "GameOver.hpp"


GameOver::GameOver(const sf::Vector2f& position) : UserInterface(position) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_GAMEOVER_SIZE);
    _text.setFillColor(sf::Color::Red);
    _text.setString("GAME OVER");
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}