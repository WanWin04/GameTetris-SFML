#include "Score.hpp"

ScoreInterface::ScoreInterface(const sf::Vector2f& position) : UserInterface(position) {
    _text.setString("SCORE");
}

void ScoreInterface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}