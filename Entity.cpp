//
//  Entity.cpp
//  CS2A-Project
//
//  Created by Lykos on 4/25/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include "Entity.hpp"

Entity :: Entity(){
    
    
    
}

Entity :: Entity(sf::RectangleShape rect, sf::Sprite sprite, sf::Text text){
    
    this->rect = rect;
    this->sprite = sprite;
    this->text = text;
    
    
}
