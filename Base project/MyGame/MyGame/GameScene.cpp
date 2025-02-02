#include "GameScene.h"
#include "GameOverScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "ScrollingBakcround.h"

GameScene::GameScene() {
	ScrollingBackroundPtr scrollingBackround = std::make_shared<ScrollingBackround>();
	addGameObject(scrollingBackround);

	ShiPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
}

int GameScene::getScore() {
	return score_;
}

void GameScene::increaseScore() {
	++score_;
}

int GameScene::getLives() {
	return lives_;
}

void GameScene::decreaseLives() {
	--lives_;

	if (lives_ == 0) {
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}