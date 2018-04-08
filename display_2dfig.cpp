#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

 #include "twoD_Fig.h"

using namespace Eigen;
using namespace std;

twoD_Fig twoDFigXY(true, false, false, false);

void display2DXY(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXY.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXY.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXY.m_allEdges[i].m_point2;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		glLineWidth(50);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex2f(coordinates1(0),coordinates1(1));
			glVertex2f(coordinates2(0),coordinates2(1));
		glEnd();
	}

  	glFlush();
  	glutSwapBuffers();
 
}

twoD_Fig twoDFigYZ(true, false, false, false);

void display2DYZ(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigYZ.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigYZ.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigYZ.m_allEdges[i].m_point2;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		glLineWidth(50);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex2f(coordinates1(0),coordinates1(1));
			glVertex2f(coordinates2(0),coordinates2(1));
		glEnd();
	}

  	glFlush();
  	glutSwapBuffers();
 
}

twoD_Fig twoDFigXZ(true, false, false, false);

void display2DXZ(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXZ.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXZ.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXZ.m_allEdges[i].m_point2;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		glLineWidth(50);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex2f(coordinates1(0),coordinates1(1));
			glVertex2f(coordinates2(0),coordinates2(1));
		glEnd();
	}

  	glFlush();
  	glutSwapBuffers();
 
}

twoD_Fig twoDFigIso(true, false, false, false);

void display2DIso(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigIso.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigIso.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigIso.m_allEdges[i].m_point2;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		glLineWidth(50);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex2f(coordinates1(0),coordinates1(1));
			glVertex2f(coordinates2(0),coordinates2(1));
		glEnd();
	}

  	glFlush();
  	glutSwapBuffers();
 
}

int main(int argc, char* argv[]){
	
	glutInit(&argc,argv);
  	//  Request double buffered true color window with Z-buffer
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	
  	//------------FOR XY Projection------------------------//
  	//------------Taking Inputs----------------------------//
	
	// Test Case1 -- Quadrilateral
	//Point2 point1(-0.5f, 0.0f, 0, true, false, false, false);
	//Point2 point2(0.0f, 0.5f, 1, true, false, false, false);
	//Point2 point3(0.5f, 0.5f, 2, true, false, false, false);
	//Point2 point4(0.5f, 0.0f, 3, true, false, false, false);

	//twoDFigXY.addPoint(point1);
	//twoDFigXY.addPoint(point2);
	//twoDFigXY.addPoint(point3);
	//twoDFigXY.addPoint(point4);

	//twoDFigXY.addEdge(0,1,false);
	//twoDFigXY.addEdge(1,2,false);
	//twoDFigXY.addEdge(2,3,false);
	//twoDFigXY.addEdge(3,0,false);
	
	
	
	
	// Test Case End here
	
	//----------------END HERE------------------------------//
	
  	// Create window
  	if(twoDFigXY.m_OnXY){
  		twoDFigXY.clear();
  		glutCreateWindow("XY Projection");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DXY);
 	}
 	else if(twoDFigXY.m_OnYZ){
  		glutCreateWindow("YZ Projection");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DYZ);
 	}
 	else if(twoDFigXY.m_OnXZ){
  		glutCreateWindow("XZ Projection");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DXZ);
 	}
 	else if(twoDFigXY.m_IsoView){
  		glutCreateWindow("Isometric View");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DIso);
 	}
  	glutMainLoop();
  	return 0;
}
