#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collider.hpp"
#ifndef Enemy_hpp
#define Enemy_hpp

class Enemy{
    private:
        sf::Vector2f velocity;
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        float speed;
        bool alive;
        bool canJump;
    public:
        Enemy();
        Enemy(sf :: Texture* texture, sf::Vector2u image, float jumpHeight);
        behavior();
        onCollision();
        drawEnemy(sf::RenderWindow& window);

};
#include <stdio.h>

#endif /* Enemy_hpp */
