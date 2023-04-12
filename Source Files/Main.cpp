#include <SFML/Graphics.hpp>
#include "Player.h"
#include "CreateObstacle.h"
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800,600), "Endless Runner");
    window.setVerticalSyncEnabled(true);

    Event event{};
    Clock dtClock;
    Clock clock;

    Player player;
    CreateObstacle CreateObstacle(player);

    Image bg;
    bg.loadFromFile("background.png");
    Texture bgTexture;
    bgTexture.loadFromImage(bg, IntRect(0, 0, 800, 600));
    Sprite bgSprite;
    bgSprite.setTexture(bgTexture);

    while (window.isOpen()) {
        Time dtTime = dtClock.restart();

        float dt = dtTime.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == Event::EventType::Closed)
                window.close();
        }
       

        if (player.isGameOver() && Keyboard::isKeyPressed(Keyboard::Space)) {
            player.restart();
            CreateObstacle.restart();
        }

        //update position and state with time
        CreateObstacle.update(dt);
        player.update(window, dt);

        window.clear();
        window.draw(bgSprite);

        CreateObstacle.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}