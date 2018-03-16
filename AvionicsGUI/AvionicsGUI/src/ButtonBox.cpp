#include "ButtonBox.h"



ButtonBox::ButtonBox()
{
}


ButtonBox::~ButtonBox()
{
}

void ButtonBox::clicked(int _x, int _y)
{
	float left_border = shape.x - shape.position.x;
	float right_border = shape.x;
	float bottom_border = shape.y - shape.position.y;
	float top_border = shape.y;
	if ((_x > left_border) && (_x < right_border) && (_y > bottom_border) && (_y < top_border))
	{


	}

}