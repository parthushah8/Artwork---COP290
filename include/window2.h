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
#include "extern_var.h"

using namespace std;

// extern threeD_Fig threeDfigw2;

// double rotate_yw2=0; 
// double rotate_xw2=0;

void displayw2();

void specialKeysw2( int key, int x, int y );

void window3Dw2();



// extern wireframe newWireframew2;

// double rotate_yWw2=0; 
//double rotate_xWw2=0;

void displayWw2();

void specialKeysWw2( int key, int x, int y );

void windowWireframew2();




// extern twoD_Fig twoDFigXYw2;

// extern twoD_Fig twoDFigYZw2;

// extern twoD_Fig twoDFigXZw2;



void display2DXYw2();

void display2DYZw2();

void display2DXZw2();



void XYvieww2();

void YZvieww2();

void XZvieww2();

