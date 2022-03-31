#pragma once
#include "Engine/Game.h"

class Ship : public GameObject
{
public:
	//makes the ship
	Ship();

	//Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
};

typedef std::shared_ptr<Ship> ShiPtr;