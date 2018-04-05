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

	// Constructor
	twoD_Fig(bool OnXY, bool OnYZ, bool OnXZ, bool IsoView){
	
		m_numOfPoints = 0;
		m_numOfEdges = 0;

		bool check1 = (OnXY || OnYZ || OnXZ);
		bool check2 = (OnXY || OnYZ || IsoView);
		bool check3 = (OnYZ || OnXZ || IsoView);
		bool check4 = (OnXY || OnXZ || IsoView);
		
		if((check1 && check2 && check3 && check4)){
			cout<<"\nWARNING : More than 1 attribute is true in 2DFigure.";
		}
		else{
			m_OnXY = OnXY;
			m_OnYZ = OnYZ;
			m_OnXZ = OnXZ;
		
			m_IsoView = IsoView;
		}
	}
	
	void clear(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		
		m_allPoints.clear();
		m_allEdges.clear();
		
		return;
	}

	void print(){
		for(int i=0;i<m_numOfPoints;i++){
			m_allPoints[i].print();
		}
		for(int i=0;i<m_numOfEdges;i++){
			m_allEdges[i].print();
		}
	}

	bool isCorrect(Point2 &point){
		//cout<<"Checking\n";
		//cout<<"Point XY: "<<point.m_OnXY<<endl;
		//cout<<"TwoDFig XY: "<<m_OnXY<<endl;
		//cout<<"Point YZ: "<<point.m_OnYZ<<endl;
		//cout<<"TwoDFig YZ: "<<m_OnYZ<<endl;
		//cout<<"Point XZ: "<<point.m_OnXZ<<endl;
		//cout<<"TwoDFig XZ: "<<m_OnXZ<<endl;
		//cout<<"Point Iso: "<<point.m_IsoView<<endl;
		//cout<<"TwoDFig Iso: "<<m_IsoView<<endl;
		return (point.m_OnXY && m_OnXY) || (point.m_OnYZ && m_OnYZ) || (point.m_OnXZ && m_OnXZ) || (point.m_IsoView && m_IsoView);
	}
	
	// we first take input from user and then when he hits "Generate" add all points
	// adds a Point
	bool addPoint(Point2 &point){
		if(!isCorrect(point)){
			cout<<"\nERROR : Point not on the plane";
			return false;
		}
		if(point.m_index == m_numOfPoints){
			m_allPoints.pb(point);
			m_numOfPoints+=1;
			return true;
		}
		else{
			cout<<"\nERROR : Illegal Ordering";
			return false;
		}
	}
	
	// we firsst take input from user and then when he hits "Generate" add all edges
	// add an Edge
	bool addEdge(int index1, int index2, bool hidden){
		if(index1 >= m_numOfPoints || index2 >= m_numOfPoints){
			cout<<"\nERROR : Point Indexing not Proper.";
			return false;
		}
		if(index1 == index2){
			cout<<"\nERROR : Same Point Mentioned Twice.";
			return false;
		}
		m_allEdges.pb(Edge_P(m_allPoints[index1],m_allPoints[index2],m_numOfEdges,hidden));
		m_numOfEdges+=1;
		return false;
	}
};

#endif
