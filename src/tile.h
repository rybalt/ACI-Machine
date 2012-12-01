// base tile class with basic state and rendering functions
#include "ofPoint.h"
#ifndef TILE_H
#define TILE_H

class Tile {
	
public:
	//Constructors
	Tile(double x, double y, double w, double h):pos(x,y),width(w),height(h){}
	Tile(ofPoint p, double w, double h):pos(p),width(w),height(h){}
	Tile(){};
	
public:
	//Other functions
	virtual void render()=0;
	
public:
	//getters
	ofPoint getPosition() const {return pos;}
	ofPoint getWidth() const{return width;}
	ofPoint getHeight() const{return height;}

	//setters
	void setPosition(double x, double y);
	void setWidth(double w);
	void setHeight(double h);
	
public:
	~Tile(){}
	
protected:
	ofPoint pos;
	double width;
	double height;
};

class DummyTile: public Tile{
public:
	DummyTile(double x, double y, double w, double h):Tile(x,y,w,h){}
	DummyTile() {}
	void render();
};

#endif