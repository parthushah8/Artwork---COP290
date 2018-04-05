#ifndef FACE_H
#define FACE_H

#define pb push_back
#define INF 10000.0

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"

using namespace Eigen;
using namespace std;

class Face{
	private:
	
	struct Point
	{
    	double x;
    	double y;
	};
	
	bool onSegment(Point p, Point q, Point r){
    	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    	return false;
	}
	
	int orientation(Point p, Point q, Point r){
    	double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
 
    	if (val == 0) return 0;  // colinear
    	return (val > 0)? 1: 2; // clock or counterclock wise
	}
	
	bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    	// Find the four orientations needed for general and
    	// special cases
    	int o1 = orientation(p1, q1, p2);
    	int o2 = orientation(p1, q1, q2);
    	int o3 = orientation(p2, q2, p1);
    	int o4 = orientation(p2, q2, q1);
 
    	// General case
    	if (o1 != o2 && o3 != o4)
    	    return true;
 
    	// Special Cases
    	// p1, q1 and p2 are colinear and p2 lies on segment p1q1
    	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    	// p1, q1 and p2 are colinear and q2 lies on segment p1q1
    	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    	// p2, q2 and p1 are colinear and p1 lies on segment p2q2
    	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     	// p2, q2 and q1 are colinear and q1 lies on segment p2q2
    	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 	
    	return false; // Doesn't fall in any of the above cases
	}
	
	bool isInside(Point polygon[], int n, Point p){
    	// There must be at least 3 vertices in polygon[]
    	if (n < 3)  return false;
 
    	// Create a point for line segment from p to infinite
    	Point extreme = {INF, p.y};
 
    	// Count intersections of the above line with sides of polygon
    	int count = 0, i = 0;
    	do{
        	int next = (i+1)%n;
 
	        // Check if the line segment from 'p' to 'extreme' intersects
	        // with the line segment from 'polygon[i]' to 'polygon[next]'
	        if (doIntersect(polygon[i], polygon[next], p, extreme)){
            	// If the point 'p' is colinear with line segment 'i-next',
            	// then check if it lies on segment. If it lies, return true,
            	// otherwise false
            	if (orientation(polygon[i], p, polygon[next]) == 0)
               		return onSegment(polygon[i], p, polygon[next]);
	            count++;
        	}
        	i = next;
    	} while (i != 0);
 
    	// Return true if count is odd, false otherwise
    	return count&1;  // Same as (count%2 == 1)
	}
	
	public:
	
	int m_index;
	int m_numOfsides;
	bool m_isComplete;
	
	vector< Edge> m_allEdges;
	vector< int> m_pointIndex;
	vector< Point3> m_allPoints;

	double a;
	double b;
	double c;
	
	double d;
	
	Face(int index){
		m_index = index;
		m_numOfsides = 0;
		m_isComplete = false;
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
	
	bool addEdge(Edge &edge){
		getPlane();
		if(m_isComplete){
			cout<<"\nERROR: Face already complete.";
			return false;
		}
		else if(m_numOfsides == 0){
			m_allEdges.pb(edge);
			m_numOfsides+=1;
			m_pointIndex.pb(edge.m_point1.m_index);
			m_pointIndex.pb(edge.m_point2.m_index);
			m_allPoints.pb(edge.m_point1);
			m_allPoints.pb(edge.m_point2);
			return true;
		}
		else if(m_numOfsides == 1){
			int i1 = edge.m_point1.m_index;
			int i2 = edge.m_point2.m_index;
			if(i1 == m_pointIndex[m_numOfsides]){
				m_pointIndex.pb(i2);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point2);
				m_numOfsides+=1;
				return true;
			}
			else if(i2 == m_pointIndex[m_numOfsides]){
				m_pointIndex.pb(i1);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point1);
				m_numOfsides+=1;
				return true;
			}
			else if(i1 == m_pointIndex[0]){
				m_pointIndex.pb(i2);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point2);
				m_numOfsides+=1;
				m_pointIndex[0]=m_pointIndex[1];
				m_allPoints[0]=m_allPoints[1];
				m_pointIndex[1]=i1;
				m_allPoints[1]=edge.m_point1;
				return true;
			}
			else if(i2 == m_pointIndex[0]){
				m_pointIndex.pb(i1);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point1);
				m_numOfsides+=1;
				m_pointIndex[0]=m_pointIndex[1];
				m_allPoints[0]=m_allPoints[1];
				m_pointIndex[1]=i2;
				m_allPoints[1]=edge.m_point2;
				return true;
			}
			else{
				cout<<"\nERROR : Improper Indexing for Face.";
				return false;
			}
		}
		else{
			int i1 = edge.m_point1.m_index;
			int i2 = edge.m_point2.m_index;
			int prev_i = m_pointIndex[m_numOfsides];
			int first_i = m_pointIndex[0];
			if(prev_i == i1){
				m_pointIndex.pb(i2);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point2);
				m_numOfsides+=1;
				return true;
			}
			else if(prev_i == i2){
				m_pointIndex.pb(i1);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point1);
				m_numOfsides+=1;
				return true;
			}
			else if(first_i == i1){
				m_pointIndex.pb(i2);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point2);
				m_numOfsides+=1;
				
				m_isComplete = true;
				
				return true;
			}
			else if(first_i == i2){
				m_pointIndex.pb(i1);
				m_allEdges.pb(edge);
				m_allPoints.pb(edge.m_point1);
				m_numOfsides+=1;
				
				m_isComplete = true;
				
				return true;
			}
			else{
				cout<<"\nERROR : Improper Indexing for Face.\n";
				return false;
			}
		}
	}

	void getPlane(){
		if(m_numOfsides<3){
			cout<<"\nYou know what they all DONT say to you, it's short\n";
			return;
		}
		int p1=0;
		int p2=1;
		int p3=2;
		int fl=0;
		while(true){
			if((!(m_allPoints[p1].isSame(m_allPoints[p2]))) && fl==0){
				fl = 1;
				p3 = p2+1;
			}
			if((!(m_allPoints[p2].isSame(m_allPoints[p3]))) && fl==1){
				fl = 2;
			}
			if(fl==0){
				p2+=1;
			}
			else if(fl==1){
				p3+=1;
			}
			else{
				double x1 = m_allPoints[p1].m_coordinates(0);
				double y1 = m_allPoints[p1].m_coordinates(1);
				double z1 = m_allPoints[p1].m_coordinates(2);
		
				double x2 = m_allPoints[p2].m_coordinates(0);
				double y2 = m_allPoints[p2].m_coordinates(1);
				double z2 = m_allPoints[p2].m_coordinates(2);
		
				double x3 = m_allPoints[p3].m_coordinates(0);
				double y3 = m_allPoints[p3].m_coordinates(1);
				double z3 = m_allPoints[p3].m_coordinates(2);
		
				double v1_1 = x1 - x2;
				double v1_2 = y1 - y2;
				double v1_3 = z1 - z2;
		
				double v2_1 = x3 - x2;
				double v2_2 = y3 - y2;
				double v2_3 = z3 - z2;
		
				a = (v1_2 * v2_3) - (v1_3 * v2_2);
				b = -((v1_1 * v2_3) - (v1_3 * v2_1));
				c = (v1_1 * v2_2) - (v1_2 * v2_1); 
				
				if(a==0 && b==0 && c==0){
					cout<<"\nCoolinear Points\n";
					fl = 1;
					p3 = p3+1;
					continue;			
				}
		
				d = (a * x1) + (b * y1) + (c * z1);
		
				double sq = sqrt((a*a)+(b*b)+(c*c));
		
				a = a/sq;
				b = b/sq;
				c = c/sq;
		
				d = d/sq; 
		
				return;	
			}
		}
	}
	
	Point3 project(Point3 &point){
		
		double x = point.m_coordinates(0);
		double y = point.m_coordinates(1);
		double z = point.m_coordinates(2); 
		
		if((a*x + b*y + c*z) == d){
			cout<<"\nPoint Already on the Plane\n";
			return point;
		}
		
		double x1 = m_allPoints[0].m_coordinates(0);
		double y1 = m_allPoints[0].m_coordinates(1);
		double z1 = m_allPoints[0].m_coordinates(2);
		
		double vx = x - x1;
		double vy = y - y1;
		double vz = z - z1;
		
		double dist = vx*a + vy*b + vz *c;
		
		double xn = x - (dist * a);
		double yn = y - (dist * b);
		double zn = z - (dist * c);
		
		return Point3(xn,yn,zn,point.m_index);
	}

   	bool isOnFace(Point3 &point){
   		for(int i=0;i<m_numOfsides;i++){
   			if(m_allEdges[i].isOnEdge(point)){
   				return true;
   			}
   		}
   		return false;
   	}

	bool isHidden(Point3 &point,int view){
		if(view == 0){// XY
			double x = point.m_coordinates(0);
			double y = point.m_coordinates(1);
			double z = point.m_coordinates(2);
			
			cout<<"\n\nChecking For point is hidden on XY Face.\n";
			point.print();
			
			if(c > 0){
				cout<<"\nC is positive: "<<c<<endl;
				if((c*z-d)>0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(0);
					double c2 = newPoint.m_coordinates(1);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(0);
						double c2i = m_allPoints[i].m_coordinates(1);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else if(c < 0){
				if((c*z-d)<0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(0);
					double c2 = newPoint.m_coordinates(1);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(0);
						double c2i = m_allPoints[i].m_coordinates(1);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else{
				return false; // line in projection
			}
		}
		else if(view == 1){// YZ
			double x = point.m_coordinates(0);
			double y = point.m_coordinates(1);
			double z = point.m_coordinates(2);
			
			if(a > 0){
				if((a*x-d)>0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(1);
					double c2 = newPoint.m_coordinates(2);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(1);
						double c2i = m_allPoints[i].m_coordinates(2);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else if(a < 0){
				if((a*x-d)<0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(1);
					double c2 = newPoint.m_coordinates(2);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(1);
						double c2i = m_allPoints[i].m_coordinates(2);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else{
				return false; // line in projection
			}
		}
		else if(view ==2){// XZ
			double x = point.m_coordinates(0);
			double y = point.m_coordinates(1);
			double z = point.m_coordinates(2);
			
			if(b > 0){
				if((b*y-d)>0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(0);
					double c2 = newPoint.m_coordinates(2);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(0);
						double c2i = m_allPoints[i].m_coordinates(2);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else if(b < 0){
				if((b*y-d)<0){
				return false;
				}
				else{
					Point3 newPoint = project(point);
					double c1 = newPoint.m_coordinates(0);
					double c2 = newPoint.m_coordinates(2);
					
					Point check = {c1,c2};
					
					Point polygon[m_numOfsides];
					
					for(int i=0;i<m_numOfsides;i++){
						double c1i = m_allPoints[i].m_coordinates(0);
						double c2i = m_allPoints[i].m_coordinates(2);
						polygon[i] = {c1i,c2i};
					}
					
					return isInside(polygon, m_numOfsides, check);
					
				}
			}
			else{
				return false; // line in projection
			}
		}
		else{
			cout<<"\nIllegal passing of view "<<view<<endl;
			return false;
		}
	}

	bool isHiddenEdge(Edge &edge,int view){

		for(int i=0;i<m_numOfsides;i++){
			Edge edgeF = m_allEdges[i];
			if(edgeF.isSame(edge)){
				//cout<<"\n\n\n SAME EDGEeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee \n\n\n";
				return false;
			}
		}
		
		cout<<"\n\nNot Same Edge\n";
		
		Point3 point1=edge.m_point1;
		Point3 point2=edge.m_point2;
		
		double x1 = point1.m_coordinates(0);
		double y1 = point1.m_coordinates(1);
		double z1 = point1.m_coordinates(2);
		
		double x2 = point2.m_coordinates(0);
		double y2 = point2.m_coordinates(1);
		double z2 = point2.m_coordinates(2);
		
		double xm = (x1+x2)/2;
		double ym = (y1+y2)/2;
		double zm = (z1+z2)/2;
		
		Point3 pointm = Point3(xm,ym,zm,0);
		
		if(isOnFace(point1)){
			cout<<"\n\nPoint1 on the Plane";
			if(isOnFace(point2)){
				cout<<"\n\nBoth Points on the plane";
				return isHidden(pointm,view);
			}
			else{
				cout<<"\n\nPoint2 not on the plane";
				return (isHidden(point2,view) || isHidden(pointm,view));
			}
		}
		
		if(isOnFace(point2)){
			cout<<"\n\nPoint2 on the Plane";
			if(isOnFace(point1)){
				cout<<"\n\nBoth Points on the plane";
				return isHidden(pointm,view);
			}
			else{
				cout<<"\n\nPoint1 not on the plane";
				return (isHidden(point1,view) || isHidden(pointm,view));
			}
		}
		
		cout<<"\n\nNo point on the plane\n";
		
		return (isHidden(point1,view) || isHidden(point2,view));
	}
	
	
	void print(){
		cout<<"\nF"<<m_index<<" : Points On it are";
		for(int i=0;i<m_numOfsides;i++){
			m_allPoints[i].print();
		} 
		cout<<"Edges On it are";
		for(int i=0;i<m_numOfsides;i++){
			m_allEdges[i].print();
		} 
	}

	bool isComplete(){
		return m_isComplete;
	}
};

#endif
