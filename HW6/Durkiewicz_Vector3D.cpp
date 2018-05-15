#include "Durkiewicz_Point3D.h"
#include <cmath>
#include "Durkiewicz_Point3D.h"
#include "Durkiewicz_Vector3D.h"
#include <string>

using namespace std;

Vector3D::Vector3D() {
	double angle, size, vx, vy, vz, ux, uy, uz;//Note, I only use this one time to make a temp pointer to hold a value.
}

Vector3D::Vector3D(double x, double y, double z)
{
	angle = atan(z / sqrt(pow(x,2) + pow(y,2))); //in rads
	size = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	vx = x;
	vy = y;
	vz = z;
	ux = x / size;
	uy = y / size;
	uz = z / size;

};


Vector3D::Vector3D(Point3D* p1, Point3D* p2)
{	

	vx = p2->x - p1->x;
	vy = p2->y - p1->y;
	vz = p2->z - p1->z;
	angle = atan(vz / sqrt(pow(vx, 2) + pow(vy, 2)));
	size = sqrt(pow(vx, 2) + pow(vy, 2) + pow(z, 2));
	ux = vx / size;
	uy = vy / size;
	uz = vz / size;

}

double Vector3D::dotProduct(Vector3D * v1)
{

	return v1->vx*this->vx + v1->vy*this->vy + v1->vz*this->vz;
}

Vector3D * Vector3D::crossProduct(Vector3D * v1)
{
	Vector3D * v_ptr = new Vector3D((this->vy*v1->vz) - (this->vz*v1->vy), (this->vz*v1->vx) - (this->vx*v1->vz), (this->vx*v1->vy) - (this->vy*v1->vx));
	
	return v_ptr;
}
Vector3D * Vector3D::add(Vector3D * v1)
{
	Vector3D * v2plusv1 = new Vector3D(this->vx + v1->vx, this->vy + v1->vy, this->vz + v1->vz);
	return v2plusv1;
}

Vector3D * Vector3D::subtract(Vector3D * v1)
{
	Vector3D * v2minusv1 = new Vector3D(this->vx - v1->vx, this->vy + v1->vy, this->vz + v1->vz);
	return v2minusv1;
}

void Vector3D::scale(double value)
{
	*this = Vector3D(this->vx * value, this->vy * value, this->vz * value);
	
}

Vector3D Vector3D::getUnitVector()
{
	//i did it this way because my program actually has persistance. This allows me to recalc the unit vector on the fly
	Vector3D unitVector = CalculateUnitVector();
	return unitVector;
}

double Vector3D::getSize() {
	return CalculateSize();
}

double Vector3D::CalculateSize()
{
	return sqrt(pow(this->vx, 2) + pow(this->vy, 2) + pow(this->vz, 2));
}



Vector3D Vector3D::CalculateUnitVector()
{
	double size = this->CalculateSize();
	double ux = this->vx / size;
	double uy = this->vy / size;
	double uz = this->vz / size;
	
	return Vector3D(ux,uy,uz);
}

string Vector3D::toString() {
	//cout << "(" << to_string(this->vx) << "," << to_string(this->vy) << "," << to_string(this->vz) << ")";
	return "(" + to_string(this->vx) + "," + to_string(this->vy) + "," + to_string(this->vz) + ")";

}

