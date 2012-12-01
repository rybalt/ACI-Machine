// base tile class with basic state and rendering functions
#include "ofPoint.h"

class Tile {
	
public:
	virtual void render()=0;
	
public:
	//getters
	ofPoint getPosition() const {return pos;}
	ofPoint getWidth() const{return width;}
	ofPoint getHeight() const{return height;}
	
public:
	~Tile(){}
	
private:
	ofPoint pos;
	double width;
	double height;
};

class DummyTile: public Tile{
	void render(){return;}
};