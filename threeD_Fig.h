#ifndef THREED_FIG_H
#define THREED_FIG_H

#define pb push_back

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "wireframe.h"

using namespace Eigen;
using namespace std;

class threeD_Fig{
	public:
	
	vector< Point3> m_allPoints;
	int m_numOfPoints;
	vector< Edge> m_allEdges;
	vector< bool> m_hiddenXY;
	vector< bool> m_hiddenYZ;
	vector< bool> m_hiddenXZ;
	int m_numOfEdges;
	vector< Face> m_allFaces;
	int m_numOfFaces;
	
	threeD_Fig(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_numOfFaces = 0;	
	}
	
	bool addPoint(Point3 &point){
		if(point.m_index!=m_numOfPoints){
			cout<<"\nERROR : Illegal Indexing.";
			return false;
		}
		else{
			m_allPoints.pb(point);
			m_numOfPoints+=1;
		}
	}
	
	bool addEdge(int index1, int index2){
		if(index1 >= m_numOfPoints || index2 >= m_numOfPoints){
			cout<<"\nERROR : Point Indexing not Proper.";
			return false;
		}
		if(index1 == index2){
			cout<<"\nERROR : Same Point Mentioned Twice.";
			return false;
		}
		m_allEdges.pb(Edge(m_allPoints[index1],m_allPoints[index2],m_numOfEdges));
		m_numOfEdges+=1;
		return false;
	}
	
	bool addFace(int numOfsides, vector<int> allIndexes){
		Face newFace(m_numOfFaces);
		int i=0;
		for(int i=0;i<numOfsides;i++){
			if(!(newFace.addEdge(m_allEdges[allIndexes[i]]))){
				cout<<"\nERROR : Illegal Indexing while Loading Face";
				return false;
			}
		}
		m_numOfFaces+=1;		
		m_allFaces.pb(newFace);
		cout<<"\nALL THE EDGES FOR THE FACE "<<newFace.m_index<<" : ";
		for(int i=0;i<newFace.m_numOfsides;i++){
			newFace.m_allEdges[i].print();
		}
		cout<<"\nALL THE POINTS FOR THE FACE "<<newFace.m_index<<" : ";
		for(int i=0;i<newFace.m_numOfsides;i++){
			newFace.m_allPoints[i].print();
		}
		if(!(newFace.isComplete())){
			cout<<"\nERROR: Incomplete Face";
			return false;
		}
		return true;
	}

	void rotateX(double angle){
		vector< Point3> t_m_allPoints = m_allPoints;
		int t_m_numOfPoints = m_numOfPoints;
		vector< Edge> t_m_allEdges = m_allEdges;
		int t_m_numOfEdges = m_numOfEdges;
		vector< Face> t_m_allFaces = m_allFaces;
		int t_m_numOfFaces = m_numOfFaces;
		
		m_allPoints.clear();
		m_numOfPoints = 0;
		m_allEdges.clear();
		m_numOfEdges = 0;
		m_allFaces.clear();
		m_numOfFaces = 0;

		for(int i=0;i<t_m_numOfPoints;i++){
			Point3 newPoint = t_m_allPoints[i].rotateX(angle); 
			addPoint(newPoint);
		}

		for(int i=0;i<t_m_numOfEdges;i++){
			addEdge(t_m_allEdges[i].m_point1.m_index,t_m_allEdges[i].m_point2.m_index);
		}
		for(int i=0;i<t_m_numOfFaces;i++){
			Face tempFace = t_m_allFaces[i];
			vector< int> tempallIndexes;
			tempallIndexes.clear();
			int k = tempFace.m_numOfsides;
			for(int i=0;i<k;i++){
				tempallIndexes.pb(tempFace.m_allEdges[i].m_index);			
			}
			addFace(k,tempallIndexes);
		}

		return;
	}

	void rotateY(double angle){
		vector< Point3> t_m_allPoints = m_allPoints;
		int t_m_numOfPoints = m_numOfPoints;
		vector< Edge> t_m_allEdges = m_allEdges;
		int t_m_numOfEdges = m_numOfEdges;
		vector< Face> t_m_allFaces = m_allFaces;
		int t_m_numOfFaces = m_numOfFaces;
		
		m_allPoints.clear();
		m_numOfPoints = 0;
		m_allEdges.clear();
		m_numOfEdges = 0;
		m_allFaces.clear();
		m_numOfFaces = 0;

		for(int i=0;i<t_m_numOfPoints;i++){
			Point3 newPoint = t_m_allPoints[i].rotateY(angle); 
			addPoint(newPoint);
		}

		for(int i=0;i<t_m_numOfEdges;i++){
			addEdge(t_m_allEdges[i].m_point1.m_index,t_m_allEdges[i].m_point2.m_index);
		}
		for(int i=0;i<t_m_numOfFaces;i++){
			Face tempFace = t_m_allFaces[i];
			vector< int> tempallIndexes;
			tempallIndexes.clear();
			int k = tempFace.m_numOfsides;
			for(int i=0;i<k;i++){
				tempallIndexes.pb(tempFace.m_allEdges[i].m_index);			
			}
			addFace(k,tempallIndexes);
		}

		return;
	}

	void rotateZ(double angle){
		vector< Point3> t_m_allPoints = m_allPoints;
		int t_m_numOfPoints = m_numOfPoints;
		vector< Edge> t_m_allEdges = m_allEdges;
		int t_m_numOfEdges = m_numOfEdges;
		vector< Face> t_m_allFaces = m_allFaces;
		int t_m_numOfFaces = m_numOfFaces;
		
		m_allPoints.clear();
		m_numOfPoints = 0;
		m_allEdges.clear();
		m_numOfEdges = 0;
		m_allFaces.clear();
		m_numOfFaces = 0;

		for(int i=0;i<t_m_numOfPoints;i++){
			Point3 newPoint = t_m_allPoints[i].rotateZ(angle); 
			addPoint(newPoint);
		}

		for(int i=0;i<t_m_numOfEdges;i++){
			addEdge(t_m_allEdges[i].m_point1.m_index,t_m_allEdges[i].m_point2.m_index);
		}
		for(int i=0;i<t_m_numOfFaces;i++){
			Face tempFace = t_m_allFaces[i];
			vector< int> tempallIndexes;
			tempallIndexes.clear();
			int k = tempFace.m_numOfsides;
			for(int i=0;i<k;i++){
				tempallIndexes.pb(tempFace.m_allEdges[i].m_index);			
			}
			addFace(k,tempallIndexes);
		}

		return;
	}
	
	wireframe convertToWireframe(){
		wireframe output;
				
		for(int i=0;i<m_numOfPoints;i++){
			output.addPoint(m_allPoints[i]);	
		}	
		for(int i=0;i<m_numOfEdges;i++){
			Edge edge = m_allEdges[i];
			m_hiddenXY.pb(false);
			m_hiddenYZ.pb(false);
			m_hiddenXZ.pb(false);
			if(i==4){
				cout<<"\n\nATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEENTION\n";	
				cout<<"\n\n\n Checking For Edge,";
				edge.print();
			}
			for(int j=0;j<m_numOfFaces;j++){
				Face face = m_allFaces[j];
				if(i==4 && j==0){
					cout<<"\n\n\n Checking with Face";
					face.print();
				}
				if(!(m_hiddenXY[i])){
					m_hiddenXY[i] = face.isHiddenEdge(edge,0);
					if(m_hiddenXY[i]){
						cout<<"\nYAYYAYAYATAYAYYAYAYAYAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYAYAYAYAY11111111111111111\n";
					}
				}
				if(!(m_hiddenYZ[i])){
					m_hiddenYZ[i] = face.isHiddenEdge(edge,1);
					if(m_hiddenYZ[i]){
						cout<<"\nYAYYAYAYATAYAYYAYAYAYAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYAYAYAYAY22222222222222222\n";
					}
				}
				if(!(m_hiddenXZ[i])){
					m_hiddenXZ[i] = face.isHiddenEdge(edge,2);
					if(m_hiddenXZ[i]){
						cout<<"\nYAYYAYAYATAYAYYAYAYAYAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYAYAYAYAY333333333333333333\n";
					}
				}
				if(m_hiddenXY[i] && m_hiddenYZ[i] && m_hiddenXZ[i]){
					break;
				}
				if(i==4 && j==0){
					cout<<"\n\nATTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEENTION\n";
				}
			}
		}
		for(int i=0;i<m_numOfEdges;i++){
			Edge edge = m_allEdges[i];
			int index1 = edge.m_point1.m_index;
			int index2 = edge.m_point2.m_index;
			output.addEdge3D(index1, index2, m_hiddenXY[i], m_hiddenYZ[i], m_hiddenXZ[i]);
		}
		output.m_modelOver = true;		
		return output;
	}

};

#endif
