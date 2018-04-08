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

// extern threeD_Fig threeDfigw3;

// double rotate_yw3=0; 
// double rotate_xw3=0;

void displayw3();

void specialKeysw3( int key, int x, int y );

void window3Dw3();



// extern wireframe newWireframew3;

// double rotate_yWw3=0; 
// double rotate_xWw3=0;

void displayWw3();

void specialKeysWw3( int key, int x, int y );

void windowWireframew3();




// extern twoD_Fig twoDFigXYw3;

// extern twoD_Fig twoDFigYZw3;

// extern twoD_Fig twoDFigXZw3;



void display2DXYw3();

void display2DYZw3();

void display2DXZw3();



void XYvieww3();

void YZvieww3();

void XZvieww3();

