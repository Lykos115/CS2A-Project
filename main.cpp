
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Player.hpp"
#include "Enemy.h"
#include "Projectile.hpp"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    srand(static_cast<unsigned int>(time(NULL)));
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");


    // Player Object
    sf::Texture playerTexture;
    playerTexture.loadFromFile(resourcePath() + "akalicopy.png");
    Player player(&playerTexture, sf::Vector2u(4,5), 0.3f, 100.0f, 1.0f);
    // Enemy objects
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile(resourcePath() + "sprite.png");
    Enemy enemy1(&enemyTexture,sf::Vector2u(1,1), true, 110.0f, 20.0f);
    Enemy enemy2(&enemyTexture,sf::Vector2u(1,1), true, 110.0f, 20.0f);
    Enemy enemy3(&enemyTexture,sf::Vector2u(1,1), true, 110.0f, 20.0f);


    vector<Projectile> projectileArr;
    Projectile scyth(&playerTexture, sf::Vector2u(4,5),0.3f, 200.0f);


    float deltaTime = 0.0f;
    sf::Clock clock;
    float secondTime = 0;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f) {
            deltaTime = 1.0f / 20.0f;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

//        animation.update(0, deltaTime, true);
//        player.setTextureRect(animation.uvRect);


        secondTime += deltaTime;
        if(secondTime > 0.30f){
            secondTime = 0;
            enemy1.behavior(deltaTime);
            enemy2.behavior(deltaTime);
            enemy3.behavior(deltaTime);
        }

        player.Update(deltaTime);
//        scyth.Update(deltaTime);

        window.clear();
        player.Draw(window);
        enemy2.drawEnemy(window);
        enemy2.drawEnemy(window);
        enemy2.drawEnemy(window);
//        scyth.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
