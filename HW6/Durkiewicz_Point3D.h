#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef Point3D_H
#define Point3D_H

class Point3D {


public:
	double x, y, z;
	Point3D();
	void setPoint(double x, double y, double z);
	double getDistance(Point3D* p1);
};
#endif
