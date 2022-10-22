//Betül KILIÇKARA -07.01.2022

#include "PointCloud.h"
#include<iostream>
using namespace std;

PointCloud::PointCloud(){
	pointNumber = 0;
}

void PointCloud::setPointNumber(int b) {
	this->pointNumber = b;
}
int PointCloud::getPointNumber() {
	return this->pointNumber;
}

void PointCloud::setPoints(Point p) {

	this->points.push_back(p);
	this->setPointNumber(points.size());
}

Point PointCloud::getPoint(int _r)
{
	list<Point>::iterator it = this->points.begin();
	for (int i = 0; i < _r; i++) {
		++it;
	}
	return *it;
}

void PointCloud::CopyPointList(PointCloud l) {
	this->points;
	for (int i = 0; i < l.points.size(); i++)
	{
		this->points.push_back(l.points.front());
		l.points.pop_front();
	}
	this->setPointNumber(l.points.size());
}

void PointCloud::ClearList()
{
	this->points.clear();
}
