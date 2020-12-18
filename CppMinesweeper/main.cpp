#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>

#include "Map.h"
#include "Game.h"
using namespace std;

void Bfs(int x, int y, Map &map);

int main(void) {
	Game game(12);
	game.Play();

	return 0;
}

/*******************************************************/

void Bfs(int x, int y, Map &map) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
	bool isVisited[SIZE][SIZE] = { false };

	queue<pair<int, int>> bfs;
	
	bfs.push(make_pair(y, x));
	isVisited[y][x] = true;

	while (!bfs.empty()) {
		int x = bfs.front().second;
		int y = bfs.front().first;

		for (int dir = 0; dir < 4; dir++) {
			int X = x + dx[dir];
			int Y = y + dy[dir];
			if ((0 <= X && X < SIZE) && (0 <= Y && Y < SIZE)) {
				if(!isVisited[Y][X] && )
			}
		}
		bfs.pop();
	}
}