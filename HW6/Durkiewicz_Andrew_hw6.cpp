#include <iostream>
#include <string>
#include "Durkiewicz_Point3D.h"
#include "Durkiewicz_Vector3D.h"
#include <stdlib.h>
#include <iomanip>


using namespace std;
void mScale(Vector3D* u1, Vector3D* u2);
void m_dot(Vector3D u1, Vector3D u2); //prints the dot product between a and b;
void m_cross(Vector3D u1, Vector3D u2);
void m_add(Vector3D u1, Vector3D u2);
void m_subtract(Vector3D u1, Vector3D u2);
Vector3D getAB();
//void main menu;


string Color(int value, string Message); //some trickery for fun
int main()
{	
	int response, cross, sub; //all these are for switch case

	cout << "First we need to define orgin and endpoints for our vector." << endl << endl;
	cout << "This is for Vector #1" << endl;
	Vector3D u1 = getAB();
	cout << endl <<  "This is for Vector #2 " << endl;
	Vector3D u2 = getAB();
	system("cls");
	do {
	cout << "Let A = " << u1.toString() << " and B = " << u2.toString() << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "select from the following menu:" << endl;
	cout << "1. AxB / BxA (Cross Product)" << endl;
	cout << "2. Adot(B) (Dot Product)" << endl;
	cout << "3. A + B / B + A (Vector Addition)" << endl;
	cout << "4. A - B / B - A (Vector Subtraction)" << endl;
	cout << "5. Scale A / B / A&B (Vector Scaling)" << endl;
	cout << "6. Display vector properties (angle, unit vector)" << endl; 
	cout << "9. Quit program" << endl << endl;


	cout << "Which of these options would you like to see?" << endl << flush;
	cin >> response;
	switch (response)
	{
	case 1:
		system("cls");
		cout << "Order matters with Cross products, Which one?" << endl;
		do {
			cout << "1. A x B" << endl << "2. B x A" << endl;
			cout << "3. A x -B" << endl << "4. -A x B" << endl;
			cout << "5. Go Back" << endl << flush;
		cin >> cross;
			switch (cross)
			{
			case 1:
				cout << "A x B: ";
				m_cross(u1, u2); 
				break;
			case 2:
				cout << "B x A: ";
				m_cross(u2, u1); 
				cross = 3;
				break;
			case 3:
				u2.scale(-1.0);
				cout << "A x -B:" << endl;
				m_cross(u1, u2);
				u2.scale(-1.0);//uninvert the vector
				break;
			case 4:
				u1.scale(-1.0);
				cout << "-A x B:" << endl;
				m_cross(u1, u2);
				u1.scale(-1.0); //uninvert the vector
				break;
			case 5:
				break;
			default:
				cout << "Invalid input, try again";
				break;
			}
		} while (cross != 5);
		break;
	case 2:
		system("cls");
		m_dot(u1, u2); //dot product
		break;
	case 3:
		system("cls");
		m_add(u1, u2); //add
		break;
	case 4:
		system("cls");
		cout << "subtraction is not cumulative and the order matters. Select: " << endl;
		do {
			cout << "1. A - B" << endl << "2. B - A" << endl << "3. Go Back" << endl << flush;
			cin >> sub;
			switch (sub)
			{
			case 1:
				cout << "A - B: ";
				m_subtract(u1, u2);
				cout << endl;				
				break;
			case 2:
				cout << "B - A: ";
				m_subtract(u2, u1);
				cout << endl;
				break;
			default:
				cout << "That input is not valid, please try again!" << endl;
				break;
			}
		} while (sub != 3);
		system("cls");
		break;
	case 5:
		system("cls");
		mScale(&u1, &u2); //scale
		break;
	case 6:
	{
		system("cls");
		//i had to call this here as my scale function is persistant. If someone chooses to scale and this isn't called here, then it will not work correctly.
		Vector3D unit1 = u1.getUnitVector();
		Vector3D unit2 = u2.getUnitVector();
		cout << "A note on how the angle works. This measures the radian angle above the x-y plane. Thus, all positive values mean that the vector end is located with a positive z value" << endl;
		cout << "----------------------------------------------------------------" << endl << endl;
		cout << "For Vectors A and B, here are the following properties:" << endl;
		cout << "For vector A: " << u1.toString() << endl;
		cout << "Unit Vector: " << unit1.toString() << endl;
		cout << "Size: " << u1.getSize() << endl;
		cout << "Angle off X,Y plane assuming Z is up: " << unit1.angle << " radians" << endl << endl;

		cout << "For vector B: " << u2.toString() << endl;
		cout << "Unit Vector: " << unit2.toString() << endl;
		cout << "Size: " << u2.getSize() << endl;
		cout << "Angle off X,Y plane assuming Z is up: " << unit2.angle << " radians" << endl << endl;
	}
		break;
	case 9:
		cout << "Thank you! Have a nice day!" << endl;
		return false;
	default:
		cout << "This is not a valid option, try again" << endl;
		break;
	}

	}
	while (true);
	return 0;
}
void m_cross(Vector3D u1, Vector3D u2) {
	Vector3D temp = Vector3D();
	Vector3D * ptr = &temp;
	ptr = u2.crossProduct(&u1);
	cout << ptr->toString() << endl << endl;
	delete ptr;
}
void m_add(Vector3D u1, Vector3D u2) {
	Vector3D temp = Vector3D();
	Vector3D * ptr = &temp;
	ptr = u2.add(&u1);
	cout << "ADD:" << endl;
	cout << "A+B: " << ptr->toString() << endl << endl;
	delete ptr;
}
void m_subtract(Vector3D u1, Vector3D u2) {
	Vector3D temp = Vector3D();
	Vector3D * ptr = &temp;
	ptr = u1.subtract(&u2);
	cout << ptr->toString() << endl;
	delete ptr;

}
void m_dot(Vector3D u1, Vector3D u2) {
	cout << "Dot Product:" << endl;
	cout << "Adot(B): " << to_string(u1.dotProduct(&u2)) << endl << endl;
}
Vector3D getAB() {
	int ax, ay, az, bx, by, bz;
	cout << "You will now enter the coordinates to form the vector: " << endl << flush;  
	cout << "Enter vector orgin point in the form x y z: " << flush;
	cin >> ax >> ay >> az;
	cout << "Enter the vector end point in the form x y z: " << flush;
	cin >> bx >> by >> bz;
	Point3D p1 = Point3D();
	Point3D p2 = Point3D();
	p1.setPoint(ax, ay, az);
	p2.setPoint(bx, by, bz);
	Vector3D ABVec_ptr = Vector3D(&p1,&p2);
	return ABVec_ptr;

}
void mScale(Vector3D* u1,Vector3D* u2) {
	int scaleMenu = 0;
	double scaleA, scaleB;
	do {
		cout << "Please Note that this is persistent!" << endl;
		cout << "Scaling options: " << endl << "1. Scale A" << endl << "2. Scale B" << endl << "3. Scale Both A and B" << endl << "Please choose: " << flush;
		cin >> scaleMenu;
		cout << scaleMenu;
	} while (scaleMenu != 1 && scaleMenu != 2 && scaleMenu != 3);

	switch (scaleMenu)
	{
	case 1:
		cout << "Enter scale Value for A: " << endl << flush;
		cin >> scaleA;
		cout << (*u1).toString();
		(*u1).scale(scaleA);
		cout << "->" << (*u1).toString() << endl;

		break;
	case 2:
		cout << "Enter scale Value for B: " << endl << flush;
		cin >> scaleB;
		cout << (*u2).toString();
		(*u2).scale(scaleB);
		cout << "->" << (*u2).toString() << endl;
		break;
	case 3:
		cout << "Enter scale Value for A: " << endl << flush;
		cin >> scaleA;
		cout << "Enter scale Value for B: " << endl << flush;
		cin >> scaleB;


		cout << "A: " << (*u1).toString();
		(*u1).scale(scaleA);
		cout << "->" << (*u1).toString() << " , " << endl << "B: " << (*u2).toString();
		(*u2).scale(scaleB);
		cout << "->" << (*u2).toString() << endl;

		break;
	default:
		cout << "An Error Occurred in the scaleMenu Function";
		break;
	}
}
