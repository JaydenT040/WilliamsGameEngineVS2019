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
	sf::Sound boom_;
};

typedef std::shared_ptr<Explosion> ExplosionPtr;