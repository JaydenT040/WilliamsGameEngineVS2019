#include "Explosion.h"

Explosion::Explosion(sf::Vector2f pos) : AnimatedSprite(pos) {
	AnimatedSprite::setTexture(GAME.getTexture("Resources/explosion-spritesheet.png"));
	SetUpExplosioinAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);
}