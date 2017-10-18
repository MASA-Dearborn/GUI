#include "DataBox.h"


DataBox::DataBox()
{

}

DataBox::~DataBox()
{
}

void DataBox::set(double _x, double _y, double _px, double _py, double _dx, double _dy, double _dz)
{
	shape.set(_px, _py, _x, _y);
	dx = _dx;
	dy = _dy;
	dz = _dz;
	color = ofColor(150, 150, 150);
}

void DataBox::setName(string _name)
{
	name = _name;
}

void DataBox::draw()
{
	ofSetColor(color);
	ofDrawRectangle(shape);


}