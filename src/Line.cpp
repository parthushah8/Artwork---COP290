#include <iostream>
#include <Eigen/Dense>

#include "Line.h"

using namespace Eigen;
using namespace std;

	
	Line::Line(double a, double b, double c, double l, double m, double n, int index){
		// Constructor with default Intercepts as 0 and default direction Cosines as 1 
		m_index = index;
		m_intercept << a, b, c;
		m_directionCosine << l, m, n;
	}
	
	void Line::printLine(){
		// Line is of the form 
		//      (x - a)   (y - b)   (z - c)
		// L1 : ------- = ------- = ------- = k
		//         l         m         n
		// Prints in the format given above
		cout<<"\n";
		cout<<"      (x - "<< m_intercept(0) <<")   (y - "<< m_intercept(1) <<")   (z - "<< 
			  m_intercept(1) <<")\n";
		cout<<" L"<< m_index <<" : ------- = ------- = ------- = k\n";
		cout<<"         "<< m_directionCosine(0) <<"         "<< m_directionCosine(1) <<
			  "         "<< m_directionCosine(2) <<"\n";
		return;
	}
	
	bool Line::isSame(Line &line){
		// returns true if both the lines are same
		return 	(line.m_intercept(0) == m_intercept(0)) && 
				(line.m_intercept(1) == m_intercept(1)) &&
			   	(line.m_intercept(2) == m_intercept(2)) && 
			   	(line.m_directionCosine(0) == m_directionCosine(0)) && 
			   	(line.m_directionCosine(1) == m_directionCosine(1)) && 
			   	(line.m_directionCosine(2) == m_directionCosine(2));
	}


