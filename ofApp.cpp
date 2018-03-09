#include "ofApp.h"

int const dataCount =6;
int const dataLength = 111; // length of string in serial
ofstream myFile;

//--------------------------------------------------------------
void ofApp::setup(){
	
	myFile.open("Data.csv");
	myFile.clear();
	myFile << "Accelaration,Altitude,Temprature,Pressure,Events\n";
	
	ofBackground(0, 0, 0);

	data = new DataBox[dataCount];

	/*initialize all data boxes*/
	string dataNames[dataCount] = { "Accelaration", "Altitude", "Temprature", "Pressure", "Longitude", "Latitude"};//  WORK AFTER THAT
	for (int i = 0; i < dataCount; i++)
	{
		data[i].set(200, 100, ofGetWidth()/2, 105*(i+1), 30);	//load to the left side
		data[i].setOpen(true);
		data[i].setName(dataNames[i]);
		data[i].loadFont("Exo-Light.otf", 20);
	}
	serial.setup("COM12", 9600);
}

//--------------------------------------------------------------
/*void parsData(DataBox data[], double val, int counter) {
	if (counter % 3 == 0) {
		data[static_cast<int>(counter / 3)].setX(val);
	}
	else if (counter % 3 == 1) {
		data[static_cast<int>(counter / 3)].setY(val);
	}
	else if (counter % 3 == 2) {
		data[static_cast<int>(counter / 3)].setZ(val);
	}

}*/

void ofApp::update() {
	//bool filter = true; // to see the data is correct (will create filter function to check the datas tring)
	unsigned char test;
	test = serial.readByte();
	if (test == '#') {
		int bytesRequired = dataLength;
		unsigned char sbyte[dataLength];
		int bytesRemaining = bytesRequired;
		while (bytesRemaining > 0) {
			// check for data
			if (serial.available() > 0) {

				// try to read - note offset into the bytes[] array, this is so
				// that we don't overwrite the bytes we already have
				int bytesArrayOffset = bytesRequired - bytesRemaining;
				int result = serial.readBytes(&sbyte[bytesArrayOffset],
					bytesRemaining);

				// check for error code
				if (result == OF_SERIAL_ERROR) {
					// something bad happened
					ofLog(OF_LOG_ERROR, "unrecoverable error reading from serial");
					// bail out
					break;
				}
				else if (result == OF_SERIAL_NO_DATA) {
					// nothing was read, try again
				}
				else {
					// we read some data!
					bytesRemaining -= result;
				}
			}
		}
		if (sbyte[0] == '!') {
			string temp = "";
			string sData(reinterpret_cast<char*>(sbyte));
			int j = 0;
			for (int i = 1; i < dataLength && j <dataCount ; i++) {

				if (sData[i] == ',') {
					double tempDouble = atof(temp.c_str());
					data[j].setData(tempDouble);
					myFile << tempDouble << ",";
					
					if (j == 4 || j == 5) {
						if (temp[0] != symbol) { // symbol is character before latitude and magnitude
							data[j].setData(-1);
						}
						else
							myFile << tempDouble << ",";
					}
					if (j == dataCount - 1) 
						myFile << endl;
					temp="";
					j++;
					continue;
				}
				temp += sData[i];
			}

		}

		/*int counter = 0;
		queue <char> qData;
		string temp = "";


		serial.readBytes(sbyte, dataLength);
		string sData(reinterpret_cast<char*>(sbyte));
		for (int i = 0; i < dataLength; i++) {
			if (sData[i] == ',' || sData[i] == '!') {
				while (!qData.empty()) {
					temp += qData.front();
					qData.pop();
				}
				parsData(data, atof(temp.c_str()), counter);
				counter++;
				temp = "";
			}
			else
				qData.push(sData[i]);
		}
	}
	for (int i = 0; i < 5; i++) {
		myFile << data[i].getX() << "," << data[i].getY() << "," << data[i].getZ() << ",";
		if (i == 4)
			myFile << endl;
	}




	/*for (int i = 0; sbyte[i] != '!'; i++) {
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
	//data[0].setData(ibyte, ibyte, ibyte);*/

	}
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
