#include "secondwindow.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

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

#include "extern_var.h"

threeD_Fig threeDfigw2;
wireframe newWireframew2;

twoD_Fig twoDFigXYw2(true,false,false,false);

twoD_Fig twoDFigYZw2(false,true,false,false);

twoD_Fig twoDFigXZw2(false,false,true,false);

double rotate_yw2=0; 
double rotate_xw2=0;

double rotate_yWw2=0; 
double rotate_xWw2=0;

using namespace Eigen;
using namespace std;
   
SecondWindow::SecondWindow()
: m_Box(Gtk::ORIENTATION_VERTICAL),
  m_input_frame("Input from file"),
  m_point_frame("Points"),
  m_edge_frame("Edges"),
  m_face_frame("Faces"),
  m_rotate_frame("Rotate Object"),
  m_create_frame("Create"),  
  m_Button_addvertex("Add Vertex"),
  m_Button_addedge("Add Edge"),
  m_input("Take input"),
  m_reset_point("Reset Points"),
  m_reset_last_point("Reset Last Point"),
  m_reset_edge("Reset Edges"),
  m_reset_last_edge("Reset Last Edge"),
  m_reset_face("Reset Faces"),
  m_reset_last_face("Reset Last Face"),
  m_create_3D("Create 3D object"),
  m_create_top("Create top view"),
  m_create_front("Create front view"),
  m_create_side("Create side view"),
  m_create_isometric("Create Wireframe view"),
  m_rotate_x("Rotate about x-axis"),
  m_rotate_y("Rotate about y-axis"),
  m_rotate_z("Rotate about z-axis"),
  m_Button_addface("Add Face")
  //m_CheckButton_Editable("Editable"),
  //m_CheckButton_Visible("Visible")
{

  // threeDfigw2.resetAllPoints();
  // newWireframew2.clear();

  // twoDFigXYw2.resetAllPoints();

  // twoDFigYZw2.resetAllPoints();

  // twoDFigXZw2.resetAllPoints();

  set_size_request(250, 100);
  set_title("Artworks:: Convert 3D to 2D Orthographic Views");
  set_border_width(12);
  	
  add(m_Box);

  m_Box.pack_start(m_input_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_input_frame.add(m_input_grid);

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
  m_point_frame.add(m_point_grid);

  x_coordinate.set_max_length(30);
  x_coordinate.set_text("x coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  x_coordinate.select_region(0, x_coordinate.get_text_length());

  y_coordinate.set_max_length(30);
  y_coordinate.set_text("y coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  y_coordinate.select_region(0, y_coordinate.get_text_length());
  
  z_coordinate.set_max_length(30);
  z_coordinate.set_text("z coordinate");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  z_coordinate.select_region(0, z_coordinate.get_text_length());

  m_label.set_max_length(30);
  m_label.set_text("Add Label");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  m_label.select_region(0, m_label.get_text_length());

  
  m_point_grid.add(x_coordinate);
  m_point_grid.attach_next_to(y_coordinate, x_coordinate, Gtk::POS_RIGHT, 1, 1);
  m_point_grid.attach_next_to(z_coordinate, y_coordinate, Gtk::POS_RIGHT, 1, 1);
  m_point_grid.attach_next_to(m_label, z_coordinate, Gtk::POS_RIGHT, 1, 1);
  m_point_grid.attach_next_to(m_Button_addvertex, x_coordinate, Gtk::POS_BOTTOM, 1, 1);
  m_point_grid.attach_next_to(m_reset_last_point ,m_Button_addvertex, Gtk::POS_RIGHT, 1, 1);
  m_point_grid.attach_next_to(m_reset_point, m_reset_last_point, Gtk::POS_RIGHT, 1, 1);
  m_Button_addvertex.signal_clicked().connect( sigc::mem_fun(*this,
              &SecondWindow::add_vertex_clicked) );
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
  //m_edge_grid.attach_next_to(m_label_edge, second_vertex, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_Button_addedge, first_vertex, Gtk::POS_BOTTOM, 2, 1);
  m_edge_grid.attach_next_to(m_reset_last_edge ,m_Button_addedge, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_reset_edge, m_reset_last_edge, Gtk::POS_RIGHT, 1, 1);
  m_Button_addedge.signal_clicked().connect( sigc::mem_fun(*this,
              &SecondWindow::add_edge_clicked) );



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
  //m_face_grid.attach_next_to(m_label_face,vertices_face, Gtk::POS_RIGHT, 1, 1);
  m_face_grid.attach_next_to(m_Button_addface, number_of_vertices, Gtk::POS_BOTTOM, 2, 1);
  m_face_grid.attach_next_to(m_reset_last_face ,m_Button_addface, Gtk::POS_RIGHT, 1, 1);
  m_face_grid.attach_next_to(m_reset_face, m_reset_last_face, Gtk::POS_RIGHT, 1, 1);
  m_Button_addface.signal_clicked().connect( sigc::mem_fun(*this,
              &SecondWindow::add_face_clicked) );



  
  m_Button_addedge.set_sensitive(false);
  m_reset_edge.set_sensitive(false);
  m_reset_last_edge.set_sensitive(false);
  m_reset_face.set_sensitive(false);
  m_reset_last_face.set_sensitive(false);
  m_Button_addface.set_sensitive(false);
  m_create_3D.set_sensitive(false);
  m_create_top.set_sensitive(false);
  m_create_front.set_sensitive(false);
  m_create_side.set_sensitive(false);
  m_create_isometric.set_sensitive(false);

  degrees_x.set_max_length(30);
  degrees_x.set_text("Degrees of Rotation(x)");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  degrees_x.select_region(0, degrees_x.get_text_length());

  degrees_y.set_max_length(30);
  degrees_y.set_text("Degrees of Rotation(y)");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  degrees_y.select_region(0, degrees_y.get_text_length());

  degrees_z.set_max_length(30);
  degrees_z.set_text("Degrees of Rotation(z)");
  //x_coordinate.set_text(x_coordinate.get_text() + " world");
  degrees_z.select_region(0, degrees_z.get_text_length());

  m_Box.pack_start(m_rotate_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_rotate_frame.add(m_rotate_grid);
  m_rotate_grid.add(degrees_x);
  m_rotate_grid.attach_next_to(degrees_y, degrees_x, Gtk::POS_RIGHT, 1, 1);
  m_rotate_grid.attach_next_to(degrees_z, degrees_y, Gtk::POS_RIGHT, 1, 1);
  m_rotate_grid.attach_next_to(m_rotate_x, degrees_x, Gtk::POS_BOTTOM, 1, 1);
  m_rotate_grid.attach_next_to(m_rotate_y, m_rotate_x, Gtk::POS_RIGHT, 1, 1);
  m_rotate_grid.attach_next_to(m_rotate_z, m_rotate_y, Gtk::POS_RIGHT, 1, 1); 


  m_Box.pack_start(m_create_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  m_create_frame.add(m_create_grid);

  m_create_grid.add(m_create_3D);
  m_create_grid.attach_next_to(m_create_top, m_create_3D, Gtk::POS_RIGHT, 1, 1);
  m_create_grid.attach_next_to(m_create_front, m_create_top, Gtk::POS_RIGHT, 1, 1);
  m_create_grid.attach_next_to(m_create_side, m_create_front, Gtk::POS_RIGHT, 1, 1);
  m_create_grid.attach_next_to(m_create_isometric, m_create_side, Gtk::POS_RIGHT, 1, 1);
  
  m_create_3D.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::create_3D_clicked) );
  m_create_top.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::create_top_clicked) );
  m_create_front.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::create_front_clicked) );
  m_create_side.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::create_side_clicked) );
  m_create_isometric.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::create_isometric_clicked) );
  m_rotate_x.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::rotate_x_clicked) );
  m_rotate_y.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::rotate_y_clicked) );
  m_rotate_z.signal_clicked().connect(sigc::mem_fun(*this,
      &SecondWindow::rotate_z_clicked) );
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
 
  //m_CheckButton_Editable.set_active(true);

  //m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
    //          &SecondWindow::on_button_close) );
  //m_VBox_right.pack_start(m_Button_Close);
  //m_Button_Close.set_can_default();
 // m_Button_Close.grab_default();

  show_all_children();
}

SecondWindow::~SecondWindow()
{
}

void SecondWindow::add_vertex_clicked()
{
  //std::cout << "Entered text: " << x_coordinate.get_text() << y_coordinate.get_text() 
  //  << z_coordinate.get_text() << m_label.get_text() << std::endl;
  double x = atof(x_coordinate.get_text().c_str());
  double y = atof(y_coordinate.get_text().c_str());
  double z = atof(z_coordinate.get_text().c_str());
  int index = atoi(m_label.get_text().c_str());
  Point3 point(x,y,z,index);
  point.print();	
  threeDfigw2.addPoint(point);
  m_input.set_sensitive(false); 
  m_Button_addedge.set_sensitive(true);
  m_create_3D.set_sensitive(true);
  m_create_top.set_sensitive(true);
  m_create_front.set_sensitive(true);
  m_create_side.set_sensitive(true);
  m_create_isometric.set_sensitive(true); 
}

void SecondWindow::add_edge_clicked()
{
  int point_index1 = atoi(first_vertex.get_text().c_str());
  int point_index2 = atoi(second_vertex.get_text().c_str());
  cout<<"edge: "<<point_index1<<"  "<<point_index2<<endl;
  threeDfigw2.addEdge(point_index1, point_index2);
  m_Button_addface.set_sensitive(true);
}

void SecondWindow::add_face_clicked()
{
  int num = atoi(number_of_vertices.get_text().c_str());
  std::string vertices = std::string(vertices_face.get_text());
  std::string substring;
  vector< int> vert;
  int l = vertices.length();
  int fp = 0;
  int lp = 0;
  int te = 0;
  for (int i = 0; i < l; i++){
        char t = vertices.at(i);
        if(t == ','){
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
  threeDfigw2.addFace(num,vert);
}

void SecondWindow::rotate_x_clicked()
{
  double angle = atof(degrees_x.get_text().c_str());
  threeDfigw2.rotateX(angle);
}

void SecondWindow::rotate_y_clicked()
{
  double angle = atof(degrees_y.get_text().c_str());
  threeDfigw2.rotateY(angle);
}

void SecondWindow::rotate_z_clicked()
{
  double angle = atof(degrees_z.get_text().c_str());
  threeDfigw2.rotateZ(angle);
}

void SecondWindow::create_3D_clicked()
{
   window3Dw2();
   newWireframew2 = threeDfigw2.convertToWireframe();
}
void SecondWindow::create_top_clicked()
{
  // twoDFigXZw2.decide(2);
  newWireframew2 = threeDfigw2.convertToWireframe();
  twoDFigXZw2 = newWireframew2.projectXZ();
  XZvieww2();
}
void SecondWindow::create_front_clicked()
{
  // twoDFigXYw2.decide(0);
  newWireframew2 = threeDfigw2.convertToWireframe();
  twoDFigXYw2 = newWireframew2.projectXY();
  XYvieww2();
}
void SecondWindow::create_side_clicked()
{
  // twoDFigYZw2.decide(1);
  newWireframew2 = threeDfigw2.convertToWireframe();
  twoDFigYZw2 = newWireframew2.projectYZ();
  YZvieww2();
}
void SecondWindow::create_isometric_clicked()
{
  newWireframew2 = threeDfigw2.convertToWireframe();
  windowWireframew2();
}
void SecondWindow::reset_point_clicked()
{
  threeDfigw2.resetAllPoints();
}
void SecondWindow::reset_last_point_clicked()
{
  threeDfigw2.resetLastPoint();
}
void SecondWindow::reset_edge_clicked()
{
  threeDfigw2.resetAllEdges();
}
void SecondWindow::reset_last_edge_clicked()
{
  threeDfigw2.resetLastEdge();
}
void SecondWindow::reset_face_clicked()
{
  threeDfigw2.resetAllFaces();
}
void SecondWindow::reset_last_face_clicked()
{
  threeDfigw2.resetLastFace();
}
void SecondWindow::m_input_clicked()
{
  m_Button_addvertex.set_sensitive(false);
  m_reset_point.set_sensitive(false);
  m_reset_last_point.set_sensitive(false);
  m_create_3D.set_sensitive(true);
    m_create_top.set_sensitive(true);
    m_create_front.set_sensitive(true);
    m_create_side.set_sensitive(true);
    m_create_isometric.set_sensitive(true);   
    
  std::string line; 
  std::string file = std::string(m_file_name.get_text());
  ifstream myfile (file);
  if (myfile.is_open())
  {
    getline(myfile, line);
    //extracting points----------------
    int num_points = atoi(line.c_str());
    for (int j=1;j<=num_points;j++ )
    {
      getline(myfile,line);
      std::string substring;
      int l = line.length();
      int fp = 0;
      int lp = 0;
      int te = 0;
      double x,y,z;
      for (int i = 0; i < l; i++)
          {
           char t = line.at(i);
           if(t == ',')
              {
		lp = i;
		substring = line.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
                if(te==0){ 
	        x=atof(substring.c_str());}
                if(te==1){ 
		y=atof(substring.c_str());}
                if(te==2){ 
		z=atof(substring.c_str());}
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = line.substr(fp,(lp-fp)); 
      int index=atoi(substring.c_str());
      Point3 point(x,y,z,index);
      point.print();	
      threeDfigw2.addPoint(point); 
    }
 //extracting edges----------------------------------------
    getline(myfile, line);
    int num_edges = atoi(line.c_str());
    for (int j=1;j<=num_edges;j++ )
    {
      getline(myfile,line);
      int l = line.length();
      std::string substring;
      int fp = 0;
      int lp = 0;
      int te = 0;
      int first_point,second_point;
      for (int i = 0; i < l; i++)
          {
           char t = line.at(i);
           if(t == ',')
              {
		lp = i;
		substring = line.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
                if(te==0){ 
		first_point=atoi(substring.c_str());}
                if(te==1){ 
	        second_point=atoi(substring.c_str());}
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = line.substr(fp,(lp-fp)); 
      int index=atoi(substring.c_str());
      threeDfigw2.addEdge(first_point, second_point);    
    }
 //extracting faces
    getline(myfile, line);
    int num_faces = atoi(line.c_str());
    for (int j=1;j<=num_faces;j++ )
    {
      getline(myfile,line);
      vector<int> vert;
      std::string substring;
      int l = line.length();
      int fp = 0;
      int lp = 0;
      int te = 0;
      for (int i = 0; i < l; i++)
          {
           char t = line.at(i);
           if(t == ',')
              {
		lp = i;
		substring = line.substr(fp,(lp-fp));
		//cout<<"\n\n\nSubstring is::"<<substring;
		vert.push_back(atoi(substring.c_str()));
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	      }
          }
      lp = l;
      substring = line.substr(fp,(lp-fp)); 
      vert.push_back(atoi(substring.c_str()));
      threeDfigw2.addFace(vert.size(),vert);    
    }
    myfile.close();
  }
 
}
