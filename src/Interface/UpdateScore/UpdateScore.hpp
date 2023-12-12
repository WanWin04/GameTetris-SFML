#ifndef UPDATESCORE_HPP
#define UPDATESCORE_HPP

#include "../UI/UI.hpp"

#include <string>

class UpdateScore : public UserInterface {
public:
    UpdateScore(const sf::Vector2f& position = sf::Vector2f(WIDTH_UPDATE_SCORE, HEIGHT_UPDATE_SCORE));

    void Update(int newScore);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    int _score;
};

#endif