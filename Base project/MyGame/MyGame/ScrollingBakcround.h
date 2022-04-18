#pragma once
#include "Engine/GameEngine.h"

class ScrollingBackround : public GameObject
{
public:
	ScrollingBackround();
	//ScrollingBackround(sf::Vector2f pos);

	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	sf::Sprite sprite2_;
	int time = 0;
};

typedef std::shared_ptr<ScrollingBackround> ScrollingBackroundPtr;