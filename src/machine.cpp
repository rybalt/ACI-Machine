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
	generateMpplrXML();
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
			cout << "x: " << x_offset+x*(tile_width) << " y: " << y_offset+y*(tile_height) << "\n";
			tmp->setPosition(x_offset+x*(tile_width), y_offset+y*(tile_height));
			tmp->setWidth(tile_width);
			tmp->setHeight(tile_height);
			
			// original and mapped points array for projection mapping
			float *orig = new float[8];
			float *map = new float[8];

			map[0] = x_offset+x*(tile_buffer+tile_width);
			map[1] = y_offset+y*(tile_buffer+tile_height);
			map[2] = map[0] + tile_width;
			map[3] = map[1];
			map[4] = map[0] + tile_width;
			map[5] = map[1] + tile_height;
			map[6] = map[0];
			map[7] = map[1] + tile_height;
			
			orig[0] = x_offset + x*tile_width;
			orig[1] = y_offset + y*tile_height;
			orig[2] = orig[0] + tile_width;
			orig[3] = orig[1];
			orig[4] = orig[0] + tile_width;
			orig[5] = orig[1] + tile_height;
			orig[6] = orig[0];
			orig[7] = orig[1] + tile_height;

			//screen scaling
			for(int i = 0; i <= 6; i+=2) {
				map[i] = map[i] / width;
				orig[i] = orig[i] / width;
				map[i+1] = map[i+1] / height;
				orig[i+1] = orig[i+1] / height;
			}

			tmp->setOrigPoints(orig);
			tmp->setMappedPoints(map);

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

void Machine::generateMpplrXML() {
	
	ofxXmlSettings xml;
	xml.addTag("TEX");
	xml.addTag("VER");
	xml.addTag("MAGS");
	xml.addTag("MAGV");
	
	xml.pushTag("TEX");
	int tagNum;
	for(auto it = grid.begin(); it != grid.end(); it++) {
		for(auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
			float * val = (*inner_it)->getOrigPoints();

			//  first tri
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[0] , tagNum);
			xml.setValue("PT:Y", (double)val[1] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[2] , tagNum);
			xml.setValue("PT:Y", (double)val[3] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[6] , tagNum);
			xml.setValue("PT:Y", (double)val[7] , tagNum);

			// second tri
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[2] , tagNum);
			xml.setValue("PT:Y", (double)val[3] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[4] , tagNum);
			xml.setValue("PT:Y", (double)val[5] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[6] , tagNum);
			xml.setValue("PT:Y", (double)val[7] , tagNum);
		}
	}
	xml.popTag();
	
	xml.pushTag("VER");
	for(auto it = grid.begin(); it != grid.end(); it++) {
		for(auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
			float * val = (*inner_it)->getMappedPoints();

			//  first tri
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[0] , tagNum);
			xml.setValue("PT:Y", (double)val[1] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[2] , tagNum);
			xml.setValue("PT:Y", (double)val[3] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[6] , tagNum);
			xml.setValue("PT:Y", (double)val[7] , tagNum);

			// second tri
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[2] , tagNum);
			xml.setValue("PT:Y", (double)val[3] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[4] , tagNum);
			xml.setValue("PT:Y", (double)val[5] , tagNum);
		
			tagNum = xml.addTag("PT");
			xml.setValue("PT:X", (double)val[6] , tagNum);
			xml.setValue("PT:Y", (double)val[7] , tagNum);
		}
	}
	xml.popTag();
	/*
	xml.pushTag("MAGS");
	for (int i = 0;i < magnets.size();i++){
		tagNum = xml.addTag("PT");
		xml.setValue("PT:X", (double)magnets[i].x , tagNum);
		xml.setValue("PT:Y", (double)magnets[i].y , tagNum);
	}
	xml.popTag();
	
	xml.pushTag("MAGV");
	for (int i = 0;i < magnetv.size();i++){
		tagNum = xml.addTag("PT");
		xml.setValue("PT:X", (double)magnetv[i].x , tagNum);
		xml.setValue("PT:Y", (double)magnetv[i].y , tagNum);
	}
	xml.popTag();
	*/

	/*
	string str;
	xml.copyXmlToString(str);
	cout << str << endl;
	*/

	// NOTE: this requires the folder 'data' alongside the executable
	xml.saveFile("preset0.xml");
}