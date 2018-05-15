//
//  Animation.hpp
//  2Atest
//
//  Created by Lykos on 5/8/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include <SFML/Graphics.hpp>
#ifndef Animation_hpp
#define Animation_hpp

class Animation{
    
public:
    
    Animation();
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    
    void update(int row, float deltaTime, bool faceRight);
    
    
    
    sf::IntRect uvRect;
    
    
    
    
private:
    
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    
    float totalTime;
    float switchTime;
    
};




#include <stdio.h>

#endif /* Animation_hpp */
