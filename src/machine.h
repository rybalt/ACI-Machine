// machine class that generates and holds the grid of tiles to be projected
#include "tile.h"
#include <vector>
using namespace std;

class Machine {
private:
	float x_offset, y_offset, width, height, tile_buffer, tile_width, tile_height;
	int grid_width, grid_height;
	vector<vector<Tile*>> grid;
public:
	Machine(float x_offset, float y_offset, float width, float height, float tile_buffer, int grid_width, int grid_height);
	void fillWithDummy();

};