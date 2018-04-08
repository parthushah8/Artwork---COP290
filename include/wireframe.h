#ifndef WIREFRAME_H
#define WIREFRAME_H

#define pb push_back
#define mp make_pair

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "twoD_Fig.h"
// #include "threeD_Fig.h"

using namespace Eigen;
using namespace std;

class wireframe{
	public:
	
	vector< Point3> m_allPoints;
	int m_numOfPoints;
	vector< Edge> m_allEdges;
	vector< bool> m_hiddenXY;
	vector< bool> m_hiddenYZ;
	vector< bool> m_hiddenXZ;
	
	int m_numOfEdges;
	bool m_modelOver;

	set< pair<int, int> > edgesPresent;
	
	wireframe();

	void clear();
	
	bool addPoint(Point3 &point);
	
	bool addEdge(int index1, int index2);

	bool addEdge3D(int index1,int index2,bool isHiddenXY,bool isHiddenYZ,bool isHiddenXZ);
	
	bool Complete();
	
	twoD_Fig projectXY();
	
	twoD_Fig projectYZ();
	
	twoD_Fig projectXZ();
	
	// twoD_Fig projectIsoView();

	bool regenerate(twoD_Fig XYproj, twoD_Fig YZproj, twoD_Fig XZproj);

	//threeD_Fig construct();
};

#endif
