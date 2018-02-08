#pragma once
#include "Box.h"


class DataBox: public Box
{
public:
	DataBox();
	virtual ~DataBox();

	void draw();
	void set(float _x, float _y, float _px, float _py, double data);
	void setData(double data);
	double getData();
	void loadFont(const string &filename, int fontsize);


private:
	double data;
	ofTrueTypeFont dataLabel;
};

