#include "GameOver.hpp"

GameOver::GameOver(const sf::Vector2f& position) : UserInterface(position) {
    _text.setString("GAME OVER");
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}