#include "testApp.h"
#include "machine.h"

//--------------------------------------------------------------
void testApp::setup(){
	cout << "running setup\n";
	m = Machine(0,0, 640, 480, 20, 10, 10);
	cout << "machine created\n";

	// projection buffer should come after machine is created
	buf.setup(1000,1000);
	con.setup(&buf);
	buf.LoadXML(0);
}

//--------------------------------------------------------------
void testApp::update(){
	m.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	buf.Begin();
	ofBackground(1,1,1);
	m.drawAll();
	buf.End();

	ofSetHexColor(0xFFFFFF);
	ofBackground(0, 0, 0);

	//Sub Display out
	buf.draw(1440,0, 640, 480);
	
	//Monitor out
	buf.draw(640, 0, 640, 480);
	
	//Source out
	buf.drawBuffer(0, 0, 640, 480);
	
	//draw ofxMpplrController
	con.draw(50, 500);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}