//
//  Projectile.hpp
//  CS2A-Project
//
//  Created by Lykos on 5/8/18.
//  Copyright © 2018 Lykos. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collider.hpp"

#ifndef Projectile_hpp
#define Projectile_hpp

class Projectile{
    
public:
    
    Projectile();
    Projectile(sf :: Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    Collider getCollider() {return Collider(body);}
    void onCollision(sf::Vector2f direction);
//    void Draw(sf::RenderWindow& window);
    void Update(float deltaTime,sf::RenderWindow& window);

    
    
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    bool isShot;
    
    sf::Vector2f velocity;
    
    
    
};



#include <stdio.h>

#endif /* Projectile_hpp */
