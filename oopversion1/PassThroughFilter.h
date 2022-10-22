//Betül KILIÇKARA -07.01.2022
#pragma once
#include"PointCloudFilter.h"
#include "PointCloud.h"
#include <string>

using namespace std;

class PassThroughFilter:public PointCloudFilter
{
private:
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;

public:
	PassThroughFilter(double UpX, double LowX, double UpY,
		double LowY, double UpZ, double LowZ) :PointCloudFilter(UpX,LowX) {
		this->upperLimitX = UpX;
		this->lowerLimitX = LowX;
		this->upperLimitY = UpY;
		this->lowerLimitY = LowY;
		this->upperLimitZ = UpZ;
		this->lowerLimitZ = LowZ;

	}
	~PassThroughFilter();
	void set_UpX(double);
	double get_UpX();
	void set_LowX(double);
	double get_LowX();
	void set_UpY(double);
	double get_UpY();
	void set_LowY(double);
	double get_LowY();
	void set_UpZ(double);
	double get_UpZ();
	void set_LowZ(double);
	double get_LowZ();

	void filter(PointCloud&);

};