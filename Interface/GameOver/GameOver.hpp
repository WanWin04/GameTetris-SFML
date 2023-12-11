#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include "../UI/UI.hpp"

class GameOver : public UserInterface {
public:
    GameOver(const sf::Vector2f& position = sf::Vector2f(WIDTH_GAMEOVER, HEIGHT_GAMEOVER));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif