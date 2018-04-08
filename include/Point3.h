#ifndef POINT3_H
#define POINT3_H

#include <iostream>
#include <Eigen/Dense>

#include "Line.h"
#include "Point2.h"

#define PI 3.14159265

using namespace Eigen;
using namespace std;

class Point3{
	public:

	int m_index;// index of the point
	Vector3f m_coordinates;// Cordinates of the point (x, y, z)
		
	Point3(double x, double y, double z,int index);

	Point3();
	
	Point2 projectOnXY();
	
	Point2 projectOnYZ();
	
	Point2 projectOnXZ();
	
	void regenerate3(Point2 &pointxy, Point2 &pointyz, Point2 &pointxz);

	void regenerate2_XY_YZ(Point2 &pointxy, Point2 &pointyz);
	
	void regenerate2_YZ_XZ(Point2 &pointyz, Point2 &pointxz);

	void regenerate2_XY_XZ(Point2 &pointxy, Point2 &pointxz);

	void regenerate2(Point2 &point1, Point2 &point2);
	
	Point3 rotate(Line &line, double angle);
	
	Point3 rotateX(double angle);

	Point3 rotateY(double angle);

	Point3 rotateZ(double angle);

	void print();
	
	bool isSame(Point3 &point);

};

#endif
