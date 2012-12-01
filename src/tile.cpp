#include "tile.h"
#include "ofGraphics.h"

void DummyTile::render(){
	ofSetColor(1,0,1);
	ofRect(pos,width,height);
}