#pragma once
#include "Box.h"


class DataBox: public Box
{
public:
	DataBox();
	virtual ~DataBox();

	void draw();
	void set(float _x, float _y, float _px, float _py, double _dx, double _dy, double _dz);
	void setData(double _dx, double _dy, double _dz);
	void setX(double _x);
	void setY(double _y);
	void setZ(double _z);
	void loadFont(const string &filename, int fontsize);


private:
	double dx, dy, dz;
	ofTrueTypeFont dataLabel;
};

