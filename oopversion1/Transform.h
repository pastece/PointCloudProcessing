#pragma once
#include "PointCloud.h"
#include <Eigen/Dense>
#ifndef TRANSFORM_H
#define TRANSFORM_H

/**
* @file Transform.h
* @Author Yusuf Aktas
* @brief This file includes Transform class.
*/
//! 

/*!
 *Transform class created for calculating the new location of a point or point cloud
 *for a different coordinate axis by using Eigen Library.
 */
class Transform
{
private:

	Eigen::Vector3d angles;//!<stores the rotation values in a vector


	Eigen::Vector3d trans;//!<stores the distance between origins of coordinate axis in a vector

	Eigen::Matrix4d transMatrix;//!<stores translation matrix values in a matrix


public:
	//!Transform constructor
	Transform();

	//!assign new values to angles with array
	void setRotation(double ang[]);

	//!assign new values to angles with vector
	void setRotation(Eigen::Vector3d ang);

	//!assign new values to trans with array
	void setTranslation(double tr[]);

	//!assign new values to angles with vector
	void setTranslation(Eigen::Vector3d tr);

	//!returns angles vector
	Eigen::Vector3d getRotation();

	//!returns trans vector
	Eigen::Vector3d getTranslation();

	//!creates the transMatrix, makes required calculations and returns new transformed point
	Point doTransform(Point p);

	//!creates the transMatrix, makes required calculations and returns new transformed point cloud
	PointCloud doTransform(PointCloud pc);

};

#endif // !1