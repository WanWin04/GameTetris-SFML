#include "Score.hpp"

Score::Score(const sf::Vector2f& position) : UserInterface(position) {
    _text.setString("SCORE");
}

void Score::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}