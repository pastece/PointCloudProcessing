//Betül KILIÇKARA -07.01.2022
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point {

private:
	double x, y, z;
public:
	Point();

	void setx(double x);
	double getx();
	void sety(double y);
	double gety();
	void setz(double z);
	double getz();

	virtual bool operator==(const Point& other) const
	{
		if (this->x==other.x&&this->y==other.y&&this->z==other.z)
			return true;

		else
			return false;
	}
	double const distance(const Point&) ;

};
#endif // !POINT_H