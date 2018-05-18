
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
#include "Collider.hpp"
#include "Player.hpp"
#include "platform.hpp"
#include "Enemy.h"
#include "Projectile.hpp"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

static const float View_height = 100.0f;
void ResizeView(sf::RenderWindow& window, sf::View& view){
	float ratio = float(window.getSize().x)/ float(window.getSize().y);
	view.setSize(View_height * ratio, View_height);
}

int main(int, char const**)
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window", sf::Style::Default);

//	sf::Texture texture;
//	texture.loadFromFile("galaxy2.jpg");
//	sf::Sprite background;
//	background.setScale(sf::Vector2f(10,6)); 
//	background.setTexture(texture);
    
	sf::Texture playerTexture;
    playerTexture.loadFromFile("akalicopy.png");
    Player player(&playerTexture, sf::Vector2u(4,5), 0.3f, 100.0f, 1.0f);
    
	vector<Projectile> projectileArr;
    Projectile scyth(&playerTexture, sf::Vector2u(4,5),0.3f, 200.0f);
    
	Platform floor(nullptr, sf::Vector2f(2000.0f,25.0f), player.getPosition());	
    
	sf::View view;
	view.setSize(600.0f,400.0f);

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

    //  if (deltaTime > 1.0f / 20.0f) {
    //  	deltaTime = 1.0f / 20.0f;
    //  }

        if (deltaTime > 1.0f / 20.0f) {
            deltaTime = 1.0f / 20.0f;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

			if(event.type == sf::Event::Resized){
				ResizeView(window,view);
			}
        }
//        animation.update(0, deltaTime, true);
//        player.setTextureRect(animation.uvRect);
        

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
		floor.GetCollider().checkCollision(player.getCollider(), 0.0f);
//        scyth.Update(deltaTime);
        view.setCenter(player.getPosition());
        window.clear();
		window.setView(view);
        //scyth.Draw(window);
		floor.Draw(window);
        player.Draw(window);
        enemy1.drawEnemy(window);
        enemy2.drawEnemy(window);
        enemy3.drawEnemy(window);
//        scyth.Draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
