#ifndef MAP_H
#define MAP_H
#define SIZE 9
#include <vector>

extern void Bfs(int x, int y, bool isVisited[SIZE][SIZE]);

enum DISPLAY_TYPE {
	DISPLAYED_FLAG = -1,
	DISPLAYED_FALSE = 0,
	DISPLAYED_TRUE = 1
};

class Map {
private:
	int mineSize;
	int leftMines;
	char map[SIZE][SIZE];
	DISPLAY_TYPE isDisplayed[SIZE][SIZE];
public:
	Map(int mineSize);
	void AllocateMines();
	void SetNumbers();
	void DisplayMap();
	
	void GetInput();
	bool CompleteGame();

	friend void Bfs(int x, int y);
};

#endif