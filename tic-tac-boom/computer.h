typedef struct Game {
	char turn;
	char** grid;
	bool explodeX;
	bool explodeO;
	int gridWidth;
	int gridHeight;
} Game;