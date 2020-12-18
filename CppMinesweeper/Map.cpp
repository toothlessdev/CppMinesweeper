#include "Map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Map::Map(int mineSize) {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			map[y][x] = '0';
		}
	}
	srand((unsigned int)time(NULL));
	this->mineSize = mineSize;
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
			std::cout << map[y][x] << "  ";
		}
		std::cout << '\n';
	}
}