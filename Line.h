#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

class Line{
	public:
	
	// Line is of the form 
	//      (x - a)   (y - b)   (z - c)
	// L1 : ------- = ------- = ------- = k
	//         l         m         n

	int m_index;// index of the Line
	
	Vector3d m_intercept;// a, b, c or the Intercepts of the line
	Vector3d m_directionCosine;// l, m, n or the direction cosine of the line 
	
	// Constructor with default Intercepts as 0 and default direction Cosines as 1 
	Line(double a=0, double b=0, double c=0, double l=1, double m=1, double n=1, int index=1){
		m_index = index;
		m_intercept << a, b, c;
		m_directionCosine << l, m, n;
	}
	
	
	// Printts in the format given above
	void printLine(){
		cout<<"\n";
		cout<<"      (x - "<< m_intercept(0) <<")   (y - "<< m_intercept(1) <<")   (z - "<< 
			  m_intercept(1) <<")\n";
		cout<<" L"<< m_index <<" : ------- = ------- = ------- = k\n";
		cout<<"         "<< m_directionCosine(0) <<"         "<< m_directionCosine(1) <<
			  "         "<< m_directionCosine(2) <<"\n";
		return;
	}
	
	// returns true if both the lines are same
	bool isSame(Line &line){
		return 	(line.m_intercept(0) == m_intercept(0)) && 
				(line.m_intercept(1) == m_intercept(1)) &&
			   	(line.m_intercept(2) == m_intercept(2)) && 
			   	(line.m_directionCosine(0) == m_directionCosine(0)) && 
			   	(line.m_directionCosine(1) == m_directionCosine(1)) && 
			   	(line.m_directionCosine(2) == m_directionCosine(2));
	}

};

#endif
