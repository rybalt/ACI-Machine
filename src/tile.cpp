#include "tile.h"
#include "ofGraphics.h"

void DummyTile::render(){
	ofSetColor(255,255,255);
	ofRect(pos,width,height);
}

void Tile::setPosition(float x, float y) {
	pos = ofPoint(x,y);
}

void Tile::setWidth(float w) {
	width = w;
}

void Tile::setHeight(float h) {
	height = h;
}