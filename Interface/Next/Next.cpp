#include "Next.hpp"

Next::Next(const sf::Vector2f& position) : UserInterface(position) {
    _text.setString("NEXT BLOCK");
}

void Next::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}