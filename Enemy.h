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
    	float jumpHeight;
    	bool alive;
    	bool canJump;

	public:
    	Enemy();
    	Enemy(sf :: Texture* texture, sf::Vector2u image, bool alive, float speed, float jumpHeight);
    	void place(sf::Vector2f pos) {body.setPosition(pos);}
		void behavior(float deltaTime);
		Collider getCollider() {return Collider(body);}
		sf::Vector2f getPosition() {return body.getPosition();}
    	void drawEnemy(sf::RenderWindow& window);

};
#include <stdio.h>

#endif /* Enemy_hpp */
