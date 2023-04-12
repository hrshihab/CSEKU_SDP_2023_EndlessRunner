#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"
using namespace sf;

Obstacle::Obstacle(float speed) {
    this->speed = speed;
    self = RectangleShape(Vector2f(50, 50));
    self.setOrigin(25, 50);
    self.setFillColor(Color::Red);

    spritesheet.loadFromFile("D:/OPP/SFML/enemies.png");
}

void Obstacle::animation() {
    int frame = animClock.getElapsedTime().asMilliseconds() / 300;
    if (frame > 2) {
        animClock.restart();
        frame = 0;
    }
    texture.loadFromImage(spritesheet, IntRect(frame * 16, 16, 16, 16));
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(-4, 4));
    sprite.setOrigin(8, 16);
}

void Obstacle::setPosition(Vector2f vec2f) {
    self.setPosition(vec2f);
}

Vector2f Obstacle::getPosition() {
    return self.getPosition();
}

FloatRect Obstacle::getGlobalBounds() {
    return self.getGlobalBounds();
}

void Obstacle::draw(RenderWindow &render) {
    sprite.setPosition(self.getPosition());
    render.draw(sprite);
}

void Obstacle::update(float dt) {
    self.move(-this->speed * dt, 0);
    animation();
}