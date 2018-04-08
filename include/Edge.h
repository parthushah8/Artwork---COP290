#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <Eigen/Dense>

#include "Point2.h"
#include "Point3.h"
#include "Line.h"

using namespace Eigen;
using namespace std;

class Edge{
	public:
	
	int m_index;// Index of Edge
	
	Point3 m_point1;// Index of Point1
	Point3 m_point2;// Index of Point2

	Edge(Point3 &point1, Point3 &point2, int index);
	
	Edge rotate(Line &line, double angle);
	
	bool isOnEdge(Point3 &point);

	void print();
	
	bool isSame(Edge &edge);
	
};

#endif
