#define pb push_back

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "wireframe.h"
#include "threeD_Fig.h"

#include "graph.h"

using namespace Eigen;
using namespace std;
	
	threeD_Fig::threeD_Fig(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_numOfFaces = 0;	
	}

	
	
	bool threeD_Fig::addPoint(Point3 &point){
		if(point.m_index!=m_numOfPoints){
			cout<<"\nERROR : Illegal Indexing.";
			return false;
		}
		else{
			m_allPoints.pb(point);
			m_numOfPoints+=1;
		}
	}
	
	void threeD_Fig::resetLastPoint(){
		m_allPoints.pop_back();
		m_allEdges.clear();
		m_hiddenXY.clear();
		m_hiddenYZ.clear();
		m_hiddenXZ.clear();
		m_allFaces.clear();
		m_numOfPoints -= 1;
		m_numOfEdges = 0;
		m_numOfFaces = 0;
		return;
	}
	
	void threeD_Fig::resetAllPoints(){
		m_allPoints.clear();
		m_allEdges.clear();
		m_allFaces.clear();
		m_hiddenXY.clear();
		m_hiddenYZ.clear();
		m_hiddenXZ.clear();
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_numOfFaces = 0;
		return;
	}

	
	bool threeD_Fig::addEdge(int index1, int index2){
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
	
	void threeD_Fig::resetLastEdge(){
		m_allEdges.pop_back();
		m_allFaces.clear();
		m_numOfEdges -= 1;
		m_numOfFaces = 0;
		return;
	}
	
	void threeD_Fig::resetAllEdges(){
		m_allEdges.clear();
		m_allFaces.clear();
		m_numOfEdges = 0;
		m_numOfFaces = 0;
		return;
	}
	
	bool threeD_Fig::addFace(int numOfsides, vector<int> allIndexes){
		Face newFace(m_numOfFaces);
		for(int i=0;i<numOfsides;i++){
			if(!(newFace.addEdge(m_allEdges[allIndexes[i]]))){
				cout<<"\nERROR : Illegal Indexing while Loading Face";
				return false;
			}
		}
		m_numOfFaces+=1;		
		m_allFaces.pb(newFace);
		// cout<<"\nALL THE EDGES FOR THE FACE "<<newFace.m_index<<" : ";
		//for(int i=0;i<newFace.m_numOfsides;i++){
			//newFace.m_allEdges[i].print();
		//}
		// cout<<"\nALL THE POINTS FOR THE FACE "<<newFace.m_index<<" : ";
		//for(int i=0;i<newFace.m_numOfsides;i++){
			//newFace.m_allPoints[i].print();
		//}
		if(!(newFace.isComplete())){
			cout<<"\nERROR: Incomplete Face";
			return false;
		}
		return true;
	}
	
	void threeD_Fig::resetLastFace(){
		m_allFaces.pop_back();
		m_numOfFaces -= 1;
		return;
	}
	
	void threeD_Fig::resetAllFaces(){
		m_allFaces.clear();
		m_numOfFaces = 0;
		return;
	}

	void threeD_Fig::rotateX(double angle){
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

	void threeD_Fig::rotateY(double angle){
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

	void threeD_Fig::rotateZ(double angle){
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
	
	wireframe threeD_Fig::convertToWireframe(){
		wireframe output;
				
		for(int i=0;i<m_numOfPoints;i++){
			output.addPoint(m_allPoints[i]);	
		}	
		// cout<<"\n\nHidden Edgessssssssssssssssssssssssssssssssssssssssssssss\n\n";
		for(int i=0;i<m_numOfEdges;i++){
			Edge edge = m_allEdges[i];
			m_hiddenXY.pb(false);
			m_hiddenYZ.pb(false);
			m_hiddenXZ.pb(false);
			// cout<<"\n\n\n Checking For Edge,";
			// edge.print();
			for(int j=0;j<m_numOfFaces;j++){
				Face face = m_allFaces[j];
				// cout<<"\n\n\n Checking with Face";
				// face.print();
				if(!(m_hiddenXY[i])){
					m_hiddenXY[i] = face.isHiddenEdge(edge,0);
					if(m_hiddenXY[i]){
						// cout<<"\nYAYYAYAYATAYAYYAYAYAYAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYAYAYAYAY11111111111111111\n";
					}
				}
				if(!(m_hiddenYZ[i])){
					m_hiddenYZ[i] = face.isHiddenEdge(edge,1);
				}
				if(!(m_hiddenXZ[i])){
					m_hiddenXZ[i] = face.isHiddenEdge(edge,2);
				}
				if(m_hiddenXY[i] && m_hiddenYZ[i] && m_hiddenXZ[i]){
					break;
				}
			}
		}
		// cout<<"\n\nCompleted Process\n\n";
		for(int i=0;i<m_numOfEdges;i++){
			Edge edge = m_allEdges[i];
			int index1 = edge.m_point1.m_index;
			int index2 = edge.m_point2.m_index;
			output.addEdge3D(index1, index2, m_hiddenXY[i], m_hiddenYZ[i], m_hiddenXZ[i]);
		}
		output.m_modelOver = true;		
		return output;
	}

	void threeD_Fig::reconstruct(wireframe &wireframe){
		m_allPoints.clear();
		m_allEdges.clear();
		m_allFaces.clear();
		m_hiddenXY.clear();
		m_hiddenYZ.clear();
		m_hiddenXZ.clear();
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_numOfFaces = 0;

		cout<<"\n-------------------------------------3D Figure Reconstruct-------------------------------------------\n";
		
		int numOfPoints = wireframe.m_numOfPoints;
		int numOfEdges = wireframe.m_numOfEdges;
		
		cout<<"Number of Points : "<<numOfPoints<<endl;
		cout<<"Number of Edges : "<<numOfEdges<<endl;
		
		for(int i=0;i<numOfPoints;i++){
			cout<<"Points"<<i<<" ";
			Point3 point = wireframe.m_allPoints[i];
			addPoint(point);
		}
		
		cout<<endl;
		
		cout<<"Graph Trying\n";
		
		Graph connection(numOfPoints);
		
		cout<<"\n--------------------------------------GRAPH FORMED---------------------------------------------------\n";
		
		for(int i=0;i<numOfEdges;i++){
			Edge edge = wireframe.m_allEdges[i];
			int i1 = edge.m_point1.m_index;
			int i2 = edge.m_point2.m_index;
			cout<<"Edge:  "<<i1<<"   "<<i2<<endl;
			addEdge(i1,i2);
			connection.addEdge(i1,i2);
		}
		
		for(int i=0;i<numOfEdges;i++){
			Edge edge = wireframe.m_allEdges[i];
			int i1 = edge.m_point1.m_index;
			int i2 = edge.m_point2.m_index;
			
			cout<<"Checking for Edge:  "<<i1<<"   "<<i2<<endl;
			
			vector< vector< int > > paths1;
			
			connection.printAllPaths(i1,i2,paths1);
			
			int numOfPaths1 = paths1.size();
			
			cout<<"Num of Paths1: "<<numOfPaths1<<endl;
			
			for(int i=0;i<numOfPaths1;i++){
				vector<int> path = paths1[i];
				cout<<"Path1 Found : ";
				for(int i=0;i<path.size();i++){
					cout<<path[i]<<" ";
				}
				cout<<endl;
				int size = path.size();
				if(size>2){
					Face face(m_numOfFaces);
					int fl = 0;
					int in = path[0];
					Point3 first_point = m_allPoints[in];
					face.addFirstPoint(first_point);
					for(int j=1;j<size;j++){
						int in1 = path[j-1];
						int in2 = path[j];
						Point3 point1 = m_allPoints[in1];
						Point3 point2 = m_allPoints[in2];
						if(!(face.addPoints(point1,point2))){
							cout<<"\nSorry Not all Points on Plane\n";
							fl = 1;
							break;
						}
					}
					if(fl==0){
						m_allFaces.push_back(face);
						m_numOfFaces += 1;
					}
				}
			}
			
			vector< vector< int > > paths2;
			
			connection.printAllPaths(i2,i1,paths2);
			
			int numOfPaths2 = paths2.size();
			
			cout<<"Num of Paths1: "<<numOfPaths2<<endl;
			
			for(int i=0;i<numOfPaths2;i++){
				vector<int> path = paths2[i];
				cout<<"Path1 Found : ";
				for(int i=0;i<path.size();i++){
					cout<<path[i]<<" ";
				}
				cout<<endl;
				int size = path.size();
				if(size>2){
					Face face(m_numOfFaces);
					int fl = 0;
					int in = path[0];
					Point3 first_point = m_allPoints[in];
					face.addFirstPoint(first_point);
					for(int j=1;j<size;j++){
						int in1 = path[j-1];
						int in2 = path[j];
						Point3 point1 = m_allPoints[in1];
						Point3 point2 = m_allPoints[in2];
						if(!(face.addPoints(point1,point2))){
							cout<<"\nSorry Not all Points on Plane\n";
							fl = 1;
							break;
						}
					}
					if(fl==0){
						m_allFaces.push_back(face);
						m_numOfFaces += 1;
					}
				}
			}
		}
		
		
		
		cout<<"\n-------------------------------------3D Figure Reconstruct ENDS-------------------------------------------\n";
	}

