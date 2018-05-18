#include <SFML/Graphics.hpp>
#include "Collider.hpp"

#ifndef Platform_h
#define Platform_h

class Platform{
	public:
		Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f pos);
		void Draw(sf::RenderWindow& window);
		void scale(float x, float y);
		Collider GetCollider() {return Collider(body);}
	
	private:
		sf::RectangleShape body;
};
#endif
