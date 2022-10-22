#include "DepthCamera.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;



void DepthCamera::setFN(string FN) { fileName = FN; }
string DepthCamera::getFN() { return fileName; }
PointCloud DepthCamera::capture() {

	fstream dataFile;
	Point p;
	PointCloud PC;

	double a;
	dataFile.open(fileName, std::fstream::in);
	if (!dataFile) {
		cerr << "Could not open the file - '" << fileName << "'" << endl;
	}
	else
	{

		while (!dataFile.eof())
		{
			dataFile >> a;
			p.setx(a);
			dataFile >> a;
			p.sety(a);
			dataFile >> a;
			p.setz(a);
			PC.setPoints(p);


		}
		return PC;
	}
}

PointCloud DepthCamera::captureFor()
{
	fstream dataFile;
	Point p;
	PointCloud PC;
	FilterPipe fp;
	Transform tr;

	double a;
	dataFile.open(fileName, std::fstream::in);
	if (!dataFile) {
		cerr << "Could not open the file - '" << fileName << "'" << endl;
	}
	else
	{

		while (!dataFile.eof())
		{
			dataFile >> a;
			p.setx(a);
			dataFile >> a;
			p.sety(a);
			dataFile >> a;
			p.setz(a);
			PC.setPoints(p);
		}
		//PC
	}

	fp = getFilterPipe();

	fp.filterOut(PC);

	tr = getTransform();
	PC=tr.doTransform(PC);
	
	return PC;



	/*PointCloudFilter* R = new RadiusOutlierFilter(25);
	PointCloudFilter* T1 = new PassThroughFilter(400, 0, 400, 0, 45, -45);
	PointCloudFilter* T2 = new PassThroughFilter(500, 0, 500, 0, 45, -45);

	FilterPipe filter1;
	filter1.addFilter(R);
	filter1.addFilter(T1);
	FilterPipe filter2;
	filter2.addFilter(R);
	filter2.addFilter(T2);
	if (this->getFN() == "camera1.txt")
	{
		filter1.filterOut(PC);
	}
	else if (this->getFN() == "camera2.txt")
	{
		filter2.filterOut(PC);
	}

	Transform t1;
	double ang[4] = { 0, 0, -90 };
	double tr[4] = { 100, 500, 50 };
	t1.setRotation(ang);
	t1.setTranslation(tr);
	Transform t2;
	double ang1[4] = { 0, 0, 90 };
	double tr1[4] = { 550, 150, 50 };
	t2.setRotation(ang1);
	t2.setTranslation(tr1);

	if (this->getFN() == "camera1.txt")
	{
		pc = t1.doTransform(PC);
	}
	else if (this->getFN() == "camera2.txt")
	{
		pc = t2.doTransform(PC);
	}
	return pc;*/

}