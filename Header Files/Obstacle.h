#ifndef TEMPLE_OBSTACLE_H
#define TEMPLE_OBSTACLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;

class Obstacle {
private:
    RectangleShape self;
    Image spritesheet;
    Sprite sprite;
    Texture texture;
    Clock animClock;
    float speed;
    void animation();
public:
    explicit Obstacle(float speed);
    void setPosition(Vector2f vec2f);
    Vector2f getPosition();
    FloatRect getGlobalBounds();
    void update(float dt);
    void draw(RenderWindow &render);
};


#endif
