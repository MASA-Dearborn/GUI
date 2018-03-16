#pragma once
#include "Box.h"

class ButtonBox: public Box
{
public:
	ButtonBox();
	~ButtonBox();

	void clicked(int _x, int _y);

protected:


};

