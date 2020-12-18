#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
private:
	Map* map;
	int mineSize;
	bool isDisplayed[SIZE][SIZE];
public:
	Game(int mineSize);
	~Game();

	void play();
	void GetKeyboardInput();
	
};

#endif