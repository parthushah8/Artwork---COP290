#ifndef FACE_H
#define FACE_H

#define pb push_back
#define INF 10000.0

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"

using namespace Eigen;
using namespace std;

class Face{
	private:
	
	struct Point;
	
	bool onSegment(Point p, Point q, Point r);
	
	int orientation(Point p, Point q, Point r);
	
	bool doIntersect(Point p1, Point q1, Point p2, Point q2);
	
	bool isInside(Point polygon[], int n, Point p);
	
	public:
	
	int m_index;// index of Face
	int m_numOfsides;// number of sides on Face
	bool m_isComplete;// is the Face Complete
	
	vector< Edge> m_allEdges;// All Edges
	vector< int> m_pointIndex;// All Point Indexes
	vector< Point3> m_allPoints;// All Points
	
	Point3 firstPoint;// First Point
	Point3 lastPoint;// Last Point

	double a;// normal-vector(x)
	double b;// normal-vector(y)
	double c;// normal-vector(z)
	
	double d;// ax + by + cz = d
	
	Face(int index);

	void addFirstPoint(Point3 &point);

	bool addPoints(Point3 &point1, Point3 &point2);
	
	bool addEdge(Edge &edge);

	void getPlane();
	
	Point3 project(Point3 &point,int view);

   	bool isOnFace(Point3 &point);

	bool isHidden(Point3 &point,int view);

	bool isHiddenEdge(Edge &edge,int view);
	
	
	void print();

	bool isComplete();
};

#endif
