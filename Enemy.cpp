#include"Enemy.h"

Enemy::Enemy(){



}

Enemy::Enemy(sf :: Texture* texture, sf::Vector2u image, bool alive, float speed,float jumpHeight){
    this -> jumpHeight = jumpHeight;
    this -> alive = alive;
    this -> speed = speed;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(306.0f, 206.0f);
    body.setTexture(texture);
}

void Enemy::behavior(float deltaTime){
    if(alive){
        int x = (rand() % 3)+1;
    if(x == 1)
        velocity.x -= speed;
    if(x == 2)
        velocity.x += speed;
    if(x == 3 && canJump)
        canJump = false;
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
        }

    body.move(velocity * deltaTime);
}

//Enemy::onCollision(){
//if (direction.x < 0.0f) {
//        velocity.x = 0.0f;
//    } else if (direction.x > 0.0f){
//
//        velocity.x = 0.0f;
//    }
//
//    if (direction.y < 0.0f) {
//        canJump = true;
//        velocity.y = 0.0f;
//    } else if(direction.y > 0.0f){
//
//        velocity.y = 0.0f;
//    }
//}

void Enemy::drawEnemy(sf::RenderWindow& window){

    window.draw(body);
}
