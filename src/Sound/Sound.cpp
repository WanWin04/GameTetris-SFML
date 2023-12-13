#include "Sound.hpp"

Sound::Sound() {
    if (!_soundBuffer.loadFromFile("resource/Audio/clear.mp3")) {
        throw std::runtime_error("Failed to load sound file");
    }
    _sound.setBuffer(_soundBuffer);
}

Sound::~Sound() {
    stop();
}

void Sound::play() {
    _soundThred = std::thread(&Sound::soundThread, this);
}

void Sound::soundThread() {
    _sound.setVolume(SOUND_VOLUME);
    _sound.play();
}

void Sound::pause() {
    _sound.pause();
}

void Sound::stop() {
    _sound.stop();

    if (_soundThred.joinable()) {
        _soundThred.join();
    }
}

void Sound::setVolume(float volume) {
    _sound.setVolume(volume);
}