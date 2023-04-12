#include "CreateObstacle.h"
#include <math.h>
using namespace sf;

CreateObstacle::CreateObstacle(Player &ref_player) : player(ref_player) {
}

//Generate new obstacle and set position

void CreateObstacle::add(sf::Vector2f vec2f) {
    float multiplier = clock.getElapsedTime().asSeconds();
    Obstacle obstacle(500 + multiplier * 10);
    obstacle.setPosition(vec2f);
    self.push_back(obstacle);
}

//Generate Obstacle Periodically

void CreateObstacle::spawn() {
    float time = spawnClock.getElapsedTime().asSeconds();
    float multiplier = clock.getElapsedTime().asSeconds();
    if (time > 1 - (multiplier * 0.01)) {
        spawnClock.restart(); //reset clock to measure the elapsed time until the next obstacle spawned.
        add(sf::Vector2f(SPAWN_X, SPAWN_Y + rand() % SPAWN_RANDOM_Y));
    }
}

void CreateObstacle::update(float dt) {

    if (player.isGameOver()) {
        return;
    }

    spawn();

    for (auto it = self.begin(); it != self.end();) {
        it->update(dt);

        //Colission Check
        if (it->getGlobalBounds().intersects(player.getGlobalBounds())) {
            player.kill();
        }
        if (it->getPosition().x < -50) {
            it = self.erase(it);
        } else {
            ++it;
        }
    }
}

void CreateObstacle::draw(sf::RenderWindow &render) {
    for (auto &it : self) {
        it.draw(render);
    }
}

void CreateObstacle::restart() {
    clock.restart();
    spawnClock.restart();
    self = std::vector<Obstacle>();
}