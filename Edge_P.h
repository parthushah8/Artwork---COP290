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

	// Constructor 
	Edge_P(Point2 &point1, Point2 &point2, int index, bool isHidden){
		if(!((point1.m_OnXY && point2.m_OnXY) || (point1.m_OnYZ && point2.m_OnYZ) || 
		    (point1.m_OnXZ && point2.m_OnXZ))){
			cout<<"\nWARNING: 2D Edge being formed by 2 non-XY || YZ || XZ planar Points.";
		}
		else{
			m_index = index;
			m_point1 = point1;
			m_point2 = point2;
			m_isHidden = isHidden;
		}
	}
	
	// print the point in the format "P1 : (3.0, 4.0, 5.0)"
	void print(){
		cout<<"\nE"<< m_index<<" : ";
		if(m_isHidden){
			cout<<"Hidden Line";	
		}
		else{
			cout<<"Visible Line";
		}
		m_point1.print();
		m_point2.print();
		return;
	}
	
	// returns if both edges are same or not
	bool isSame(Edge_P &edge){
		return (edge.m_point1.isSame(m_point1) && edge.m_point2.isSame(m_point2)) || (edge.m_point2.isSame(m_point1) && edge.m_point1.isSame(m_point2));
	}
	
};

#endif
