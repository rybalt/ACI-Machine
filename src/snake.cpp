#include "snake.h"
#include "pixel.h"
#include "ofGraphics.h"
#include <random>

// initializes a snake with position, color, and velocity
Snake::Snake(float x_, float y_, float r_, float g_, float b_, float velocity_){
	x = x_; y = y_; r = r_; g = g_; b = b_; velocity = velocity_;
	vx=0;
	vy=0;
	changeDirection();
}

//randomly picks a direction to move in
void Snake::changeDirection() {
	vx=0;
	vy=0;
	switch(rand()%4) {
	case 0:
		vx=velocity;
		break;
	case 1:
		vx=-velocity;
		break;
	case 2:
		vy=velocity;
		break;
	case 3:
		vy=-velocity;
		break;
	}
}

//moves the snake, making a trail of Pixels along the way
void Snake::update() {

	if(rand()%100==0) {
		changeDirection();
	}
	
	if(x<0)
		vx=velocity;
	if(y<0)
		vy=velocity;
	if(x>1000)
		vx=-velocity;
	if(y>1000)
		vy=-velocity;

	for(auto it = pixels.begin(); it != pixels.end(); it++) {
		it->update();
		it->fade();
	}
	x+=vx;
	y+=vy;
	pixels.push_back(Pixel(x,y,r,g,b));
	if(pixels.size() > 100) {
		pixels.erase(pixels.begin(), pixels.begin()+1);
	}
}

void Snake::draw() {
	for(auto it = pixels.begin(); it != pixels.end(); it++) {
		it->draw();
	}
}