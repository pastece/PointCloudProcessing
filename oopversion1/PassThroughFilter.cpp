//Betül KILIÇKARA -07.01.2022
#include "PassThroughFilter.h"
#include<iostream>

using namespace std;

	
PassThroughFilter::~PassThroughFilter() {
}
void PassThroughFilter::set_UpX(double UpX) {
	upperLimitX = UpX;
}
void PassThroughFilter::set_UpY(double UpY) {
	upperLimitY = UpY;
}
void PassThroughFilter::set_UpZ(double UpZ) {
	upperLimitZ = UpZ;
}
void PassThroughFilter::set_LowX(double LowX) {
	lowerLimitX = LowX;
}
void PassThroughFilter::set_LowY(double LowY) {
	lowerLimitY = LowY;
}
void PassThroughFilter::set_LowZ(double LowZ) {
	lowerLimitZ = LowZ;
}
double PassThroughFilter::get_UpX() {
	return upperLimitX;
}
double PassThroughFilter::get_LowX() {
	return lowerLimitX;
}
double PassThroughFilter::get_UpY() {
	return upperLimitY;
}
double PassThroughFilter::get_LowY() {
	return lowerLimitY;
}
double PassThroughFilter::get_UpZ() {
	return upperLimitZ;
}
double PassThroughFilter::get_LowZ() {
	return lowerLimitZ;
}


void PassThroughFilter::filter(PointCloud &pc)
{
	Point p;
	int counter = 0;
	int c = pc.getPointNumber();

	for (int i = 0; i < c; i++)
	{
		pc.setPoints(pc.getPoint(i));
	}
	PointCloud newPC;
	newPC.CopyPointList(pc);

	pc.ClearList();


	for (int m = 0; m < c;m++)
	{
		if (newPC.getPoint(m).getx() <= upperLimitX&& newPC.getPoint(m).getx() >= lowerLimitX
			&& newPC.getPoint(m).gety() <= upperLimitY && newPC.getPoint(m).gety() >= lowerLimitY
			&& newPC.getPoint(m).getz() <= upperLimitZ&& newPC.getPoint(m).getz() >= lowerLimitZ)
		{
			pc.setPoints(newPC.getPoint(m));
			counter++;

		}
	}
	int d = counter;

	//for (int i = counter; i < c + 1; i++)
	//{
	//	pc.setPoints(p);
	//}

	pc.setPointNumber(d);

}