#include"Enemy.h"

Enemy::Enemy(){



}

Enemy::Enemy(sf :: Texture* texture, sf::Vector2u image, bool alive, float speed, float jumpHeight){
    this -> jumpHeight = jumpHeight;
    this -> alive = alive;
    this -> speed = speed;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setTexture(texture);
}

void Enemy::behavior(float deltaTime){
	if(alive){
        int x = (rand() % 3)+1;
    	if(x == 1)
        	velocity.x -= speed;
    	else if(x == 2){
        	velocity.x += speed;
		}
    	else{
			canJump = false;
        	velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
		}	
	}
	
	velocity.y -= 981.0f * deltaTime;

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
