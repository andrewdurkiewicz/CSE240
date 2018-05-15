#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "Durkiewicz_Point3D.h"
using namespace std;

#ifndef Vector3D_H
#define Vector3D_H

class Vector3D :public Point3D {
public:
	double angle;
	double size;
	double ux, uy, uz, vx, vy, vz;
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D(Point3D *p1, Point3D *p2);
	double dotProduct(Vector3D* other);
	Vector3D* crossProduct(Vector3D* v1);
	Vector3D* add(Vector3D* other);
	Vector3D* subtract(Vector3D* other);
	void scale(double value);
	Vector3D getUnitVector();
	string toString();
	double getSize();

private:
	double CalculateSize();
	Vector3D CalculateUnitVector();
	
};
#endif

