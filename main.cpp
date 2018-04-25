
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
#include <iostream>

using namespace std;

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    cout << "test";
    int counter = 0;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // Load a sprite to display
    sf::Texture Playertexture;
    if (!Playertexture.loadFromFile(resourcePath() + "akali.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(Playertexture);
    sprite.setPosition(window.getSize().x/2, window.getSize().y/2);
    sprite.setTextureRect(sf::IntRect(0,80,70,100));
    //    sprite.setTextureRect(sf::IntRect(70,100,80,100));
    //    sprite.setTextureRect(sf::IntRect(155,100,60,90));
    //    sprite.setTextureRect(sf::IntRect(207,100,90,90));
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);
    
    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(1,0);
            if (counter < 0) {
                sprite.setTextureRect(sf::IntRect(0,80,70,100));
                counter++;
            } else if (counter < 50){
                sprite.setTextureRect(sf::IntRect(70,100,80,100));
                counter++;
            }else if(counter < 100){
                sprite.setTextureRect(sf::IntRect(155,100,60,90));
                counter++;
            }else if(counter <=150){
                sprite.setTextureRect(sf::IntRect(207,100,90,90));
                counter = 0;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-1,0);
            
            
            
        }
        
        
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(sprite);
        
        // Draw the string
        window.draw(text);
        
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}

