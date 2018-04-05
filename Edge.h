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

	// Constructor 
	Edge(Point3 &point1, Point3 &point2, int index){
		m_index = index;
		m_point1 = point1;
		m_point2 = point2;
	}
	
	// rotates the edge around a line given some angle
	Edge rotate(Line &line, double angle){
		Point3 new_point1 = m_point1.rotate(line,angle);
		Point3 new_point2 = m_point2.rotate(line,angle);
		return Edge(new_point1, new_point2, m_index);
	}
	
	bool isOnEdge(Point3 &point){
	
		if(m_point1.isSame(point) || m_point2.isSame(point)){
			return true;
		}
	
		double x1 = m_point1.m_coordinates(0);
		double y1 = m_point1.m_coordinates(1);
		double z1 = m_point1.m_coordinates(2);
		
		double x2 = m_point2.m_coordinates(0);
		double y2 = m_point2.m_coordinates(1);
		double z2 = m_point2.m_coordinates(2);
		
		double x = point.m_coordinates(0);
		double y = point.m_coordinates(1);
		double z = point.m_coordinates(2);
		
		double v1_1 = x - x1;
		double v1_2 = y - y1;
		double v1_3 = z - z1;
		
		double v2_1 = x - x2;
		double v2_2 = y - y2;
		double v2_3 = z - z2;
		
		double a = (v1_2 * v2_3) - (v1_3 * v2_2);
		double b = -((v1_1 * v2_3) - (v1_3 * v2_1));
		double c = (v1_1 * v2_2) - (v1_2 * v2_1);
		
		return ((a==0) && (b==0) && (c==0));
		
	}

	// print the point in the format "P1 : (3.0, 4.0, 5.0)"
	void print(){
		cout<<"\nE"<< m_index<<" : ";
		m_point1.print();
		m_point2.print();
		return;
	}
	
	// returns if both edges are same or not
	bool isSame(Edge &edge){
		Point3 point1 = edge.m_point1;
		Point3 point2 = edge.m_point2;
		bool c11 = m_point1.isSame(point1);
		bool c22 = m_point2.isSame(point2);
		bool c12 = m_point1.isSame(point2);
		bool c21 = m_point2.isSame(point1);
		return ((c11 && c22) || (c12 && c21));
	}
	
};

#endif
