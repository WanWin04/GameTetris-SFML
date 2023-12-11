#ifndef ANIMATEDTEXT_HPP
#define ANIMATEDTEXT_HPP

#include <SFML/Graphics.hpp>

#include <string>

#include "../../DEFINITIONS.hpp"

class AnimatedText : public sf::Drawable {
public:
    AnimatedText(const sf::Font font, const sf::Vector2f& position, const std::string& text);

    void update(float deltaTime);
    void reset();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    const sf::Font& _font;
    sf::Text _text;
    std::string _originalText;
    std::size_t _currentCharacterIndex;
    float _timeElapsed;
};

#endif