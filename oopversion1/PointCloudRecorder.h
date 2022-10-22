#pragma once
#include<iostream>
#include<fstream>
#include"PointCloud.h"

/**
* @file PointCloudRecorder.h
* @Author Yusuf Aktas
* @brief This file includes PointCloudRecorder class.
*/
//! 

/*!
 PointCloudRecorder class created for saving the result point cloud to a
 text file.
*/


class PointCloudRecorder {
private:

	string fileName;//!< stores the file name as string

public:
	//!PointCloudRecorder constructor
	PointCloudRecorder(string n);

	//!assings the file name to fileName variable
	void setName(string n);

	//!returns fileName variable
	string getName();

	//!saves pointcloud to the text file
	bool save(const PointCloud&pc);




};