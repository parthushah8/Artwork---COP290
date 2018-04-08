#ifndef WIREFRAME_H
#define WIREFRAME_H

#define pb push_back
#define mp make_pair

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "twoD_Fig.h"

using namespace Eigen;
using namespace std;

class wireframe{
	public:
	
	vector< Point3> m_allPoints;
	int m_numOfPoints;
	vector< Edge> m_allEdges;
	vector< bool> m_hiddenXY;
	vector< bool> m_hiddenYZ;
	vector< bool> m_hiddenXZ;
	
	int m_numOfEdges;
	bool m_modelOver;

	set< pair<int, int> > edgesPresent;
	
	wireframe(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_modelOver=false;	
	}
	
	bool addPoint(Point3 &point){
		if(m_modelOver){
			cout<<"ERROR: Model already present\n";
			return false;
		}
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
		if(m_modelOver){
			cout<<"ERROR: Model already present\n";
			return false;
		}
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

	bool addEdge3D(int index1,int index2,bool isHiddenXY,bool isHiddenYZ,bool isHiddenXZ){
		if(m_modelOver){
			cout<<"ERROR: Model already present\n";
			return false;
		}
		if(index1 >= m_numOfPoints || index2 >= m_numOfPoints){
			cout<<"\nERROR : Point Indexing not Proper.";
			return false;
		}
		if(index1 == index2){
			cout<<"\nERROR : Same Point Mentioned Twice.";
			return false;
		}
		m_allEdges.pb(Edge(m_allPoints[index1],m_allPoints[index2],m_numOfEdges));
		m_hiddenXY.pb(isHiddenXY);
		m_hiddenYZ.pb(isHiddenYZ);
		m_hiddenXZ.pb(isHiddenXZ);
		m_numOfEdges+=1;
		return false;
	}
	
	bool Complete(){
		if(m_modelOver){
			cout<<"ERROR: Model already present\n";
			return false;
		}
		if(m_numOfPoints==0 || m_numOfEdges==0){
			cout<<"ERROR: Model not Complete, 0 Points or Edges\n";
			return false;
		}
		m_modelOver=true;
		return true;
	}
	
	// converts wireframe to XY 2D figure
	twoD_Fig projectXY(){
		if(!m_modelOver){
			cout<<"ERROR: Model not complete\n";
		}
		twoD_Fig XYproj(true,false,false,false);
		for(int i=0;i<m_numOfPoints;i++){
			Point2 XYpoint =m_allPoints[i].projectOnXY(); 
			XYproj.addPoint(XYpoint);				
		}
		for(int i=0;i<m_numOfEdges;i++){
			XYproj.addEdge(m_allEdges[i].m_point1.m_index, m_allEdges[i].m_point2.m_index, m_hiddenXY[i]);
		}
		return XYproj;
	}
	
	// converts wireframe to YZ 2D figure
	twoD_Fig projectYZ(){
		if(!m_modelOver){
			cout<<"ERROR: Model not complete\n";
		}
		twoD_Fig YZproj(false,true,false,false);
		for(int i=0;i<m_numOfPoints;i++){
			Point2 YZpoint =m_allPoints[i].projectOnYZ(); 
			YZproj.addPoint(YZpoint);				
		}
		for(int i=0;i<m_numOfEdges;i++){
			YZproj.addEdge(m_allEdges[i].m_point1.m_index, m_allEdges[i].m_point2.m_index, m_hiddenYZ[i]);
		}
		return YZproj;
	}
	
	// converts wireframe to XZ 2D figure
	twoD_Fig projectXZ(){
		if(!m_modelOver){
			cout<<"ERROR: Model not complete\n";
		}
		twoD_Fig XZproj(false,false,true,false);
		for(int i=0;i<m_numOfPoints;i++){
			Point2 XZpoint =m_allPoints[i].projectOnXZ(); 
			XZproj.addPoint(XZpoint);				
		}
		for(int i=0;i<m_numOfEdges;i++){
			XZproj.addEdge(m_allEdges[i].m_point1.m_index, m_allEdges[i].m_point2.m_index, m_hiddenXZ[i]);
		}
		return XZproj;
	}
	
	// converts wireframe to ISO 2D figure
	twoD_Fig projectIsoView(){
		if(!m_modelOver){
			cout<<"ERROR: Model not complete\n";
		}
		twoD_Fig IsoView(false,false,false,true);
		for(int i=0;i<m_numOfPoints;i++){
			Point2 Isopoint =m_allPoints[i].isoView(); 
			IsoView.addPoint(Isopoint);				
		}
		for(int i=0;i<m_numOfEdges;i++){
			IsoView.addEdge(m_allEdges[i].m_point1.m_index, m_allEdges[i].m_point2.m_index, false);
		}
		return IsoView;
	}

	bool regenerate(twoD_Fig XYproj, twoD_Fig YZproj, twoD_Fig XZproj){
		if(m_modelOver){
			cout<<"ERROR: Model already complete\n";
			return false;
		}		
		if(! ((XYproj.m_numOfPoints == YZproj.m_numOfPoints) && (YZproj.m_numOfPoints == XZproj.m_numOfPoints)) ){
			cout<<"ERROR: All projection dont have same number of points";
			return false;
}
		int numOfPoints = XYproj.m_numOfPoints;
		for(int i=0;i<numOfPoints;i++){
			Point2 XYpoint = XYproj.m_allPoints[i];
			Point2 YZpoint = YZproj.m_allPoints[i];
			Point2 XZpoint = XZproj.m_allPoints[i];
			
			Point3 threeDpoint;

			threeDpoint.regenerate3(XYpoint, YZpoint, XZpoint);

			cout<<"\n";
			threeDpoint.print();

			addPoint(threeDpoint);			 
		}

		for(int i=0;i<XYproj.m_numOfEdges;i++){
			Edge_P edge = XYproj.m_allEdges[i];
			int index1 = edge.m_point1.m_index;
			int index2 = edge.m_point2.m_index;
			edgesPresent.insert(mp(index1, index2));
			addEdge(index1, index2);
		}

		for(int i=0;i<YZproj.m_numOfEdges;i++){
			Edge_P edge = YZproj.m_allEdges[i];
			int index1 = edge.m_point1.m_index;
			int index2 = edge.m_point2.m_index;
			bool is_present = (edgesPresent.find(mp(index1,index2)) != edgesPresent.end()) || (edgesPresent.find(mp(index2,index1)) != edgesPresent.end()); 
			if(!is_present){
				edgesPresent.insert(mp(index1, index2));				
				addEdge(index1, index2);
			}
		}

		for(int i=0;i<XZproj.m_numOfEdges;i++){
			Edge_P edge = XZproj.m_allEdges[i];
			int index1 = edge.m_point1.m_index;
			int index2 = edge.m_point2.m_index;
			bool is_present = (edgesPresent.find(mp(index1,index2)) != edgesPresent.end()) || (edgesPresent.find(mp(index2,index1)) != edgesPresent.end()); 
			if(!is_present){
				edgesPresent.insert(mp(index1, index2));				
				addEdge(index1, index2);
			}
		}
		
		m_modelOver = true;

		return true;
	}

};

#endif
