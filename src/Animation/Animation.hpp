#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

#include <fstream>

class Animation {
public:
    Animation(int i_animation_speed, int i_frame_width, int total_frame);

    bool update();

    void drawExplosion(int i_x, int i_y, sf::RenderTarget *target, sf::Texture texture);

    void reset();

    // setter
    void setVars(int animation_iterator,
                 int animation_speed,
                 int current_frame,
                 int frame_width);

    int getCurrentFrame();

private:
    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;

    int total_frames;

    sf::Sprite sprite;
};

#endif