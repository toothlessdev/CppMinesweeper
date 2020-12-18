#ifndef MAP_H
#define MAP_H
#define SIZE 9

class Map {
private:
	int mineSize;
	char map[SIZE][SIZE];
public:
	Map(int mineSize);
	void AllocateMines();
	void SetNumbers();
	void DisplayMap();
};

#endif