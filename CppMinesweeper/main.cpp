#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>

#include "Map.h"


using namespace std;

void Bfs(int x, int y, bool isVisited[SIZE][SIZE]);

int main(void) {
	Map map(15);
	
	map.AllocateMines();
	map.DisplayMap();

	return 0;
}


void Bfs(int x, int y, bool isVisited[SIZE][SIZE]) {
	const int dx[] = { 1,-1,0,0 };
	const int dy[] = { 0,0,1,-1 };
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

			}
		}
	}
}