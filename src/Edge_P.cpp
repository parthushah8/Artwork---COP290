#include <iostream>
#include <Eigen/Dense>

#include "Point2.h"
#include "Point3.h"
#include "Line.h"
#include "Edge_P.h"

using namespace Eigen;
using namespace std;


	

	Edge_P::Edge_P(Point2 &point1, Point2 &point2, int index, bool isHidden){
		// Constructor 
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
	
	void Edge_P::print(){
		// print the point in the format "P1 : (3.0, 4.0, 5.0)"
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
	
	bool Edge_P::isSame(Edge_P &edge){
		// returns if both edges are same or not
		return (edge.m_point1.isSame(m_point1) && edge.m_point2.isSame(m_point2)) || (edge.m_point2.isSame(m_point1) && edge.m_point1.isSame(m_point2));
	}
