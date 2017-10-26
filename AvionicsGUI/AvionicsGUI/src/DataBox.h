#pragma once
#include "ofMain.h"
#include <string>



class DataBox
{
public:
	DataBox();
	virtual ~DataBox();

	void draw();
	void set(float _x, float _y, float _px, float _py, double _dx, double _dy, double _dz);
	void setData(double _dx, double _dy, double _dz);
	void setName(string _name);
	void setOpen(bool _val);
	void loadFont(const string &filename, int fontsize);


private:
	ofRectangle shape;
	ofColor color;
	double dx, dy, dz;
	string name;
	bool isOpen;
	ofTrueTypeFont label;
	ofTrueTypeFont dataLabel;


};

