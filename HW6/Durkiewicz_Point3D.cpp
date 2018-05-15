#include "Durkiewicz_Point3D.h"
#include <cmath>
Point3D::Point3D() {
	double x;
	double y;
	double z;
};


void Point3D::setPoint(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}



double Point3D::getDistance(Point3D* p2) {
	Point3D *p1 = this;


	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));


}

