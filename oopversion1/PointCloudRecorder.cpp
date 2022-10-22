#include "PointCloudRecorder.h"
#include <string>
#include <iostream>
#include <fstream> 
#include "PointCloud.h"


using namespace std;


PointCloudRecorder::PointCloudRecorder(string n="result.txt") { fileName = n; }

/*!
	/param n is string argument
	/return void
*/
void PointCloudRecorder::setName(string n) { fileName = n; }


/*!
	/return fileName
*/
string PointCloudRecorder::getName() { return fileName; }

/*!
	/param pc is a PointCloud argument
	/return bool
*/
bool PointCloudRecorder::save(const PointCloud& pc) {
	ofstream result(fileName);

	if (!result) {
		cout << "File error!" << endl;
		return 0;
	}

	PointCloud temp;

	temp = pc;

	int max=temp.getPointNumber();
	
	for (int i = 0; i < max; i++) {
		result << temp.getPoint(i).getx() << " ";
		result << temp.getPoint(i).gety() << " ";
		result << temp.getPoint(i).getz() << " ";
		result << endl;
	}

	return 1;
}