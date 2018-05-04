//
//  Entity.hpp
//  CS2A-Project
//
//  Created by Lykos on 4/25/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Entity{
  
public:
    Entity();
    Entity(sf::RectangleShape rect, sf::Sprite sprite, sf::Text text);
    sf::RectangleShape& getRect() {return rect;}
    sf::Sprite getSprite() const {return sprite;}
    sf::Text getText() const {return text;}
    
    void setRect(sf::RectangleShape rect){this -> rect = rect;}
    void setSprite(sf::Sprite sprite){this -> sprite = sprite;}
    void setText(sf::Text text){this-> text = text;}
    
protected:
    
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    sf::Texture texture;
    
    
};

#include <stdio.h>

#endif /* Entity_hpp */
