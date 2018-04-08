#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "wireframe.h"

using namespace Eigen;
using namespace std;

wireframe newWireframe;

void display();
void specialKeys();

double rotate_y=0; 
double rotate_x=0;
 
void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  int numOfEdges = newWireframe.m_numOfEdges;
	
  for(int i=0;i<numOfEdges;i++){
	Point3 point1 = newWireframe.m_allEdges[i].m_point1;
	Point3 point2 = newWireframe.m_allEdges[i].m_point2;
	
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
 
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

int main(int argc, char* argv[]){
  
  	glutInit(&argc,argv);
 
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	
  	// Test Case 1 -- Cube
  	
  	Point3 point1(0.0f,0.0f,0.0f,0);
  	Point3 point2(0.0f,0.5f,0.0f,1);
  	Point3 point3(0.5f,0.5f,0.0f,2);
  	Point3 point4(0.5f,0.0f,0.0f,3);
  	Point3 point5(0.5f,0.0f,0.5f,4);
  	Point3 point6(0.0f,0.0f,0.5f,5);
  	Point3 point7(0.0f,0.5f,0.5f,6);
  	Point3 point8(0.5f,0.5f,0.5f,7);
  	
  	newWireframe.addPoint(point1);
  	newWireframe.addPoint(point2);
  	newWireframe.addPoint(point3);
  	newWireframe.addPoint(point4);
  	newWireframe.addPoint(point5);
  	newWireframe.addPoint(point6);
  	newWireframe.addPoint(point7);
  	newWireframe.addPoint(point8);
  	
  	newWireframe.addEdge(0,1);
  	newWireframe.addEdge(1,2);
  	newWireframe.addEdge(2,3);
  	newWireframe.addEdge(3,4);
  	newWireframe.addEdge(4,5);
  	newWireframe.addEdge(5,6);
  	newWireframe.addEdge(6,7);
  	newWireframe.addEdge(7,4);
  	newWireframe.addEdge(0,3);
  	newWireframe.addEdge(0,5);
  	newWireframe.addEdge(1,6);
  	newWireframe.addEdge(2,7);
  	
  	newWireframe.Complete();
  	
  	// Test Case Ends Here
 
	glutCreateWindow("Wireframe");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(display);
  	glutSpecialFunc(specialKeys);
 
 	glutMainLoop();
  return 0;
}
