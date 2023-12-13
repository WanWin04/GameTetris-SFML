#include "Music.hpp"

Music::Music() {
    if (!_music.openFromFile("resource/Audio/play.mp3")) {
        throw std::runtime_error("Failed to load music audio");
    }
}

void Music::play() {
    _musicThread = std::thread(&Music::musicThread, this);
}

void Music::musicThread() {
    _music.setVolume(MUSIC_VOLUME);
    _music.play();
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