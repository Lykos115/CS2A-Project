//
//  Projectile.hpp
//  CS2A-Project
//
//  Created by Lykos on 5/3/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include "Entity.hpp"

class Projectile : public Entity{
    
public:
    
    Projectile();
    Projectile(sf::Sprite sprite);
    
    
    
protected:
    int counter = 0;
    int AD = 0;
    int direction = 1;
    
};

#include <stdio.h>

#endif /* Projectile_hpp */
