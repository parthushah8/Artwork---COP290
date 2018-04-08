#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#define pb push_back
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "threeD_Fig.h"

using namespace Eigen;
using namespace std;

threeD_Fig threeDfig;

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
 
  int numOfFaces = threeDfig.m_numOfFaces;

  cout<<"\nThe number of faces are: "<<numOfFaces<<endl;
	
  for(int i=0;i<numOfFaces;i++){
	cout<<i<<endl;
	Face face = threeDfig.m_allFaces[i];
	cout<<"face found\n";
	int numOfPoints = face.m_numOfsides;
	cout<<"\nThe number of sides are: "<<numOfPoints<<endl;

	glBegin(GL_POLYGON);

	for(int i=0;i<numOfPoints;i++){
		Point3 point = face.m_allPoints[i];
		Vector3f coordinates = point.m_coordinates;
		glColor3f( 1.0, 1.0, 1.0 );     glVertex3f( coordinates(0),  coordinates(1), coordinates(2)); 
	}

	glEnd();
	
  }

  int numOfEdges = threeDfig.m_numOfEdges;
	
  for(int i=0;i<numOfEdges;i++){
	Point3 point1 = threeDfig.m_allEdges[i].m_point1;
	Point3 point2 = threeDfig.m_allEdges[i].m_point2;
	
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
  	
  	threeDfig.addPoint(point1);
  	threeDfig.addPoint(point2);
  	threeDfig.addPoint(point3);
  	threeDfig.addPoint(point4);
  	threeDfig.addPoint(point5);
  	threeDfig.addPoint(point6);
  	threeDfig.addPoint(point7);
  	threeDfig.addPoint(point8);
  	
  	threeDfig.addEdge(0,1); // 0
  	threeDfig.addEdge(1,2); // 1
  	threeDfig.addEdge(2,3); // 2
  	threeDfig.addEdge(3,4); // 3
  	threeDfig.addEdge(4,5); // 4
  	threeDfig.addEdge(5,6); // 5
  	threeDfig.addEdge(6,7); // 6
  	threeDfig.addEdge(7,4); // 7
  	threeDfig.addEdge(0,3); // 8
  	threeDfig.addEdge(0,5); // 9
  	threeDfig.addEdge(1,6); // 10
  	threeDfig.addEdge(2,7); // 11

	vector< int> face1;
	vector< int> face2;
	vector< int> face3;
	vector< int> face4;
	vector< int> face5;
	vector< int> face6;

	face1.pb(0);
	face1.pb(1);
	face1.pb(2);
	face1.pb(8);
	
	face2.pb(4);
	face2.pb(5);
	face2.pb(6);
	face2.pb(7);

	face3.pb(8);
	face3.pb(3);
	face3.pb(4);
	face3.pb(9);

	face4.pb(0);
	face4.pb(10);
	face4.pb(5);
	face4.pb(9);

	face5.pb(7);
	face5.pb(3);
	face5.pb(2);
	face5.pb(11);

	face6.pb(1);
	face6.pb(11);
	face6.pb(6);
	face6.pb(10);

	threeDfig.addFace(4,face1);
	threeDfig.addFace(4,face2);
	threeDfig.addFace(4,face3);
	threeDfig.addFace(4,face4);
	threeDfig.addFace(4,face5);
	threeDfig.addFace(4,face6);

	threeDfig.rotateX(45);  	
	
  	//newWireframe.Complete();
  	
  	// Test Case Ends Here
 
	glutCreateWindow("Wireframe");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(display);
  	glutSpecialFunc(specialKeys);
 
 	glutMainLoop();
  return 0;
}
