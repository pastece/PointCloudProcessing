#pragma once
#include"PointCloud.h"
class PointCloudFilter
{
protected:
	double upperLimitX;
	double lowerLimitY;
	double radius;
public:
	virtual void filter(PointCloud& pc) = 0;
	PointCloudFilter(double r);
	PointCloudFilter(double i, double j);
};