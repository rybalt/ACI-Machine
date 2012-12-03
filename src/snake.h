// base tile class with basic state and rendering functions
#ifndef SNAKE_H
#define SNAKE_H
#include "pixel.h"
#include <vector>
using namespace std;

class Snake {
	
private:
	float x, y, r, g, b, vx, vy, velocity;
	vector<Pixel> pixels;
public:
	Snake() {}
	Snake(float x, float y, float r, float g, float b, float velocity=.5);
	
	void draw();
	void update();
	void changeDirection();
};

#endif