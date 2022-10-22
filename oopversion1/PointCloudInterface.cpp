#include "PointCloudInterface.h"

PointCloudInterface::PointCloudInterface()
{
	recorder = new PointCloudRecorder("result.txt");
}
void PointCloudInterface::addGenerator(PointCloudGenerator* gen)
{
	this->generators.push_back(gen);
}

void PointCloudInterface::setRecorder(PointCloudRecorder* rec)
{
	recorder = rec;
}

bool PointCloudInterface::generate()
{
	for (int i = 0; i < generators.size(); i++)
	{
		patch = generators[i]->captureFor();
		for (int j = 0; j < patch.getPointNumber(); j++)
		{
			pointCloud.setPoints(patch.getPoint(j));
		}
	}
	return 1;
}

bool PointCloudInterface::record()
{
	recorder->save(pointCloud);
	return 1;
}