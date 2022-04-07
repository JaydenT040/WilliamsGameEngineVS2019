#pragma once
#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	//creates the gameover message instance
	GameOverMessage(int score);
	//Functions ovveriden from GameObj
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;
};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;