//
//  Player.cpp
//  2Atest
//
//  Created by Lykos on 5/8/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include "Player.hpp"
Player :: Player(){
    
    
    
    
}


Player :: Player(sf :: Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(texture, imageCount, switchTime){
    
    this -> speed = speed;
    this -> jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
    
}

void Player::Update(float deltaTime){
    
    velocity.x *= 0.0f;
    
    sf::Vector2f movement(0.0f, 0.0f);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed;
    }
    
    if (sf::Keyboard:: isKeyPressed(sf::Keyboard::Up) && canJump) {
        canJump = false;
        
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight); //sqrt
    }
    
//    velocity.y +=981.0f * deltaTime;
    
    
    
    
    if (velocity.x == 0.0f) {
        row = 0;
    } else {
        row = 1;
        
        if (velocity.x > 0.0f) {
            faceRight = true;
        } else {
            faceRight = false;
        }
    }
//    if (velocity.y == 0.0f) {
//        row = 0;
//    } else {
//        row = 2;
//    }
    
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
    
}

void Player::Draw(sf::RenderWindow& window){
    
    window.draw(body);
}

void Player::onCollision(sf::Vector2f direction){
    
    if (direction.x < 0.0f) {
        velocity.x = 0.0f;
    } else if (direction.x > 0.0f){
        
        velocity.x = 0.0f;
    }
    
    if (direction.y < 0.0f) {
        
        velocity.y = 0.0f;
        canJump = true;
        
    } else if(direction.y > 0.0f){
        
        velocity.y = 0.0f;
    }
    
}






