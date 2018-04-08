#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

class Line{
	public:

	int m_index;// index of the Line
	
	Vector3d m_intercept;// a, b, c or the Intercepts of the line
	Vector3d m_directionCosine;// l, m, n or the direction cosine of the line 
	
	Line(double a, double b, double c, double l, double m, double n, int index);
	
	void printLine();
	
	bool isSame(Line &line);
};

#endif
