#include "tile.h"
#include "ofGraphics.h"

void DummyTile::render(){
	ofSetColor(255,0,255);
	ofRect(pos,width,height);
}

void Tile::setPosition(double x, double y) {
	pos = ofPoint(x,y);
}

void Tile::setWidth(double w) {
	width = w;
}

void Tile::setHeight(double h) {
	height = h;
}