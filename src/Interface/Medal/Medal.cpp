#include "Medal.hpp"

Medal::Medal(const sf::Vector2f& position) : UserInterface(position) {
    if (!_texture.loadFromFile("resource/Image/medal.png")) {
        std::cout << "Failed to load image" << std::endl;
    }

    _sprite.setTexture(_texture);
    _sprite.setPosition(position);
}

void Medal::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}