//
//  Player.cpp
//  CS2A-Project
//
//  Created by Lykos on 4/25/18.
//  Copyright © 2018 Lykos. All rights reserved.
//

#include "Player.hpp"

Player :: Player(sf::Sprite sprite){
    
    this->sprite = sprite;
    rect.setPosition(400, 400);
    
}

void Player::update(){
    
    
    sprite.setPosition(rect.getPosition());
    sprite.setTextureRect(sf::IntRect(0,80,70,100));
    
}

void Player::updateMovement(){
    int ground = rect.getPosition().y;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                rect.move(1,0);
//                if (counter < 0) {
//                    sprite.setTextureRect(sf::IntRect(0,80,70,100));
//                    counter++;
//                } else
                 if (counter < 50){
                    sprite.setTextureRect(sf::IntRect(70,100,80,100));
                    counter++;
                }else if(counter < 100){
                    sprite.setTextureRect(sf::IntRect(155,100,60,90));
                    counter++;
                }else if(counter < 150){
                    sprite.setTextureRect(sf::IntRect(207,100,90,90));
                    counter++;
    
                } else if(counter < 200) {
                    
                    counter = 0;
                }
            } else{
                sprite.setTextureRect(sf::IntRect(0,80,70,100));
            }
    
    
    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                
                rect.move(0,-1);
                if (jumpCounter < 50){
                    sprite.setTextureRect(sf::IntRect(0,180,100,100));
                    rect.setPosition(rect.getPosition().x, rect.getPosition().y);
                    jumpCounter++;
                    //                        cout << rect.getPosition().y << endl;
                }else if(jumpCounter < 100){
                    sprite.setTextureRect(sf::IntRect(92,170,86,105));
                    rect.setPosition(rect.getPosition().x, rect.getPosition().y);
                    
                    jumpCounter++;
                    //                        cout << rect.getPosition().y << endl;
                } else if (jumpCounter == 100){
                    sprite.setTextureRect(sf::IntRect(175,175,75,150));
                    fallCounter = rect.getPosition().y;
                    
                }
                cout << jumpCounter << endl;
                
                while (fallCounter > 0 && rect.getPosition().y < 400) {
                    if (fallCounter >= 100) {
                        sprite.setTextureRect(sf::IntRect(175,175,75,150));
                        rect.setPosition(rect.getPosition().x+.25, rect.getPosition().y + 1);
                        fallCounter--;
                    } else if (fallCounter >= 50){
                        sprite.setTextureRect(sf::IntRect(250,200,80,100));
                        rect.setPosition(rect.getPosition().x+.25, rect.getPosition().y + 1);
                        fallCounter--;
                    }


                }
                
                if (rect.getPosition().y == 400) {
                    jumpCounter = 0;
                    fallCounter = 0;
                }
                
                
            }
    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                rect.move(0, 1);
    
    
            }
    
    
            // should not be included in final product    //
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                rect.move(-1,0);
            
            }
    
            //                                          //
    
    
}
