#include "Meteor.h"
#include "GameScene.h"
#include <iostream>
const float SPEED = 0.25f;
Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("laser")) {
		otherGameObject.makeDead();
		sf::Vector2f pos = sprite_.getPosition();
		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(pos.x, pos.y + sprite_.getGlobalBounds().height / 2));
		//GAME.getCurrentScene().addGameObject(explosion);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.addGameObject(explosion);
		scene.increaseScore();
	}

	makeDead();
}