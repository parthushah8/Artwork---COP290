#ifndef POINT2_H
#define POINT2_H

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

class Point2{
	public:

	int m_index;// index of the point
	Vector2f m_coordinates;// Cordinates of the point (x, y) or (y, z) or (x, z)

	bool m_OnXY;// is it on XY Plane
	bool m_OnYZ;// is it on YZ Plane
	bool m_OnXZ;// is it on XZ Plane
	
	bool m_IsoView;// is it the Isometric View of a Point in 3D

	Point2(double c1, double c2, int index, bool xy, bool yz, bool xz, bool isoView);
	
	Point2();

	void print();
	
	bool isSame(Point2 &point);

};

#endif
