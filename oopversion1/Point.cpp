//Betül KILIÇKARA -07.01.2022
#include"Point.h"
#include<iostream>
#include<cmath>
using namespace std;


Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
void Point::setx(double x) {
	this->x = x;
}
double Point::getx() {
	return this->x;
}
void Point::sety(double y) {
	this->y = y;
}
double Point::gety() {
	return this->y;
}
void Point::setz(double z) {
	this->z = z;
}
double Point::getz() {
	return this->z;
}
double const Point::distance(const Point& q) {

	return sqrt(pow((this->x - q.x), 2) + pow((this->y - q.y), 2) + pow((this->z - q.z), 2));
}
