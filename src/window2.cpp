#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#define pb push_back
#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/freeglut.h>
#endif

#include "threeD_Fig.h"
#include "Point3.h"
#include "Point2.h"
#include "Line.h"
#include "Face.h"
#include "Edge.h"
#include "Edge_P.h"
#include "twoD_Fig.h"
#include "wireframe.h"
#include "window2.h"

using namespace std;
 
void displayw2(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_xw2, 1.0, 0.0, 0.0 );
  glRotatef( rotate_yw2, 0.0, 1.0, 0.0 );
 
  int numOfFaces = threeDfigw2.m_numOfFaces;

  // cout<<"\nThe number of faces are: "<<numOfFaces<<endl;
	
  for(int i=0;i<numOfFaces;i++){
	cout<<i<<endl;
	Face face = threeDfigw2.m_allFaces[i];
	// cout<<"face found\n";
	int numOfPoints = face.m_numOfsides;
	//cout<<"\nThe number of sides are: "<<numOfPoints<<endl;

	glBegin(GL_POLYGON);

	for(int i=0;i<numOfPoints;i++){
		Point3 point = face.m_allPoints[i];
		Vector3f coordinates = point.m_coordinates;
		glColor3f( 1.0, 1.0, 1.0 );     glVertex3f( coordinates(0),  coordinates(1), coordinates(2)); 
	}

	glEnd();
	
  }

  int numOfEdges = threeDfigw2.m_numOfEdges;
	
  for(int i=0;i<numOfEdges;i++){
	Point3 point1 = threeDfigw2.m_allEdges[i].m_point1;
	Point3 point2 = threeDfigw2.m_allEdges[i].m_point2;
	
	Vector3f coordinates1 = point1.m_coordinates;
	Vector3f coordinates2 = point2.m_coordinates;
	
	glLineWidth(5000);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(coordinates1(0),coordinates1(1),coordinates1(2));
		glVertex3f(coordinates2(0),coordinates2(1),coordinates2(2));
	glEnd();
  }


  glFlush();
  glutSwapBuffers();
 
}
 
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeysw2( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_yw2 += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_yw2 -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_xw2 += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_xw2 -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

void window3Dw2(){
	
	int i=0;	
	
	glutInit(&i,NULL);
 
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("3D Model");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(displayw2);
  	glutSpecialFunc(specialKeysw2);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 
 	glutMainLoop();

}

// 3d fIGURE------------------------------------------------------------------------------------

void display2DXYw2(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXYw2.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXYw2.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXYw2.m_allEdges[i].m_point2;
		bool isHidden = twoDFigXYw2.m_allEdges[i].m_isHidden;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		if(!(isHidden)){
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
		}
		else{
			glPushAttrib(GL_ENABLE_BIT);
			glLineStipple(5, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
			glPopAttrib();
		}
	}

  	glFlush();
  	glutSwapBuffers();
 
}

void display2DYZw2(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigYZw2.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigYZw2.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigYZw2.m_allEdges[i].m_point2;
		bool isHidden = twoDFigYZw2.m_allEdges[i].m_isHidden;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		if(!(isHidden)){
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
		}
		else{
			glPushAttrib(GL_ENABLE_BIT);
			glLineStipple(5, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
			glPopAttrib();
		}
	}

  	glFlush();
  	glutSwapBuffers();
 
}

void display2DXZw2(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXZw2.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXZw2.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXZw2.m_allEdges[i].m_point2;
		bool isHidden = twoDFigXZw2.m_allEdges[i].m_isHidden;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		if(!(isHidden)){
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
		}
		else{
			glPushAttrib(GL_ENABLE_BIT);
			glLineStipple(5, 0xAAAA);
			glEnable(GL_LINE_STIPPLE);
			glLineWidth(5000);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(coordinates1(0),coordinates1(1));
				glVertex2f(coordinates2(0),coordinates2(1));
			glEnd();
			glPopAttrib();
		}
	}

  	glFlush();
  	glutSwapBuffers();
 
}

void XYvieww2(){

	int i=0;
	glutInit(&i,NULL);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	

	glutCreateWindow("XY Projection");
  	glutInitWindowSize(1080, 1080);
   	glutInitWindowPosition(50, 50);
  	glutDisplayFunc(display2DXYw2);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 
 	glutMainLoop();
}

void YZvieww2(){

	int i=0;
	glutInit(&i,NULL);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	

	glutCreateWindow("YZ Projection");
  	glutInitWindowSize(1080, 1080);
   	glutInitWindowPosition(50, 50);
  	glutDisplayFunc(display2DYZw2);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 
 	glutMainLoop();
}

void XZvieww2(){

	int i=0;
	glutInit(&i,NULL);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	

	glutCreateWindow("XZ Projection");
  	glutInitWindowSize(1080, 1080);
   	glutInitWindowPosition(50, 50);
  	glutDisplayFunc(display2DXZw2);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 
 	glutMainLoop();
}


// 2d fIGURE------------------------------------------------------------------------------------


void displayWw2(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_xWw2, 1.0, 0.0, 0.0 );
  glRotatef( rotate_yWw2, 0.0, 1.0, 0.0 );
 
  int numOfEdges = newWireframew2.m_numOfEdges;
	
  for(int i=0;i<numOfEdges;i++){
	Point3 point1 = newWireframew2.m_allEdges[i].m_point1;
	Point3 point2 = newWireframew2.m_allEdges[i].m_point2;
	
	Vector3f coordinates1 = point1.m_coordinates;
	Vector3f coordinates2 = point2.m_coordinates;
	
	glLineWidth(50);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(coordinates1(0),coordinates1(1),coordinates1(2));
		glVertex3f(coordinates2(0),coordinates2(1),coordinates2(2));
	glEnd();
  }

  glFlush();
  glutSwapBuffers();
 
}

void specialKeysWw2( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_yWw2 += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_yWw2 -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_xWw2 += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_xWw2 -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

void windowWireframew2(){
	
	int i=0;	
	
	glutInit(&i,NULL);
 
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("Wireframe");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(displayWw2);
  	glutSpecialFunc(specialKeysWw2);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);
 
 	glutMainLoop();

}

