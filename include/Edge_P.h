#ifndef EDGE_P_H
#define EDGE_P_H

#include <iostream>
#include <Eigen/Dense>

#include "Point2.h"
#include "Point3.h"
#include "Line.h"

using namespace Eigen;
using namespace std;

class Edge_P{
	public:
	
	int m_index;// Index of Edge
	
	Point2 m_point1;// Index of Point1
	Point2 m_point2;// Index of Point2
	
	bool m_isHidden;// Is the line Hidden

	Edge_P(Point2 &point1, Point2 &point2, int index, bool isHidden);
	
	void print();
	
	bool isSame(Edge_P &edge);
	
};

#endif
