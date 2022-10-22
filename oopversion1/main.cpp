#include<iostream>
#include"DepthCamera.h"
#include"Point.h"
#include"PointCloud.h"
#include"Transform.h"
#include "PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"RadiusOutlierFilter.h"

using namespace std;

int main()
{

	PointCloud pc1, pc2, result;

	DepthCamera c1("camera1.txt"), c2("camera1.txt");
	Transform t1, t2;
	Eigen::Vector3d rt1(0, 0, -90);
	Eigen::Vector3d tr1(100, 500, 50);

	Eigen::Vector3d rt2(0, 0, 90);
	Eigen::Vector3d tr2(550, 150, 50);

	t1.setRotation(rt1);
	t1.setTranslation(tr1);

	t2.setRotation(rt2);
	t2.setTranslation(tr2);

	PointCloudFilter* R = new RadiusOutlierFilter(25);
	PointCloudFilter* T1 = new PassThroughFilter(400, 0, 400, 0, 45, -45);
	PointCloudFilter* T2 = new PassThroughFilter(500, 0, 500, 0, 45, -45);

	FilterPipe filter1;
	filter1.addFilter(R);
	filter1.addFilter(T1);
	FilterPipe filter2;
	filter2.addFilter(R);
	filter2.addFilter(T2);


	c1.setFilterPipe(&filter1);
	c2.setFilterPipe(&filter2);

	c1.setTransform(t1);
	c2.setTransform(t2);

	

	pc1 = c1.captureFor();
	pc2 = c2.captureFor();

	result = pc1 + pc2;

	PointCloudRecorder r("result.txt");

	r.save(result);






	return 0;
}