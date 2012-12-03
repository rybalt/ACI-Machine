// base tile class with basic state and rendering functions
#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
	
private:
	float x, y, r, g, b;

public:
	Pixel() {}
	Pixel(float x, float y, float r, float g, float b);
	
	void draw();
	void update();
	void fade();
};

#endif