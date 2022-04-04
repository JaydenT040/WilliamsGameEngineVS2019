#pragma once

#include "Engine/GameEngine.h"

class Explosion : public AnimatedSprite {
public:
	//Creates explosion
	Explosion(sf::Vector2f pos);

	//Functions ovveridden from GameObj
	void update(sf::Time& elapsed);
private:
	void SetUpExplosioinAnimation();
};

typedef std::shared_ptr<Explosion> ExplosionPtr;