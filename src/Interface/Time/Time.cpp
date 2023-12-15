#include "Time.hpp"

Time::Time(const sf::Vector2f& position) : UserInterface(position), _paused(false), _totalSeconds(0), _hours(0), _minutes(0), _seconds(0) {
    if (!_font.loadFromFile("resource/Font/Marker-Felt.ttf")) {
        return;
    }

    _text.setFont(_font);
    _text.setCharacterSize(CHARACTER_SCORE_SIZE);
    _text.setFillColor(sf::Color::White);

    _elapsedTime = sf::Time::Zero;
    _totalPausedTime = sf::Time::Zero;

    _clock.restart();
}

void Time::UpdateTime() {
    if (!_paused) {
        _elapsedTime += _clock.restart();
    } else {
        _totalPausedTime += _clock.restart();
    }

    if (!_paused) {
        _totalSeconds = static_cast<int>(_elapsedTime.asSeconds() - _totalPausedTime.asSeconds());

        _hours = _totalSeconds / 3600;
        _minutes = (_totalSeconds % 3600) / 60;
        _seconds = _totalSeconds % 60;
    }

    std::ostringstream ss;
    ss << "Time : " << std::setfill('0') << std::setw(2) << _hours << ":" << std::setw(2) << _minutes << ":" << std::setw(2) << _seconds;
    _text.setString(ss.str());
}

void Time::Pause() {
    _paused = true;
}

void Time::Reset() {
    _elapsedTime = sf::Time::Zero;
    _totalPausedTime = sf::Time::Zero;
    _clock.restart();
    _paused = false;
}

void Time::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_text, states);
}