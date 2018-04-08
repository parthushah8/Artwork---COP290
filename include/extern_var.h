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

using namespace std;

extern threeD_Fig threeDfigw2;

extern wireframe newWireframew2;

extern twoD_Fig twoDFigXYw2;

extern twoD_Fig twoDFigYZw2;

extern twoD_Fig twoDFigXZw2;

extern threeD_Fig threeDfigw3;

extern wireframe newWireframew3;

extern twoD_Fig twoDFigXYw3;

extern twoD_Fig twoDFigYZw3;

extern twoD_Fig twoDFigXZw3;

extern double rotate_yw2; 
extern double rotate_xw2;

extern double rotate_yWw2; 
extern double rotate_xWw2;

extern double rotate_yw3; 
extern double rotate_xw3;

extern double rotate_yWw3; 
extern double rotate_xWw3;

