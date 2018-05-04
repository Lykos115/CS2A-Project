//
//  Projectile.cpp
//  CS2A-Project
//
//  Created by Lykos on 5/3/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include "Projectile.hpp"

Projectile :: Projectile(){
    
    rect.setSize(sf::Vector2f(10,10));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Red);
//    sprite.setTextureRect(sf::IntRect(0,0,200,200));
    
    
}
