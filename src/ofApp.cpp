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
	serial.setup("COM12", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
	bool filter = true; // to see the data is correct (will create filter function to check the datas tring)
	unsigned char sbyte[45];
	serial.readBytes(sbyte, 45);
	int temp,_xByte,_yByte,_zByte,j=0;
	for (int i = 0; sbyte[i] != '!'; i++) {
		if (sbyte[i] == ',') {
			temp = sbyte[i - 1] + sbyte[i - 2] - '0' - '0';
		}
		if (sbyte[i] == ',' || sbyte[i] == '!') {
			j++;
			if (j % 3 == 0) {
				_zByte = temp;
				data[(j / 3)].setData(_xByte, _yByte, _zByte);
			}
			else if (j % 3 == 2)
				_yByte = temp;
			else
				_xByte = temp;
		}
	}

	//int ibyte = sbyte - '0';
	//data[0].setData(ibyte, ibyte, ibyte);

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
