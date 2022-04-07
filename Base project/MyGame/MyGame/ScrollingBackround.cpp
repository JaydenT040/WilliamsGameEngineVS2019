#include "ScrollingBakcround.h"

const float Speed = 0.1f;

ScrollingBackround::ScrollingBackround(sf::Vector2f pos) {
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(pos);
	assignTag("background");
}

void ScrollingBackround::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void ScrollingBackround::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	//MAKE IT SO IT ONLY KILLS IF THE RIGHT MOST PART IS TOUCHING
	if (pos.x < sprite_.getGlobalBounds().width * -1) { 
		makeDead();
		ScrollingBackroundPtr scrollingBackround = std::make_shared<ScrollingBackround>(sf::Vector2f());
		GAME.getCurrentScene().addGameObject(scrollingBackround);
	}
	else {
		sprite_.setPosition(sf::Vector2f(pos.x - Speed * msElapsed, pos.y));
	}
}