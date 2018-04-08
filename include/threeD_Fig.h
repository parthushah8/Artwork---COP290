#ifndef THREED_FIG_H
#define THREED_FIG_H

#define pb push_back

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "wireframe.h"

using namespace Eigen;
using namespace std;

class threeD_Fig{
	public:
	
	vector< Point3> m_allPoints;
	int m_numOfPoints;
	vector< Edge> m_allEdges;
	vector< bool> m_hiddenXY;
	vector< bool> m_hiddenYZ;
	vector< bool> m_hiddenXZ;
	int m_numOfEdges;
	vector< Face> m_allFaces;
	int m_numOfFaces;
	
	threeD_Fig();

	
	
	bool addPoint(Point3 &point);
	
	void resetLastPoint();
	
	void resetAllPoints();

	
	bool addEdge(int index1, int index2);
	
	void resetLastEdge();
	
	void resetAllEdges();
	
	bool addFace(int numOfsides, vector<int> allIndexes);
	
	void resetLastFace();
	
	void resetAllFaces();

	void rotateX(double angle);

	void rotateY(double angle);

	void rotateZ(double angle);
	
	wireframe convertToWireframe();
	
	void reconstruct(wireframe &wireframe);

};

#endif
