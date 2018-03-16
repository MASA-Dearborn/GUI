#pragma once
#include "ofMain.h"
#include <string>

class Box
{
public:
	Box();
	void drawBox();
	void setBox(float _x, float _y, float _px, float _py);
	void setColor(int _r, int _g, int _b);
	void setName(string _name);
	void setOpen(bool _val);
	void loadFont(const string &filename, int fontsize);

protected:
	ofRectangle shape;
	ofColor color;
	string name;
	bool isOpen;
	ofTrueTypeFont label;
};

