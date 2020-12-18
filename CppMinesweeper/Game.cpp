#include "Game.h"
#include <iostream>

Game::Game(int mineSize) {
	this->mineSize = mineSize;
	map = new Map(mineSize);
	map->AllocateMines();
	map->SetNumbers();
	map->DisplayMap(); // debug

	for(int y = 0 ; y < SIZE; y++){
		for(int x = 0 ; x < SIZE; x++){
			isDisplayed[y][x] = false;
		}
	}
}

Game::~Game() {
	delete this->map;
}

void Game::play(){
	this->GetKeyboardInput();
}

void Game::GetKeyboardInput(){
	int inputX, inputY;
	std::cout << "작업할 영역을 선택하세요 (X좌표/Y좌표) : ";
	std::cin >> inputX >> inputY;

	if(!isDisplayed[inputY][inputX]){ //확인 하지 않은 칸이면
		int select;
		std::cout << "선택된 영역을 어떻게 하시겠습니까?" << '\n';
		std::cout << "1. 확인한다   2. 깃발을 꽃는다   3. 돌아간다<< '\n';
		std::cin >> select;

		if(is)
	}
	else{
		std::cout << "이미 확인했던 칸입니다!" << '\n';
	}
}