#include "Map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>



Map::Map(int mineSize) {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			map[y][x] = '0';
			isDisplayed[y][x] = DISPLAYED_FALSE;
		}
	}
	srand((unsigned int)time(NULL));
	this->mineSize = mineSize;
	this->leftMines = mineSize;
}

void Map::AllocateMines() {
	int* x = new int[mineSize];
	int* y = new int[mineSize];
	int size = 1;
	x[0] = rand() % SIZE;
	y[0] = rand() % SIZE;

	while (size < mineSize) {
		bool isNew = true;
		int new_x = rand() % SIZE;
		int new_y = rand() % SIZE;

		for (int i = 0; i < mineSize; i++) {
			if (new_x == x[i] && new_y == y[i]) {
				isNew = false;
				continue;
			}
		}
		if (isNew) {
			x[size] = new_x;
			y[size] = new_y;
			size++;
		}
	}
	for (int m = 0; m < mineSize; m++) {
		map[y[m]][x[m]] = '*';
	}
}

void Map::SetNumbers() {
	const int dx[] = { -1,0,1,1,1,0,-1,-1 };
	const int dy[] = { -1,-1,-1,0,1,1,1,0 };
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			for (int dir = 0; dir < 8; dir++) {
				int X = x + dx[dir], Y = y + dy[dir];
				if ((0 <= X && X < SIZE) && (0 <= Y && Y < SIZE)) {
					if (map[Y][X] == '*' && map[y][x] != '*') {
						map[y][x] ++;
					}
				}
			}
		}
	}
}

void Map::DisplayMap() {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			if(isDisplayed[y][x] == DISPLAYED_TRUE){
				std::cout << map[y][x] << ' ';
			}
			else if(isDisplayed[y][x] == DISPLAYED_FALSE){
				std::cout << "□" << ' ';
			}
			else if(isDisplayed[y][x] == DISPLAYED_FLAG){
				std::cout << "ᚹ" << ' ';
			}
		}
		std::cout << '\n';
	}
}

void Map::GetInput(){
	int inputX, inputY;
	std::cout << "작업할 영역을 선택하세요 (X좌표/Y좌표) : ";
	std::cin >> inputX >> inputY;

	if(!isDisplayed[inputY][inputX]){ //확인 하지 않은 칸이면
		int select;
		std::cout << "선택된 영역을 어떻게 하시겠습니까?" << '\n';
		std::cout << "1. 확인한다   2. 깃발을 꽂는다   3. 돌아간다" << '\n';
		std::cin >> select;

		switch(select){
			case 1:
				isDisplayed[inputY][inputX] = DISPLAYED_TRUE;
				break;
			case 2:
				isDisplayed[inputY][inputX] = DISPLAYED_FLAG;
				if(map[inputY][inputX] == '*') this->leftMines--;
				break;
			case 3: break;
		}
	}
	else{
		std::cout << "이미 확인한 영역입니다!" << '\n';
	}
}

bool Map::CompleteGame(){
	return this->leftMines == 0;
}