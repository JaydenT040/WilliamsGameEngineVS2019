#include "ScrollingBakcround.h"
#include <iostream>

const float Speed = 0.1f;

ScrollingBackround::ScrollingBackround() {
	sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f);
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite2_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(pos);
	sf::Vector2f pos2 = sf::Vector2f(sprite_.getGlobalBounds().width, pos.y);
	//pos2.x += sprite_.getGlobalBounds().width;
	sprite2_.setPosition(pos2);
}

void ScrollingBackround::draw() {
	GAME.getRenderWindow().draw(sprite_);
	GAME.getRenderWindow().draw(sprite2_);

}

void ScrollingBackround::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	std::cout << "s1: " << pos.x;
	if (pos.x <= sprite_.getGlobalBounds().width * -1) { 
		pos.x = sprite_.getGlobalBounds().width;
		sprite_.setPosition(pos);
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - Speed * msElapsed, pos.y));
	}
	
	sf::Vector2f pos2 = sprite2_.getPosition();
	std::cout << " s2: " << pos2.x << '\n';


	if (pos2.x <= sprite2_.getGlobalBounds().width * -1) {
		pos2.x = sprite2_.getGlobalBounds().width;
		sprite2_.setPosition(pos2);
	}
	else {
		sprite2_.setPosition(sf::Vector2f(pos2.x - Speed * msElapsed, pos2.y));
	}
}