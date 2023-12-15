#include "Music.hpp"

Music::Music() : _looping(false) {
    if (!_music.openFromFile("resource/Audio/play.mp3")) {
        throw std::runtime_error("Failed to load music audio");
    }
}

Music::~Music() {
    stop();
}

void Music::play() {
    _looping = true;
    _musicThread = std::thread(&Music::musicThread, this);
}

void Music::musicThread() {
    _music.setVolume(MUSIC_VOLUME);
    _music.play();

    while (_looping) {
        // Wait for the music to finish
        while (_music.getStatus() == sf::Music::Playing) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        // If looping is enabled, play the music again
        if (_looping) {
            _music.play();
        }
    }
}

void Music::pause() {
    _music.pause();
}

void Music::stop() {
    _looping = false;
    _music.stop();

    if (_musicThread.joinable()) {
        _musicThread.join();
    }
}

void Music::setVolume(float volume) {
    _music.setVolume(volume);
}

// void Music::setLoop(bool loop) {
//     _looping = loop;
// }