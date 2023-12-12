#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SFML/Audio.hpp>

#include <thread>

class Music {
public:
    Music();

    void play();
    void pause();
    void stop();
    void setVolume(float volume);

private:
    sf::Music _music;
    std::thread _musicThread;

    // functions
    void musicThread();
};

#endif