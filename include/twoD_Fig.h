#ifndef TWOD_FIG_H
#define TWOD_FIG_H

#define pb push_back

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point2.h"
#include "Edge_P.h"

using namespace Eigen;
using namespace std;

class twoD_Fig{
	public:
	
	bool m_OnXY;// is the 2D figure on XY Plane
	bool m_OnYZ;// is the 2D figure on YZ Plane
	bool m_OnXZ;// is the 2D figure on XZ Plane
	
	bool m_IsoView;// is the 2D figure an Isometric View
	
	vector< Point2> m_allPoints;// the set of all Points
	int m_numOfPoints;// the number of Points
	vector< Edge_P> m_allEdges;// the set of all Edges
	int m_numOfEdges;// the number of Edges

	twoD_Fig();

	// Constructor
	twoD_Fig(bool OnXY, bool OnYZ, bool OnXZ, bool IsoView);

	void decide(int view);
	
	void clear();

	void print();

	bool isCorrect(Point2 &point);
	
	// we first take input from user and then when he hits "Generate" add all points
	// adds a Point
	bool addPoint(Point2 &point);

	void resetLastPoint();
	
	void resetAllPoints();
	
	// we firsst take input from user and then when he hits "Generate" add all edges
	// add an Edge
	bool addEdge(int index1, int index2, bool hidden);

	void resetLastEdge();
	
	void resetAllEdges();
};

#endif
