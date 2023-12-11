#ifndef NEXTINTERFACE_HPP
#define NEXTINTERFACE_HPP

#include "../UserInterface/UserInterface.hpp"

class NextInterface : public UserInterface {
public:
    NextInterface(const sf::Vector2f& position = sf::Vector2f(WIDTH_NEXT, HEIGHT_NEXT));

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif