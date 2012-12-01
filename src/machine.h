// machine class that generates and holds the grid of tiles to be projected
#ifndef MACHINE_H
#define MACHINE_H
#include "tile.h"
#include <vector>
using namespace std;

class Machine {
private:
	double x_offset, y_offset, width, height, tile_buffer, tile_width, tile_height;
	int grid_width, grid_height;
	vector< vector<Tile*> > grid;
public:
	Machine(double x_offset, double y_offset, double width, double height, double tile_buffer, int grid_width, int grid_height);
	
	Machine(){}

	//fills the machine grid with dummy tiles
	void fillWithDummy();

	//sets a tile in the grid at x,y to be tile_arg
	void setTile(int x, int y, Tile * tile_arg);

	//draws all the tiles in the grid
	void drawAll();

};

#endif