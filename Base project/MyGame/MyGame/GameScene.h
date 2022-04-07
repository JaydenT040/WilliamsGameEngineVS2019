#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();

  //Gets current score
  int getScore();

  //Increases the score
  void increaseScore();

  //Get lives
  int getLives();

  //Decrase lives
  void decreaseLives();
   
private:
	int score_ = 0;
	int lives_ = 3;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
