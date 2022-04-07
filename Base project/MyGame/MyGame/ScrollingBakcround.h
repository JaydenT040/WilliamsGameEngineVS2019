#pragma once
#include "Engine/GameEngine.h"

class ScrollingBackround : public GameObject
{
public:
	ScrollingBackround(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<ScrollingBackround> ScrollingBackroundPtr;