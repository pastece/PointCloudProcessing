#pragma once
#include<iostream>
#include<fstream>
#include"PointCloud.h"
#include"FilterPipe.h"
#include"RadiusOutlierFilter.h"
#include"PassThroughFilter.h"
#include"PointCloudGenerator.h"
#include"PointCloudFilter.h"
#include"Transform.h"

using namespace std;
class DepthCamera: public PointCloudGenerator
{
private:
	string fileName;

public:
	DepthCamera(string F) :PointCloudGenerator(F) { this->fileName = F; }
	void setFN(string FN);
	string getFN();
	PointCloud capture();
	PointCloud captureFor();

};