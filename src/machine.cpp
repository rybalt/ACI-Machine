#include "machine.h"
#include "snake.h"

Machine::Machine(float x_offset_, float y_offset_, float width_, float height_, float tile_buffer_, int grid_width_, int grid_height_) {

	//drawing dimensions of overall machine
	x_offset = x_offset_;
	y_offset = y_offset_;
	width = width_;
	height = height_;

	//space between tiles
	tile_buffer = tile_buffer_;

	//number of elements in the grid along width and height
	grid_width = grid_width_;
	grid_height = grid_height_;
	
	// determine size of a single tile by removing buffer space from machine size and dividing whats left
	tile_width  = (width -  (tile_buffer * grid_width-1))  / grid_width;
	tile_height = (height - (tile_buffer * grid_height-1)) / grid_height;
	
	cout << "tile_height " << tile_height; 
	cout << "tile_width " << tile_width; 

	frame_skip=0;

	fillWithDummy();
	generateSnakes(10);
}

// fills the machine with a grid of dummy tiles
void Machine::fillWithDummy() {

	// loop for each row
	for(int y = 0; y < grid_height; y++) {
		vector<Tile*> row;

		//loop for each element in the row
		for(int x = 0; x < grid_width; x++) {
			Tile * tmp = new DummyTile;
			cout << "x: " << x_offset+x*(tile_buffer+tile_width) << " y: " << y_offset+y*(tile_buffer+tile_height) << "\n";
			tmp->setPosition(x_offset+x*(tile_buffer+tile_width), y_offset+y*(tile_buffer+tile_height));
			tmp->setWidth(tile_width);
			tmp->setHeight(tile_height);
			row.push_back(tmp);
		}
		cout << "row size: " << row.size() << "\n";
		grid.push_back(row);
	}
	cout << "grid size" << grid.size();
}

//sets a tile in the grid at x,y to be tile_arg
void Machine::setTile(int x, int y, Tile * tile_arg) {
	grid[x][y] = tile_arg;
}

void Machine::generateSnakes(int count) {
	for(int i = 0; i < count; i++) {
		snakes.push_back(Snake(rand()%1000,rand()%1000,0,0,255,2.5));
	}
}

//machine update, updates contained snakes
void Machine::update() {
	frame_skip-=1;
	if(frame_skip <=0) {
		frame_skip = 10;
		for(auto it = snakes.begin(); it != snakes.end(); it++) {
			it->update();
		}
	}
}

//draws all the tiles in the grid
void Machine::drawAll() {
	for(auto it = grid.begin(); it != grid.end(); it++) {
		for(auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
			(*inner_it)->render();
		}
	}
	
	for(auto it = snakes.begin(); it != snakes.end(); it++) {
		it->draw();
	}
}