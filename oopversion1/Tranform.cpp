#include "Transform.h"
#define _USE_MATH_DEFINES 
#include <math.h>

using namespace std;

Transform::Transform() {
    angles = {};
    trans = {};
    transMatrix = {};
}



/*!
    /param ang is a double array argument
    /return void
*/
void Transform::setRotation(double ang[])
{
    if (ang == NULL) return;
    
    for (int i = 0; i < 3; i++)
        angles[i] = ang[i];


}

/*!
    /param ang is a vector argument
    /return void
*/
void Transform::setRotation(Eigen::Vector3d ang) {
    angles = ang;

}

/*!
    /tr ang is double array argument
    /return void
*/
void Transform::setTranslation(double tr[])
{
    if (tr == NULL) return;

    for (int i = 0; i < 3; i++)
        trans[i] = tr[i];


}

/*!
    /param tr is vector argument
    /return void
*/
void Transform::setTranslation(Eigen::Vector3d tr) {
    trans = tr;

}

/*!
    /return angle vector
*/
Eigen::Vector3d Transform::getRotation() {
    return angles;
}

/*!
    /return trans vector
*/
Eigen::Vector3d Transform::getTranslation() {
    return trans;
}

/*!
    /param p is a Point argument    
    /return transformed point
*/
Point Transform::doTransform(Point p) {
    Eigen::Vector4d  aP(0,0,0,0);
    Eigen::Vector4d  bP;
    bP[0] = p.getx();
    bP[1] = p.gety();
    bP[2] = p.getz();
    bP[3] = 1;
    
    
    double pitch = M_PI * (angles[0]/180);
    double yaw = M_PI * (angles[1]/180);
    double roll = M_PI * (angles[2]/180);

    Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitZ());
    Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitY());
    Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitX());

    Eigen::Quaternion<double> q = pitchAngle * yawAngle * rollAngle;

    Eigen::Matrix3d rotationMatrix = q.matrix();    

    transMatrix.setIdentity();
    transMatrix.block<3, 3>(0, 0) = rotationMatrix;
    transMatrix.block<3, 1>(0, 3) = trans;


    aP = transMatrix * bP;
           
    Point newP;
    newP.setx(aP(0));
    newP.sety(aP(1));
    newP.setz(aP(2));
   

    return newP;
}

/*!
    /param p is a PointCloud argument
    /return transformed point cloud
*/
PointCloud Transform::doTransform(PointCloud pc) {

    int max = pc.getPointNumber();
    Point p;
    PointCloud newpc;

    for (int i = 0; i < max; i++) {
        p = pc.getPoint(i);
        newpc.setPoints(doTransform(p));
    }

    return newpc;
}