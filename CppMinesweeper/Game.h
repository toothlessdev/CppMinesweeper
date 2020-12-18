#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
private:
	Map* map;
	int mineSize;
public:
	Game(int mineSize);
	~Game();
	void Play();
};

#endif