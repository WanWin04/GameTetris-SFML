#ifndef MEDAL_HPP
#define MEDAL_HPP

#include "../UI/UI.hpp"

class Medal : public UserInterface {
public:
    Medal(const sf::Vector2f& position = sf::Vector2f(X_MEDAL, Y_MEDAL));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif