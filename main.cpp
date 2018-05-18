
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
#include "Projectile.hpp"
#include <vector>
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
    //sf::Sprite floor;
	//floor.setPosition(0.0f,1050.0f);
/*	
	sf::Texture floor_im;
	floor_im.loadFromFile("brick.jpg");
	//floor.setScale(sf::Vector2f(8,0.5));
	floor.setTexture(floor_im);
	*/
	sf::View view;
	view.setSize(600.0f,400.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
    //  if (deltaTime > 1.0f / 20.0f) {
    //  	deltaTime = 1.0f / 20.0f;
    //  }
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
        
        
        player.Update(deltaTime);
		floor.GetCollider().checkCollision(player.getCollider(), 0.0f);
//        scyth.Update(deltaTime);
        view.setCenter(player.getPosition());
        window.clear();
		window.setView(view);
        //scyth.Draw(window);
	//	window.draw(background);
		floor.Draw(window);
		//window.draw(floor);
 		player.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
