#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio.hpp>

#include <thread>

#include "../../global/DEFINITIONS.hpp"

class Sound {
public:
    Sound();

    void play();
    void pause();
    void stop();
    void setVolume(float volume);

private:
    sf::SoundBuffer _soundBuffer;
    sf::Sound _sound;
    std::thread _soundThred;

    // functions
    void soundThread();
};

#endif