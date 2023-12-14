#include "Music.hpp"

Music::Music() {
    if (!_music.openFromFile("resource/Audio/play.mp3")) {
        throw std::runtime_error("Failed to load music audio");
    }
}

Music::~Music() {
    stop();
}

void Music::play() {
    _musicThread = std::thread(&Music::musicThread, this);
}

void Music::musicThread() {
    _music.setVolume(MUSIC_VOLUME);
    _music.play();

    // play music again
    while (_music.getStatus() == sf::Music::Playing) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void Music::pause() {
    _music.pause();
}

void Music::stop() {
    _music.stop();

    if (_musicThread.joinable()) {
        _musicThread.join();
    }
}

void Music::setVolume(float volume) {
    _music.setVolume(volume);
}