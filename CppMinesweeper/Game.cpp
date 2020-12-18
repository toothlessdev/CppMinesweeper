#include "Game.h"

Game::Game(int mapX, int mapY, int mineSize) {
	this->mapX = mapX;
	this->mapY = mapY;
	this->mineSize = mineSize;
	map = new Map(mineSize);
}

Game::~Game() {
	delete this->map;
}