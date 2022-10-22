#pragma once
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include<vector>

class PointCloudInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*>generators;
	PointCloudRecorder* recorder;

public:
	PointCloudInterface();


	void addGenerator(PointCloudGenerator* gen);

	void setRecorder(PointCloudRecorder* rec);
	bool generate();
	bool record();
};