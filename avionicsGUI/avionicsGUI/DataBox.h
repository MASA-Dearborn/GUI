
# include <string>

class DataBox
{
public:
	DataBox();
	~DataBox();
	double getDx();
	double getDy();
	double getDz();
	void setDx();
	void setDy();
	void setDz();
	void draw();
	void setPosx();
	void setPosy();
	void setX();
	void setY();

private:
	double x, y, posX, posY,dx,dy,dz;
	std::string name;
};

