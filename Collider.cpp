//
//  Collider.cpp
//  
//
//  Created by Lykos on 5/8/18.
//

#include "Collider.hpp"

Collider :: Collider():body(body){
    
    
}

Collider :: Collider(sf::RectangleShape& body):body(body){
    
    
    
}

bool Collider:: checkCollision(Collider &other,sf::Vector2f& direction, float push){
    
    sf::Vector2f otherPosition = other.GetPostion();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    
    sf::Vector2f thisPosition = GetPostion();
    sf::Vector2f thisHalfSize = getHalfSize();
    
    int deltaX = otherPosition.x - thisPosition.x; // float
    int deltaY = otherPosition.y - thisPosition.y; // float
    
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    
    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f);
        
        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                move(intersectX*(1.0f - push), 0.0f);
                other.move(-intersectX * push, 0.0f);
                
                direction.x = 1.0f;
                direction.y = 0.0f;
                
            } else {
                move(-intersectX*(1.0f - push), 0.0f);
                other.move(intersectX * push, 0.0f);
                
                direction.x = -1.0f;
                direction.y = 0.0f;
                
            }
        } else {
            
            if (deltaY > 0.0f) {
                move(0.0f,intersectY*(1.0f - push));
                other.move(0.0f,-intersectY * push);
                
                direction.x = 0.0f;
                direction.y = 1.0f;
                
            } else {
                move(0.0f,-intersectY*(1.0f - push));
                other.move(0.0f,intersectY * push);
                
                direction.x = 0.0f;
                direction.y = -1.0f;
                
            }

            
            
        }
        return true;
    }
    
    return false;
    
}
