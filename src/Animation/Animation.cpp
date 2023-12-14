// #include "Animation.hpp"

// Animation::Animation(const sf::Vector2f& position, const std::vector<std::string>& imagePaths, float cycleTime)
//     : position(position), images(imagePaths), cycleTime(cycleTime), elapsedTime(sf::Time::Zero), isPlaying(true), frameCount(0) {
// }

// void Animation::Show(sf::RenderWindow& window) {
//     if (!isPlaying) {
//         return;
//     }

//     if (frameCount < images.size()) {
//         sf::Texture texture;
//         if (texture.loadFromFile(images[frameCount])) {
//             sf::Sprite sprite(texture);
//             sprite.setPosition(position);
//             window.draw(sprite);
//         }
//     }

//     elapsedTime += clock.restart();

//     if (elapsedTime >= sf::seconds(cycleTime)) {
//         elapsedTime = sf::Time::Zero;
//         frameCount++;

//         if (frameCount >= images.size()) {
//             isPlaying = false;
//         }
//     }
// }

// bool Animation::IsFinished() const {
//     return isPlaying;
// }

// void Animation::Reset() {
//     isPlaying = true;
//     frameCount = 0;
// }