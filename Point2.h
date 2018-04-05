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

	// Constructor	
	Point2(double c1, double c2, int index, bool xy, bool yz, bool xz, bool isoView){
		m_index = index;
		m_coordinates<< c1, c2;
		m_OnXY = xy;
		m_OnYZ = yz;
		m_OnXZ = xz;
		m_IsoView = isoView;
	}
	
	Point2(){
		m_index = -1;
		m_coordinates<< 0.0, 0.0;
		m_OnXY = false;
		m_OnYZ = false;
		m_OnXZ = false;
		m_IsoView = false;
	}

	// print the point in the format "P1 : (3.0, 4.0)"
	void print(){
		cout<<"\nP"<< m_index<<" : ("<<m_coordinates(0)<<", "<<m_coordinates(1)<<")";
		if(m_OnXY){
			cout<<" on XY Plane.";
		}
		else if(m_OnYZ){
			cout<<" on YZ Plane.";
		}
		else if(m_OnXY){
			cout<<" on XZ Plane.";
		}
		else if(m_IsoView){
			cout<<" Isometric View";
		}
		return;
	}
	
	// returns true if both the Points coiincide
	bool isSame(Point2 &point){
		return (point.m_coordinates(0) == m_coordinates(0)) && (point.m_coordinates(1) == m_coordinates(1)) 
				&& ((point.m_OnXY && m_OnXY) || (point.m_OnYZ && m_OnYZ) || (point.m_OnXZ && m_OnXZ) 					    || (point.m_IsoView && m_IsoView));
	}

};

#endif
