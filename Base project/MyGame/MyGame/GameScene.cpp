#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"

GameScene::GameScene() {
	ShiPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);
}

