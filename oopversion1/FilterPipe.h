#pragma once
#include"PointCloudFilter.h"
#include<vector>

class FilterPipe
{
private:
	vector<PointCloudFilter*>filters;
public:
	FilterPipe();
	void addFilter(PointCloudFilter *filter);
	void filterOut(PointCloud & pc);
};

