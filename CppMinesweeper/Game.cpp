#include "Game.h"
#include <iostream>
#include <stdlib.h>

Game::Game(int mineSize) {
	this->mineSize = mineSize;
	map = new Map(mineSize);
	map->AllocateMines();
	map->SetNumbers();
	map->DisplayMap(); // debug
}

Game::~Game() {
	delete this->map;
}

void Game::Play(){
	while(!map->CompleteGame()){
		map->GetInput();
		map->DisplayMap();
		//system("cls");
	}
}
