
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

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    
    
    sf::Texture playerTexture;
    playerTexture.loadFromFile(resourcePath() + "akali.png");
    
    Player player(&playerTexture, sf::Vector2u(4,5), 0.3f, 100.0f, 1.0f);
    
    
    float deltaTime = 0.0f;
    sf::Clock clock;


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
        
        player.Update(deltaTime);
        
        window.clear();
        player.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
