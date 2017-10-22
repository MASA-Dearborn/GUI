#include "DataBox.h"

const float DNULL = 0.01021;	//custom null
DataBox::DataBox()
{
	isOpen = false;
}

DataBox::~DataBox()
{
}

void DataBox::set(float _x, float _y, float _px, float _py, double _dx, double _dy, double _dz)
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

void DataBox::setOpen(bool _val)
{
	isOpen = _val;
}

void DataBox::loadFont(const string &filename, int fontsize)
{
	int offset = fontsize / 2;
	label.loadFont(filename, fontsize);
	dataLabel.loadFont(filename, offset);

}

void DataBox::draw()
{
	ofSetColor(color);
	ofDrawRectangle(shape);
	ofSetColor(ofColor(255,255,0));
	/*Set Label*/
	float newHeight = shape.height - label.stringHeight(name);
	float xCenter = (shape.width - label.stringWidth(name)) / 2;	//offset by leftover spaces
	float yOffset = (newHeight) / 4;
	label.drawString(name, shape.x+xCenter, shape.y+yOffset);
	/*Set Data Label
		Positions are partially hardcoded
		FIX!!!							*/
	if (dx != DNULL)
	{	
		xCenter = (shape.width - dataLabel.stringWidth(to_string(dx))) / 2;	//offset by leftover spaces
		yOffset = label.stringHeight(name) * 2 + (newHeight - label.stringHeight(to_string(dx))) / 4;
		dataLabel.drawString(to_string(dx), shape.x + xCenter, shape.y + yOffset);
	}
	if (dy != DNULL)
	{
		xCenter = (shape.width - dataLabel.stringWidth(to_string(dy))) / 2;	//offset by leftover spaces
		yOffset = label.stringHeight(name)*3 + (newHeight - label.stringHeight(to_string(dy))) / 4;
		dataLabel.drawString(to_string(dy), shape.x + xCenter, shape.y + yOffset);
	}
	if (dz != DNULL)
	{
		xCenter = (shape.width - dataLabel.stringWidth(to_string(dz))) / 2;	//offset by leftover spaces
		yOffset = label.stringHeight(name) * 4 + (newHeight - label.stringHeight(to_string(dz))) / 4;
		dataLabel.drawString(to_string(dz), shape.x + xCenter, shape.y + yOffset);
	}
}