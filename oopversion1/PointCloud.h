//Betül KILIÇKARA -07.01.2022
#pragma once
#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include<list>
#include<iterator>
#include <iostream>
#include<algorithm>
#include"Point.h"
#define MAX 2000

class PointCloud
{
private:
	int pointNumber;
	list<Point> points;

public:
	PointCloud();
	void setPointNumber(int b);
	int getPointNumber();
	void setPoints(Point p);
	Point getPoint(int _r);
	PointCloud operator+(PointCloud p)
	{
		int s = this->getPointNumber() + p.getPointNumber();
		PointCloud pointCloud;
		for (int f = 0; f < this->getPointNumber(); f++)
		{
			
			pointCloud.setPoints(this->getPoint(f));
			
		}

		for (int f = 0; f < p.getPointNumber(); f++)
		{
			pointCloud.setPoints( p.getPoint(f));
		}
		return pointCloud;
	}

	void CopyPointList(PointCloud l);
	void ClearList();
};
#endif // !POINTCLOUD_H

