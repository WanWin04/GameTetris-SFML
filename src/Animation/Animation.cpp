#include "Animation.hpp"

Animation::Animation(int i_animation_speed, int i_frame_width, int total_frame) : animation_iterator(0),
                                                                                  animation_speed(std::max<int>(1, i_animation_speed)),
                                                                                  current_frame(0),
                                                                                  frame_width(i_frame_width)
{
    this->total_frames = total_frame;
}

int Animation::getCurrentFrame() {
    return current_frame;
}

bool Animation::update() {
    bool output = 0;

    animation_iterator++;

    while (animation_iterator >= animation_speed)
    {
        animation_iterator -= animation_speed;
        current_frame++;

        if (current_frame == total_frames)
        {
            output = 1;
            current_frame = 0;
        }
    }

    return output;
}

void Animation::drawExplosion(int i_x, int i_y, sf::RenderTarget *target, sf::Texture texture) {
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    sprite.setPosition(i_x, i_y);

    target->draw(sprite);
}

void Animation::reset() {
    animation_iterator = 0;
    current_frame = 0;
}

void Animation::setVars(int animation_iterator,
                        int animation_speed,
                        int current_frame,
                        int frame_width)
{
    this->animation_iterator = animation_iterator;
    this->animation_speed = animation_speed;
    this->current_frame = current_frame;
    this->frame_width = frame_width;
}