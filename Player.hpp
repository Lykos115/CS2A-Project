//
//  Player.hpp
//  CS2A-Project
//
//  Created by Lykos on 4/25/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include "Entity.hpp"

class Player : public Entity{

public:
    
    Player();
    Player(sf::Sprite sprite);
    void update();
    void updateMovement();
    
    
    
private:
    int counter = 0;
    int fallCounter = 0;
    
};

#include <stdio.h>

#endif /* Player_hpp */
