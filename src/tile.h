// base tile class with basic state and rendering functions
#ifndef TILE_H
#define TILE_H

#include "ofPoint.h"
#include "tile.h"


class Tile {
	
public:
	//Constructors
	Tile(float x, float y, float w, float h):pos(x,y),width(w),height(h){}
	Tile(ofPoint p, float w, float h):pos(p),width(w),height(h){}
	Tile(){};
	
public:
	//Other functions
	virtual void render()=0;
	
public:
	//getters
	ofPoint getPosition() const {return pos;}
	ofPoint getWidth() const{return width;}
	ofPoint getHeight() const{return height;}
	
	float * getOrigPoints() const{return origPoints;}
	float * getMappedPoints() const{return mappedPoints;}

	//setters
	void setPosition(float x, float y);
	void setWidth(float w);
	void setHeight(float h);
	void setOrigPoints(float * orig);
	void setMappedPoints(float * mapped);
	
public:
	~Tile(){}
	
protected:
	ofPoint pos;
	float width;
	float height;
	float * origPoints;
	float * mappedPoints;
};

class DummyTile: public Tile{
public:
	DummyTile(float x, float y, float w, float h):Tile(x,y,w,h){}
	DummyTile() {}
	void render();
};

#endif