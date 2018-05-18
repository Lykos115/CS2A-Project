//
//  Player.hpp
//  2Atest
//
//  Created by Lykos on 5/8/18.
//  Copyright © 2018 Lykos. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collider.hpp"
#include <math.h>
#ifndef Player_hpp
#define Player_hpp

class Player {
    
public:
    
    Player();
    Player(sf :: Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
	void onCollision(sf::Vector2f direction);
    Collider getCollider() {return Collider(body);}
    sf::Vector2f getPosition() {return body.getPosition();}    

private:
    
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    
    sf::Vector2f velocity;
    bool canJump = true;
    float jumpHeight;
    
    
};

#include <stdio.h>

#endif /* Player_hpp */
