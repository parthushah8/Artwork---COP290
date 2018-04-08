#include <iostream>
#include <Eigen/Dense>

#include "Point2.h"

using namespace Eigen;
using namespace std;

	Point2::Point2(double c1, double c2, int index, bool xy, bool yz, bool xz, bool isoView){
		// Constructor	
		m_index = index;
		m_coordinates<< c1, c2;
		m_OnXY = xy;
		m_OnYZ = yz;
		m_OnXZ = xz;
		m_IsoView = isoView;
	}
	
	Point2::Point2(){
		// Empty Constructor
		m_index = -1;
		m_coordinates<< 0.0, 0.0;
		m_OnXY = false;
		m_OnYZ = false;
		m_OnXZ = false;
		m_IsoView = false;
	}

	void Point2::print(){
		// print the point in the format "P1 : (3.0, 4.0)"
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
	
	bool Point2::isSame(Point2 &point){
		// returns true if both the Points coiincide
		return (point.m_coordinates(0) == m_coordinates(0)) && (point.m_coordinates(1) == m_coordinates(1)) 
				&& ((point.m_OnXY && m_OnXY) || (point.m_OnYZ && m_OnYZ) || (point.m_OnXZ && m_OnXZ) 					    || (point.m_IsoView && m_IsoView));
	}
