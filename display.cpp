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
#include "threeD_Fig.h"
#include "wireframe.h"

using namespace Eigen;
using namespace std;

twoD_Fig twoDFigXY(true, false, false, false);

void display2DXY(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXY.m_numOfEdges;

	cout<<"\n\n\nIN display2DXY.";
	
	twoDFigXY.print();;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXY.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXY.m_allEdges[i].m_point2;
		bool isHidden = twoDFigXY.m_allEdges[i].m_isHidden;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		cout<<"\n";

		cout<<coordinates1(0)<<" "<<coordinates1(1)<<endl;
		cout<<coordinates2(0)<<" "<<coordinates2(1)<<endl;
		
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

twoD_Fig twoDFigYZ(false, true, false, false);

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

twoD_Fig twoDFigXZ(false, false, true, false);

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

twoD_Fig twoDFigIso(false, false, false, true);

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

wireframe newWireframe;

double rotate_yW=0; 
double rotate_xW=0;
 
void displayW(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_xW, 1.0, 0.0, 0.0 );
  glRotatef( rotate_yW, 0.0, 1.0, 0.0 );
 
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

void specialKeysW( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_yW += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_yW -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_xW += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_xW -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}

/*
int main(int argc, char* argv[]){
	glutInit(&argc,argv);
  	//  Request double buffered true color window with Z-buffer
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	
  	//------------FOR XY Projection------------------------//
  	//------------Taking Inputs----------------------------//
	
	// Test Case1 -- Quadrilateral
	Point2 point1(-0.5f, 0.0f, 0, true, false, false, false);
	Point2 point2(0.0f, 0.5f, 1, true, false, false, false);
	Point2 point3(0.5f, 0.5f, 2, true, false, false, false);
	Point2 point4(0.5f, 0.0f, 3, true, false, false, false);

	twoDFigXY.addPoint(point1);
	twoDFigXY.addPoint(point2);
	twoDFigXY.addPoint(point3);
	twoDFigXY.addPoint(point4);

	twoDFigXY.addEdge(0,1,false);
	twoDFigXY.addEdge(1,2,false);
	twoDFigXY.addEdge(2,3,false);
	twoDFigXY.addEdge(3,0,false);
	
	
	
	
	// Test Case End here
	
	//----------------END HERE------------------------------//
	

  	// Create window
  	if(twoDFigXY.m_OnXY){
  		//twoDFigXY.clear();
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
*/
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

	threeDfig.rotateX(55);
	threeDfig.rotateY(55);  	

  	newWireframe = threeDfig.convertToWireframe();

	twoDFigXY = newWireframe.projectXY();

	twoDFigXY.print();
  	
  	// Test Case Ends Here
 
	//glutCreateWindow("Wireframe");
 
   	//glEnable(GL_DEPTH_TEST);
 
  	//glutDisplayFunc(display2DXY);
  	//glutSpecialFunc(specialKeysW);

	glutCreateWindow("XY Projection");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DXY);
 
 	glutMainLoop();
  return 0;
}
/*
int main(int argc, char* argv[]){
  
  	glutInit(&argc,argv);
 
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	
  	// Test Case 2 -- Square Pyramid
  	
  	Point3 point1(0.0f,0.0f,0.0f,0);
  	Point3 point2(0.0f,0.5f,0.0f,1);
  	Point3 point3(0.5f,0.5f,0.0f,2);
  	Point3 point4(0.5f,0.0f,0.0f,3);
  	Point3 point5(0.25f,0.25f,-0.5f,4);
  	
  	threeDfig.addPoint(point1);
  	threeDfig.addPoint(point2);
  	threeDfig.addPoint(point3);
  	threeDfig.addPoint(point4);
  	threeDfig.addPoint(point5);
  	
  	threeDfig.addEdge(0,1); // 0
  	threeDfig.addEdge(1,2); // 1
  	threeDfig.addEdge(2,3); // 2
  	threeDfig.addEdge(3,0); // 3
  	threeDfig.addEdge(0,4); // 4
  	threeDfig.addEdge(1,4); // 5
  	threeDfig.addEdge(2,4); // 6
  	threeDfig.addEdge(3,4); // 7

	vector< int> face1;
	vector< int> face2;
	vector< int> face3;
	vector< int> face4;
	vector< int> face5;

	face1.pb(0);
	face1.pb(1);
	face1.pb(2);
	face1.pb(3);
	
	face2.pb(0);
	face2.pb(4);
	face2.pb(5);
	
	face3.pb(1);
	face3.pb(5);
	face3.pb(6);
	
	face4.pb(2);
	face4.pb(6);
	face4.pb(7);
	
	face5.pb(3);
	face5.pb(7);
	face5.pb(4);
	
	threeDfig.addFace(4,face1);
	threeDfig.addFace(3,face2);
	threeDfig.addFace(3,face3);
	threeDfig.addFace(3,face4);
	threeDfig.addFace(3,face5);

	//threeDfig.rotateX(55);
	// threeDfig.rotateY(55);  	

  	newWireframe = threeDfig.convertToWireframe();

	twoDFigXY = newWireframe.projectXY();

	twoDFigXY.print();
  	
  	// Test Case Ends Here
 
	//glutCreateWindow("Wireframe");
 
   	//glEnable(GL_DEPTH_TEST);
 
  	//glutDisplayFunc(display2DXY);
  	//glutSpecialFunc(specialKeysW);

	glutCreateWindow("XY Projection");
  		glutInitWindowSize(1080, 1080);
   		glutInitWindowPosition(50, 50);
  		glutDisplayFunc(display2DXY);
 
 	glutMainLoop();
  return 0;
}
*/
/*
int main(int argc, char* argv[]){
	glutInit(&argc,argv);
  	//  Request double buffered true color window with Z-buffer
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	
  	//------------FOR XY Projection------------------------//
  	//------------Taking Inputs----------------------------//
	
	// Test Case1 -- Quadrilateral
	Point2 point1x(0.0f, 0.0f, 0, true, false, false, false);
	Point2 point2x(0.0f, 0.5f, 1, true, false, false, false);
	Point2 point3x(0.5f, 0.5f, 2, true, false, false, false);
	Point2 point4x(0.5f, 0.0f, 3, true, false, false, false);
	Point2 point5x(0.0f, 0.0f, 4, true, false, false, false);
	Point2 point6x(0.0f, 0.5f, 5, true, false, false, false);
	Point2 point7x(0.5f, 0.5f, 6, true, false, false, false);
	Point2 point8x(0.5f, 0.0f, 7, true, false, false, false);

	twoDFigXY.addPoint(point1x);
	twoDFigXY.addPoint(point2x);
	twoDFigXY.addPoint(point3x);
	twoDFigXY.addPoint(point4x);
	twoDFigXY.addPoint(point5x);
	twoDFigXY.addPoint(point6x);
	twoDFigXY.addPoint(point7x);
	twoDFigXY.addPoint(point8x);
	

	twoDFigXY.addEdge(0,1,false);
	twoDFigXY.addEdge(1,2,false);
	twoDFigXY.addEdge(2,3,false);
	twoDFigXY.addEdge(3,0,false);
	
	
	
	
	// Test Case End here
	
	//----------------END HERE------------------------------//

	//------------FOR YZ Projection------------------------//
  	//------------Taking Inputs----------------------------//
	
	// Test Case1 -- Quadrilateral
	Point2 point1y(0.0f, 0.0f, 0, false, true, false, false);
	Point2 point2y(0.5f, 0.0f, 1, false, true, false, false);
	Point2 point3y(0.5f, 0.0f, 2, false, true, false, false);
	Point2 point4y(0.0f, 0.0f, 3, false, true, false, false);
	Point2 point5y(0.0f, 0.5f, 4, false, true, false, false);
	Point2 point6y(0.5f, 0.5f, 5, false, true, false, false);
	Point2 point7y(0.5f, 0.5f, 6, false, true, false, false);
	Point2 point8y(0.0f, 0.5f, 7, false, true, false, false);

	twoDFigYZ.addPoint(point1y);
	twoDFigYZ.addPoint(point2y);
	twoDFigYZ.addPoint(point3y);
	twoDFigYZ.addPoint(point4y);
	twoDFigYZ.addPoint(point5y);
	twoDFigYZ.addPoint(point6y);
	twoDFigYZ.addPoint(point7y);
	twoDFigYZ.addPoint(point8y);
	

	twoDFigYZ.addEdge(4,5,false);
	twoDFigYZ.addEdge(0,4,false);
	twoDFigYZ.addEdge(2,6,false);
	twoDFigYZ.addEdge(6,7,false);
	
	
	
	
	// Test Case End here
	
	//----------------END HERE------------------------------//

	//------------FOR XZ Projection------------------------//
  	//------------Taking Inputs----------------------------//
	
	// Test Case1 -- Quadrilateral
	Point2 point1z(0.0f, 0.0f, 0, false, false, true, false);
	Point2 point2z(0.0f, 0.0f, 1, false, false, true, false);
	Point2 point3z(0.5f, 0.0f, 2, false, false, true,  false);
	Point2 point4z(0.5f, 0.0f, 3, false, false, true, false);
	Point2 point5z(0.0f, 0.5f, 4, false, false, true, false);
	Point2 point6z(0.0f, 0.5f, 5, false, false, true, false);
	Point2 point7z(0.5f, 0.5f, 6, false, false, true, false);
	Point2 point8z(0.5f, 0.5f, 7, false, false, true, false);

	twoDFigXZ.addPoint(point1z);
	twoDFigXZ.addPoint(point2z);
	twoDFigXZ.addPoint(point3z);
	twoDFigXZ.addPoint(point4z);
	twoDFigXZ.addPoint(point5z);
	twoDFigXZ.addPoint(point6z);
	twoDFigXZ.addPoint(point7z);
	twoDFigXZ.addPoint(point8z);
	

	twoDFigXZ.addEdge(4,7,false);
	twoDFigXZ.addEdge(5,6,false);
	twoDFigXZ.addEdge(1,5,false);
	twoDFigXZ.addEdge(3,7,false);
	
	
	
	/*
	// Test Case End here
	
	//----------------END HERE------------------------------//
	

  	// Create window
  	if(twoDFigXY.m_OnXY){
  		//twoDFigXY.clear();
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

	

	newWireframe.regenerate(twoDFigXY, twoDFigYZ, twoDFigXZ);

	glutCreateWindow("Wireframe");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(displayW);
  	glutSpecialFunc(specialKeysW);
 
 	glutMainLoop();
  	return 0;
}
*/
