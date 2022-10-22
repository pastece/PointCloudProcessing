//Ayþegül AYVAZ -07.01.2022
#include "RadiusOutlierFilter.h"
#include <iostream>
#include <vector>

using namespace std;

RadiusOutlierFilter::~RadiusOutlierFilter()
{
	//destructor
}
void RadiusOutlierFilter::setRadius(double a)
{
	this->radius = a;
}
double RadiusOutlierFilter::getRadius()
{
	return radius;
}
void RadiusOutlierFilter::filter(PointCloud &pc)
{

	Point p;
	int counter = 0;
	int c=pc.getPointNumber();

	for (int i = 0; i < c; i++)
	{
		pc.setPoints(pc.getPoint(i));
	}
	PointCloud newPC;
	newPC.CopyPointList(pc);

	pc.ClearList();

	for (int m=0;m<c;m++)
	{
		for (int n=0;n<c;n++)
		{
			if (newPC.getPoint(m).distance(newPC.getPoint(n)) <= radius )
			{
				if (newPC.getPoint(m) == newPC.getPoint(n))
				{
					break;
				}
				pc.setPoints(newPC.getPoint(m));
				counter++;
				break;
			}
		}
	}
	int d = counter;

	//for (int i = counter; i < c+1; i++)
	//{
	//	pc.setPoints(p);
	//}

	pc.setPointNumber(d);

}