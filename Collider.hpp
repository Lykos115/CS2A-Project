//
//  Collider.hpp
//  
//
//  Created by Lykos on 5/8/18.
//

#include <SFML/Graphics.hpp>
#include <math.h>
#ifndef Collider_hpp
#define Collider_hpp

class Collider{
    
public:
    Collider();
    Collider(sf::RectangleShape& body);
    
    void move(float dx, float dy){body.move(dx,dy); }
    
    bool checkCollision(Collider& other, sf::Vector2f& direction, float push);
    sf::Vector2f GetPostion(){return body.getPosition();}
    sf::Vector2f getHalfSize(){return body.getSize()/2.0f;}
    
    
    
    
private:
    
    sf::RectangleShape& body;
    
    
};

#include <stdio.h>

#endif /* Collider_hpp */
