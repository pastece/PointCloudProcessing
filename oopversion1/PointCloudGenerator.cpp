#include "PointCloudGenerator.h"

using namespace std;

PointCloudGenerator::PointCloudGenerator(string F) {
	filterPipe = new FilterPipe;
	string fileName = F;
}

/*!
	/param fp is a FilterPipe argument
	/return void
*/
void PointCloudGenerator::setFilterPipe(FilterPipe* fp) {

	filterPipe = fp;
}

/*!
	/return filterPipe object
*/
FilterPipe PointCloudGenerator::getFilterPipe() {
	return *filterPipe;
}

/*!
	/param tr is a Transform argument
	/return void
*/
void PointCloudGenerator::setTransform(Transform tr) {
	transform = tr;
}

/*!
	/return transform object
*/
Transform PointCloudGenerator::getTransform() {
	return transform;
}