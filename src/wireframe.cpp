#define pb push_back
#define mp make_pair

#include <bits/stdc++.h>
#include <Eigen/Dense>

#include "Point3.h"
#include "Edge.h"
#include "Face.h"
#include "twoD_Fig.h"
#include "wireframe.h"
// #include "threeD_Fig.h"

using namespace Eigen;
using namespace std;

	
	wireframe::wireframe(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_modelOver=false;	
	}

	void wireframe::clear(){
		m_numOfPoints = 0;
		m_numOfEdges = 0;
		m_modelOver=false;
		m_allEdges.clear();
		m_allPoints.clear();
		m_hiddenXY.clear();
		m_hiddenYZ.clear();
		m_hiddenXZ.clear();
		return;
	}
	
	bool wireframe::addPoint(Point3 &point){
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
	
	bool wireframe::addEdge(int index1, int index2){
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

	bool wireframe::addEdge3D(int index1,int index2,bool isHiddenXY,bool isHiddenYZ,bool isHiddenXZ){
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
	
	bool wireframe::Complete(){
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
	
	twoD_Fig wireframe::projectXY(){
		// converts wireframe to XY 2D figure
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
	
	twoD_Fig wireframe::projectYZ(){
		// converts wireframe to YZ 2D figure
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
	
	twoD_Fig wireframe::projectXZ(){
		// converts wireframe to XZ 2D figure
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
	
/*
	twoD_Fig projectIsoView(){
		// converts wireframe to ISO 2D figure
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
	}*/

	bool wireframe::regenerate(twoD_Fig XYproj, twoD_Fig YZproj, twoD_Fig XZproj){
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
			//threeDpoint.print();

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
	
/*
	threeD_Fig construct(){
		threeD_fig model;
		if(!m_modelOver){
			cout<<"\nModel Not Over Yet\n";
		}
		for(int i=0;i<m_numOfPoints;i++){
			model.addPoint(m_allPoints[i]);
		}
		Graph<int> vertices;
		for(int i=0;i<m_numOfEdges;i++){
			Edge edge = m_allEdges[i];
			int i1 = edge.m_poin1.m_index;
			int i2 = edge.m_poin2.m_index;
			model.addEdge(i1,i2);
			vertices.addEdge(i1,i2);
		}
		
	}
*/
