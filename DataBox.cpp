#include "DataBox.h"

const float DNULL = 0.01021;	//custom null
DataBox::DataBox()
{
	isOpen = false;
}

DataBox::~DataBox()
{
}

void DataBox::set(float _x, float _y, float _px, float _py, double data)
{
	shape.set(_px, _py, _x, _y);
	this->data = data;
	color = ofColor(150, 150, 150);
}

double DataBox::getData() {
	return data;
  }

void DataBox::loadFont(const string &filename, int fontsize)
{
	int offset = fontsize / 2;
	label.loadFont(filename, fontsize);
	dataLabel.loadFont(filename, offset);

}

void DataBox::setData(double data)
{
	this->data = data;
}


void DataBox::draw()
{
	drawBox();
	float xCenter = (shape.width - label.stringWidth(name)) / 2;	//offset by leftover spaces
	float yOffset = (shape.height / 5) + 3;
	/*Set Data Label
		Positions are partially hardcoded
		FIX!!!							*/
	float newHeight = yOffset;
	if (data != DNULL)
	{	
		xCenter = (shape.width - dataLabel.stringWidth(to_string(data))) / 2;	//offset by leftover spaces
		yOffset = newHeight*2 + (newHeight - label.stringHeight(to_string(data))) / 4;
		dataLabel.drawString(to_string(data), shape.x + xCenter, shape.y + yOffset);
	}
	
}