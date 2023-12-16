#ifndef UPDATE_LEVEL
#define UPDATE_LEVEL

#include "../UI/UI.hpp"

#include <string>

class UpdateLevel: public UserInterface {
public:
    UpdateLevel(const sf::Vector2f& position = sf::Vector2f(WIDTH_UPDATE_LEVEL, HEIGHT_UPDATE_LEVEL));

    void Update(int newScore);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    int _level;
};

#endif