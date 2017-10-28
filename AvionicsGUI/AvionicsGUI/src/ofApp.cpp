#include "ofApp.h"
int const dataCount = 5;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

	data = new DataBox[dataCount];

	/*initialize all data boxes*/
	string dataNames[5] = { "Position", "Velocity", "Acceleration", "Altitude", "Temperature" };
	for (int i = 0; i < dataCount; i++)
	{
		data[i].set(200, 100, ofGetWidth()/2, 105*(i+1), 30, 30, 30);	//load to the left side
		data[i].setOpen(true);
		data[i].setName(dataNames[i]);
		data[i].loadFont("Exo-Light.otf", 20);
	}
	serial.setup("COM4", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
	char sbyte = serial.readByte();
	int ibyte = sbyte - '0';
	data[1].setData(ibyte, ibyte, ibyte);

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < dataCount; i++)
	{
		data[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mouseX = x;
	mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
