#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
private:
	Map* map;
	int mapX, mapY;
	int mineSize;
public:
	Game(int mapX, int mapY, int mineSize);
	~Game();
};

#endif