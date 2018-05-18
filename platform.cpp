#include "platform.hpp"

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f pos){
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(pos);
	body.setTexture(texture);

}

void Platform::Draw(sf::RenderWindow& window){
	window.draw(body);
}

void Platform::scale(float x, float y){
	body.setScale(x,y);
}
