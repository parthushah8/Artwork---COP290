#include "thirdwindow.h"
#include <iostream>

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

twoD_Fig twoDFigXYT(true, false, false, false);

void display2DXYT(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXYT.m_numOfEdges;

	cout<<"\n\n\nIN display2DXYT.";
	
	twoDFigXYT.print();;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXYT.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXYT.m_allEdges[i].m_point2;
		
		Vector2f coordinates1 = point1.m_coordinates;
		Vector2f coordinates2 = point2.m_coordinates;
		
		cout<<"\n";

		cout<<coordinates1(0)<<" "<<coordinates1(1)<<endl;
		cout<<coordinates2(0)<<" "<<coordinates2(1)<<endl;
		
		glLineWidth(5000);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
			glVertex2f(coordinates1(0),coordinates1(1));
			glVertex2f(coordinates2(0),coordinates2(1));
		glEnd();
	}

  	glFlush();
  	glutSwapBuffers();
 
}

twoD_Fig twoDFigYZT(false, true, false, false);

void display2DYZT(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigYZT.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigYZT.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigYZT.m_allEdges[i].m_point2;
		
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

twoD_Fig twoDFigXZT(false, false, true, false);

void display2DXZT(){
 
  	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	
	int numOfEdges = twoDFigXZT.m_numOfEdges;
	
	for(int i=0;i<numOfEdges;i++){
		Point2 point1 = twoDFigXZT.m_allEdges[i].m_point1;
		Point2 point2 = twoDFigXZT.m_allEdges[i].m_point2;
		
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
/*
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
*/
// 2d above ----------------------------------------------------------

wireframe newWireframeT;

double rotate_yWT=0; 
double rotate_xWT=0;
 
void displayWT(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_xWT, 1.0, 0.0, 0.0 );
  glRotatef( rotate_yWT, 0.0, 1.0, 0.0 );
 
  int numOfEdges = newWireframeT.m_numOfEdges;
	
  for(int i=0;i<numOfEdges;i++){
	Point3 point1 = newWireframeT.m_allEdges[i].m_point1;
	Point3 point2 = newWireframeT.m_allEdges[i].m_point2;
	
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

void specialKeysWT( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_yWT += 5;
 
  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_yWT -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_xWT += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_xWT -= 5;
 
  //  Request display update
  glutPostRedisplay();
 
}


// wireframe above ----------------------------------------------------------


ThirdWindow::ThirdWindow()
: m_Box(Gtk::ORIENTATION_VERTICAL),
  m_point_box(Gtk::ORIENTATION_VERTICAL),
  m_point_frame("Points"),
  m_point_frame_xy("Coordinates in xy projection"),
  m_point_frame_yz("Coordinates in yz projection"),
  m_point_frame_zx("Coordinates in zx projection"),
  m_input_frame("Input from file"),
  m_point_frame_buttons("Create/Reset"),
  m_edge_frame("Edges"),
  m_face_frame("Faces"),
  m_input("Take Input"),
  m_reset_point("Reset Points"),
  m_reset_last_point("Reset Last Point"),
  m_reset_edge("Reset Edges"),
  m_reset_last_edge("Reset Last Edge"),
  m_reset_face("Reset Faces"),
  m_reset_last_face("Reset Last Face"), 
  m_Button_addvertex("Add Vertex"),
  m_Button_addedge("Add Edge"),
  m_create("Create 3D object"),
  m_Button_addface("Add Face")
  //m_CheckButton_Editable("Editable"),
  //m_CheckButton_Visible("Visible")
{
  set_size_request(200, 100);
  set_title("Artworks:: Convert 3D to 2D Orthographic Views");
  set_border_width(12);
  	
  add(m_Box);

  m_Box.pack_start(m_input_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_point_frame.add(m_input_grid);

  m_file_name.set_max_length(30);
  m_file_name.set_text("Name of file");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  m_file_name.select_region(0, m_file_name.get_text_length());

  m_input_grid.add(m_file_name);
  m_input_grid.attach_next_to(m_input, m_file_name, Gtk::POS_RIGHT, 1, 1);


  m_Box.pack_start(m_point_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  //m_Box.pack_start(m_VBox_left);
  //m_Box.pack_start(m_VBox_right);  
  
  //m_VBox_right.pack_start(m_VBox1);
  m_point_frame.add(m_point_box);
  
  m_point.set_max_length(30);
  m_point.set_text("Point");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  m_point.select_region(0, m_point.get_text_length());

  m_point_box.pack_start(m_point);
  m_point_box.pack_start(m_point_frame_xy);
  m_point_box.pack_start(m_point_frame_yz);
  m_point_box.pack_start(m_point_frame_zx);
  m_point_box.pack_start(m_point_frame_buttons); 

  m_point_frame_xy.add(m_point_grid_xy);
  m_point_frame_yz.add(m_point_grid_yz);
  m_point_frame_zx.add(m_point_grid_zx);
  m_point_frame_zx.add(m_point_grid_buttons);

  x_coordinate_xy.set_max_length(30);
  x_coordinate_xy.set_text("x coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  x_coordinate_xy.select_region(0, x_coordinate_xy.get_text_length());

  y_coordinate_xy.set_max_length(30);
  y_coordinate_xy.set_text("y coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  y_coordinate_xy.select_region(0, y_coordinate_xy.get_text_length());
  
  z_coordinate_xy.set_max_length(30);
  z_coordinate_xy.set_text("z coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  z_coordinate_xy.select_region(0, z_coordinate_xy.get_text_length());

  x_coordinate_yz.set_max_length(30);
  x_coordinate_yz.set_text("x coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  x_coordinate_yz.select_region(0, x_coordinate_yz.get_text_length());

  y_coordinate_yz.set_max_length(30);
  y_coordinate_yz.set_text("y coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  y_coordinate_yz.select_region(0, y_coordinate_yz.get_text_length());
  
  z_coordinate_yz.set_max_length(30);
  z_coordinate_yz.set_text("z coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  z_coordinate_yz.select_region(0, z_coordinate_yz.get_text_length());

  x_coordinate_zx.set_max_length(30);
  x_coordinate_zx.set_text("x coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  x_coordinate_zx.select_region(0, x_coordinate_zx.get_text_length());

  y_coordinate_zx.set_max_length(30);
  y_coordinate_zx.set_text("y coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  y_coordinate_zx.select_region(0, y_coordinate_zx.get_text_length());
  
  z_coordinate_zx.set_max_length(30);
  z_coordinate_zx.set_text("z coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  z_coordinate_zx.select_region(0, z_coordinate_zx.get_text_length());
  
  
  m_point_grid_xy.add(x_coordinate_xy);
  m_point_grid_xy.attach_next_to(y_coordinate_xy, x_coordinate_xy, Gtk::POS_RIGHT, 1, 1);
  m_point_grid_xy.attach_next_to(z_coordinate_xy, y_coordinate_xy, Gtk::POS_RIGHT, 1, 1);

  m_point_grid_yz.add(x_coordinate_yz);
  m_point_grid_yz.attach_next_to(y_coordinate_yz, x_coordinate_yz, Gtk::POS_RIGHT, 1, 1);
  m_point_grid_yz.attach_next_to(z_coordinate_yz, y_coordinate_yz, Gtk::POS_RIGHT, 1, 1);

  m_point_grid_zx.add(x_coordinate_zx);
  m_point_grid_zx.attach_next_to(y_coordinate_zx, x_coordinate_zx, Gtk::POS_RIGHT, 1, 1);
  m_point_grid_zx.attach_next_to(z_coordinate_zx, y_coordinate_zx, Gtk::POS_RIGHT, 1, 1);

  m_point_grid_buttons.add(m_Button_addvertex);
  m_point_grid.attach_next_to(m_reset_last_point ,m_Button_addvertex, Gtk::POS_RIGHT, 1, 1);
  m_point_grid.attach_next_to(m_reset_point, m_reset_last_point, Gtk::POS_RIGHT, 1, 1);
  m_Button_addvertex.signal_clicked().connect( sigc::mem_fun(*this,
              &ThirdWindow::add_vertex_clicked) );
 // m_CheckButton_Editable.set_active(true);


  // Note that add() can also be used instead of pack_xxx()
  m_Box.pack_start(m_edge_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  
  first_vertex.set_max_length(30);
  first_vertex.set_text("Label of first vertex");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  first_vertex.select_region(0, first_vertex.get_text_length());


  second_vertex.set_max_length(30);
  second_vertex.set_text("Label of second vertex");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  second_vertex.select_region(0, second_vertex.get_text_length());


  m_label_edge.set_max_length(30);
  m_label_edge.set_text("Add label of edge");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  m_label_edge.select_region(0, m_label_edge.get_text_length());



  m_edge_frame.add(m_edge_grid);
  m_edge_grid.add(first_vertex);
  m_edge_grid.attach_next_to(second_vertex, first_vertex, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_label_edge, second_vertex, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_Button_addedge, first_vertex, Gtk::POS_BOTTOM, 2, 1);
  m_edge_grid.attach_next_to(m_reset_last_edge ,m_Button_addedge, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_reset_edge, m_reset_last_edge, Gtk::POS_RIGHT, 1, 1);
  m_Button_addedge.signal_clicked().connect( sigc::mem_fun(*this,
              &ThirdWindow::add_edge_clicked) );



  m_Box.pack_start(m_face_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  
  number_of_vertices.set_max_length(30);
  number_of_vertices.set_text("Number of Vertices");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  number_of_vertices.select_region(0, number_of_vertices.get_text_length());

  vertices_face.set_max_length(30);
  vertices_face.set_text("Vertices(separated by commas)");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  vertices_face.select_region(0, vertices_face.get_text_length());

  m_label_face.set_max_length(30);
  m_label_face.set_text("Add label of face");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  m_label_face.select_region(0, m_label_face.get_text_length());

  m_face_frame.add(m_face_grid);
  m_face_grid.add(number_of_vertices);
  m_face_grid.attach_next_to(vertices_face, number_of_vertices, Gtk::POS_RIGHT, 1, 1);
  m_face_grid.attach_next_to(m_label_face,vertices_face, Gtk::POS_RIGHT, 1, 1);
  m_face_grid.attach_next_to(m_Button_addface, number_of_vertices, Gtk::POS_BOTTOM, 2, 1);
  m_face_grid.attach_next_to(m_reset_last_face ,m_Button_addface, Gtk::POS_RIGHT, 1, 1);
  m_face_grid.attach_next_to(m_reset_face, m_reset_last_face, Gtk::POS_RIGHT, 1, 1);
  m_Button_addface.signal_clicked().connect( sigc::mem_fun(*this,
              &ThirdWindow::add_face_clicked) );

  m_Box.pack_start(m_create, Gtk::PACK_EXPAND_WIDGET, 10);

  m_create.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::create_clicked) );
  m_reset_point.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_point_clicked) );
  m_reset_last_point.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_last_point_clicked) ); 
  m_reset_edge.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_edge_clicked) );
  m_reset_last_edge.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_last_edge_clicked) );
  m_reset_face.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_face_clicked) );
  m_reset_last_face.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::reset_last_face_clicked) );
  m_input.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::m_input_clicked) );
 

  m_Button_addedge.set_sensitive(false);
  m_Button_addface.set_sensitive(false);
  m_create.set_sensitive(false);

  //m_CheckButton_Editable.set_active(true);

  //m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
    //          &ThirdWindow::on_button_close) );
  //m_VBox_right.pack_start(m_Button_Close);
  //m_Button_Close.set_can_default();
 // m_Button_Close.grab_default();

  show_all_children();
}


ThirdWindow::~ThirdWindow()
{
}

void ThirdWindow::add_vertex_clicked()
{
  //std::cout << "Entered text: " << x_coordinate.get_text() << y_coordinate.get_text() 
    //<< z_coordinate.get_text() << m_label.get_text() << std::endl;
  int index = atoi(m_point.get_text().c_str());
  double x_xy = atof(x_coordinate_xy.get_text().c_str());
  double y_xy = atof(y_coordinate_xy.get_text().c_str());
  double z_xy = atof(z_coordinate_xy.get_text().c_str());
  double x_yz = atof(x_coordinate_yz.get_text().c_str());
  double y_yz = atof(y_coordinate_yz.get_text().c_str());
  double z_yz = atof(z_coordinate_yz.get_text().c_str());
  double x_zx = atof(x_coordinate_zx.get_text().c_str());
  double y_zx = atof(y_coordinate_zx.get_text().c_str());
  double z_zx = atof(z_coordinate_zx.get_text().c_str());
  Point2 pointxy(x_xy, y_xy, index, true, false, false, false);
  Point2 pointyz(y_yz, z_yz, index, false, true, false, false);
  Point2 pointxz(x_zx, z_zx, index, false, false, true, false);
  //string label = std::string(m_label.get_text());
  twoDFigXYT.addPoint(pointxy);
  twoDFigYZT.addPoint(pointyz);
  twoDFigXZT.addPoint(pointxz);
  m_input.set_sensitive(false);
  m_Button_addedge.set_sensitive(true);
  m_create.set_sensitive(true); 
}

void ThirdWindow::add_edge_clicked()
{

  int point_index1 = atoi(first_vertex.get_text().c_str());
  int point_index2 = atoi(second_vertex.get_text().c_str());
  int index = atoi(m_label_edge.get_text().c_str());
  twoDFigXYT.addEdge(point_index1,point_index2,false);
  twoDFigYZT.addEdge(point_index1,point_index2,false);
  twoDFigXZT.addEdge(point_index1,point_index2,false);
  m_Button_addface.set_sensitive(true);
}

void ThirdWindow::add_face_clicked()
{
  int num = atoi(number_of_vertices.get_text().c_str());
  std::string vertices = std::string(vertices_face.get_text());
  std::string label = std::string(m_label_face.get_text());
  char vert[num];
   for (int i = 0; i < (2*num-1); i++)
    {
        if(i%2==0)
	{
	   	vert[i/2]=vertices.at(i);
        }
	
    }
}

void wireframeModel(){
  
	int i=0;
  	glutInit(&i,NULL);
 
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
	glutCreateWindow("Wirefremae");
 
   	glEnable(GL_DEPTH_TEST);
 
  	glutDisplayFunc(displayWT);
  	glutSpecialFunc(specialKeysWT);
 
 	// glutMainLoop();
  return ;
}

void ThirdWindow::create_clicked()
{
	newWireframeT.regenerate(twoDFigXYT, twoDFigYZT, twoDFigXZT);
	wireframeModel();

}
void ThirdWindow::reset_point_clicked()
{
  
}
void ThirdWindow::reset_last_point_clicked()
{
  
}
void ThirdWindow::reset_edge_clicked()
{
  
}
void ThirdWindow::reset_last_edge_clicked()
{
  
}
void ThirdWindow::reset_face_clicked()
{
  
}
void ThirdWindow::reset_last_face_clicked()
{
  
}
void m_input_clicked()
{
  m_Button_addvertex.set_sensitive(false);
  std::string line; 
  std::string file = std::string(vertices_face.get_text());
  ifstream myfile (file);
  if (myfile.is_open())
  {
    getline(myfile, line);
    //extracting points----------------
    int num_points = atoi(line.c_str());
    for (int j=1;i<=num_points;j++ )
    {
      getline(myfile,line);
      std::string substring;
      int l = line.length();
      int fp = 0;
      int lp = 0;
      int te = 0;
      for (int i = 0; i < l; i++)
          {
           char t = vertices.at(i);
           if(t == ',')
              {
		lp = i;
		substring = vertices.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
                if(te==0){ 
		double x=atof(substring.c_str());}
                if(te==1){ 
		double y=atof(substring.c_str());}
                if(te==2){ 
		double z=atof(substring.c_str());}
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = vertices.substr(fp,(lp-fp)); 
      int index=atoi(substring.c_str());
      Point3 point(x,y,z,index);
      point.print();	
      threeDfig.addPoint(point); 
    }
 //extracting edges----------------------------------------
    int num_edges = atoi(line.c_str());
    for (int j=1;i<=num_edges;j++ )
    {
      getline(myfile,line);
      l = line.length();
      fp = 0;
      lp = 0;
      te = 0;
      for (int i = 0; i < l; i++)
          {
           t = vertices.at(i);
           if(t == ',')
              {
		lp = i;
		substring = vertices.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
                if(te==0){ 
		int first_point=atoi(substring.c_str());}
                if(te==1){ 
		int second_point=atoi(substring.c_str());}
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = vertices.substr(fp,(lp-fp)); 
      int index=atoi(substring.c_str());
      threeDfig.addEdge(first_point, second_point);    
    }
 //extracting faces
    int num_faces = atoi(line.c_str());
    for (int j=1;i<=num_edges;j++ )
    {
      getline(myfile,line);
      vector<int> vert;
      l = line.length();
      fp = 0;
      lp = 0;
      te = 0;
      for (int i = 0; i < l; i++)
          {
           t = vertices.at(i);
           if(t == ',')
              {
		lp = i;
		substring = vertices.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
		vert.push_back(atoi(substring.c_str()));
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = vertices.substr(fp,(lp-fp)); 
      vert.push_back(atoi(substring.c_str()));
      threeDfig.addFace(vert.size(),vert);    
    }
    m_create_3D.set_sensitive(true);
    m_create_top.set_sensitive(true);
    m_create_front.set_sensitive(true);
    m_create_side.set_sensitive(true);
    m_create_isometric.set_sensitive(true);   
    myfile.close();
  }
}
