#ifndef TEMPLE_CreateObstacle_H
#define TEMPLE_CreateObstacle_H

#define SPAWN_X 800
#define SPAWN_Y 255
#define SPAWN_RANDOM_Y 150

#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"
#include "Player.h"
using namespace sf;

class CreateObstacle {
private:
    std::vector <Obstacle> self;
    Player &player;
    Clock clock;
    Clock spawnClock;
    void add(Vector2f vec2f);
public:
    explicit CreateObstacle(Player &ref_player);
    void spawn();
    void update(float dt);
    void draw(RenderWindow &render);
    void restart();
};


#endif
