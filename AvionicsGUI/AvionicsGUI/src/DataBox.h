#pragma once
#include "ofMain.h"
#include <string>



class DataBox
{
public:
	DataBox();
	virtual ~DataBox();

	void draw();
	void set(double _x, double _y, double _px, double _py, double _dx, double _dy, double _dz);
	void setName(string _name);


private:
	ofRectangle shape;
	ofColor color;
	double dx, dy, dz;
	string name;

};

