// machine class that generates and holds the grid of tiles to be projected
#ifndef MACHINE_H
#define MACHINE_H
#include "tile.h"
#include "snake.h"
#include <vector>
using namespace std;

class Machine {
private:
	float x_offset, y_offset, width, height, tile_buffer, tile_width, tile_height;
	int grid_width, grid_height;
	int frame_skip;
	vector< vector<Tile*> > grid;
	vector< Snake > snakes;
public:
	Machine(float x_offset, float y_offset, float width, float height, float tile_buffer, int grid_width, int grid_height);
	
	Machine(){}

	void update();

	//fills the machine grid with dummy tiles
	void fillWithDummy();

	//sets a tile in the grid at x,y to be tile_arg
	void setTile(int x, int y, Tile * tile_arg);

	//generates snakes/tron light cycles line effect overlay
	void generateSnakes(int count);

	//draws all the tiles in the grid
	void drawAll();

};

#endif