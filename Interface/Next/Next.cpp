#include "Next.hpp"

NextInterface::NextInterface(const sf::Vector2f& position) : UserInterface(position) {
    _text.setString("NEXT BLOCK");
}

void NextInterface::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}