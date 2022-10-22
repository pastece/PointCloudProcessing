//Ayþegül AYVAZ -07.01.2022

#pragma once
#include "PointCloud.h"
#include "Point.h"
#include"PointCloudFilter.h"
class RadiusOutlierFilter :public PointCloudFilter
{
private:
	double radius;

public:
	RadiusOutlierFilter(double r) :PointCloudFilter(r) { this->radius = r; }
	~RadiusOutlierFilter();
	void setRadius(double);
	double getRadius();
	void filter(PointCloud &PC);
};