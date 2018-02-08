#include "Box.h"

Box::Box()
{
	isOpen = false;
}

void Box::setName(string _name)
{
	name = _name;
}

void Box::setOpen(bool _val)
{
	isOpen = _val;
}

void Box::loadFont(const string &filename, int fontsize)
{
	int offset = fontsize / 2;
	label.loadFont(filename, fontsize);
}


void Box::drawBox()
{
	ofSetColor(color);
	ofDrawRectangle(shape);
	ofSetColor(ofColor(255, 255, 0));
	/*Set Label*/
	float xCenter = (shape.width - label.stringWidth(name)) / 2;	//offset by leftover spaces
	float yOffset = (shape.height / 5) + 3;
	label.drawString(name, shape.x + xCenter, shape.y + yOffset);
}