#pragma once
#include "Transform.h"
#include "PointCloud.h"
#include "FilterPipe.h"


/**
* @file PointCloudGenerator.h
* @Author Yusuf Aktas
* @brief This file includes PointCloudGenerator class.
*/
//! 

/*!
 PointCloudGenerator class created for capturing pointclouds from a text file,
 filtering with FilterPipe class and tranforming with Transform class
*/

class PointCloudGenerator {
private:
	Transform transform;//<!Transform object to perform transform calculations

	FilterPipe* filterPipe;//<!FilterPipe object to perform filtering

public:

	//! PointCloudGenerator constructor
	PointCloudGenerator(string F);

	//!pure virtual function to get point cloud from a text file
	virtual PointCloud capture() = 0;

	//!pure virtual function to get point cloud from a text file and perform filtering and transforming
	virtual PointCloud captureFor() = 0;

	//!assing filterPipe
	void setFilterPipe(FilterPipe*);

	//! returns filterPipe
	FilterPipe getFilterPipe();

	//!assing transform
	void setTransform(Transform);

	//!return transform
	Transform getTransform();
};