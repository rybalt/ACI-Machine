#include "pixel.h"
#include "ofGraphics.h"

Pixel::Pixel(float x_, float y_, float r_, float g_, float b_){
	x = x_; y = y_; r = r_; g = g_; b = b_;
}

void Pixel::update() {

}

//fades linearly to black
void Pixel::fade() {
	r-=1;
	g-=1;
	b-=1;
}

void Pixel::draw() {
	ofSetColor(r,g,b);
	ofRect(x,y,0,8,8);
}