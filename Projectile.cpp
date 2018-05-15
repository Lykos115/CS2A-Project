//
//  Projectile.cpp
//  CS2A-Project
//
//  Created by Lykos on 5/8/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include "Projectile.hpp"

Projectile :: Projectile(sf :: Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime) {
    
    this -> speed = speed;
    row = 3;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
    
}
//void Projectile::Draw(sf::RenderWindow& window){
//
//    window.draw(body);
//}

void Projectile::Update(float deltaTime,sf::RenderWindow& window){
    
    velocity.x *= 0.0f;
    
    sf::Vector2f movement(0.0f, 0.0f);
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        window.draw(body);
        velocity.x += speed;
    }
    animation.update(row, deltaTime, true);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}
