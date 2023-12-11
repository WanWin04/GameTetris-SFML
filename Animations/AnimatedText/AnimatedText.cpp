#include "AnimatedText.hpp"

AnimatedText::AnimatedText(const sf::Font font, const sf::Vector2f& position, const std::string& text) 
    : _font(font), _originalText(text), _currentCharacterIndex(0), _timeElapsed(0.0f) {
    
    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_SIZE);
    _text.setPosition(position);
    _text.setFillColor(sf::Color::White);
    _text.setString("");
}

void AnimatedText::update(float deltaTime) {
    _timeElapsed += deltaTime;

    if (_timeElapsed >= 0.1f && _currentCharacterIndex < _originalText.size()) {
        _text.setString(_text.getString() + _originalText[_currentCharacterIndex]);
        ++_currentCharacterIndex;
        _timeElapsed = 0.0f;
    }
}

void AnimatedText::reset() {
    _text.setString("");
    _currentCharacterIndex = 0;
    _timeElapsed = 0.0f;
}

void AnimatedText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}