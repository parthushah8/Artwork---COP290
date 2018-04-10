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

#include "extern_var.h"


using namespace Eigen;
using namespace std;

threeD_Fig threeDfigw3;

wireframe newWireframew3;

twoD_Fig twoDFigXYw3(true,false,false,false);

twoD_Fig twoDFigYZw3(false,true,false,false);

twoD_Fig twoDFigXZw3(false,false,true,false);

double rotate_yw3=0; 
double rotate_xw3=0;

double rotate_yWw3=0; 
double rotate_xWw3=0;

ThirdWindow::ThirdWindow()
: m_Box(Gtk::ORIENTATION_VERTICAL),
  m_point_box(Gtk::ORIENTATION_VERTICAL),
  m_point_frame("Points"),
  m_point_frame_xy("Coordinates in xy projection"),
  m_point_frame_yz("Coordinates in yz projection"),
  m_point_frame_zx("Coordinates in zx projection"),
  m_input_frame("Input from file"),
  m_point_frame_buttons("Add/Reset"),
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

  // twoDFigXYw3.decide(0);

  // twoDFigYZw3.decide(1);

  // twoDFigXZw3.decide(2);

  // threeDfigw3.resetAllPoints();
  // newWireframew3.clear();

  // twoDFigXYw3.resetAllPoints();

  // twoDFigYZw3.resetAllPoints();

  // twoDFigXZw3.resetAllPoints();

  set_size_request(200, 100);
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
  m_point_frame_buttons.add(m_point_grid_buttons);

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
  m_point_grid_buttons.attach_next_to(m_reset_last_point ,m_Button_addvertex, Gtk::POS_RIGHT, 1, 1);
  m_point_grid_buttons.attach_next_to(m_reset_point, m_reset_last_point, Gtk::POS_RIGHT, 1, 1);
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
  //m_edge_grid.attach_next_to(m_label_edge, second_vertex, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_Button_addedge, first_vertex, Gtk::POS_BOTTOM, 2, 1);
  m_edge_grid.attach_next_to(m_reset_last_edge ,m_Button_addedge, Gtk::POS_RIGHT, 1, 1);
  m_edge_grid.attach_next_to(m_reset_edge, m_reset_last_edge, Gtk::POS_RIGHT, 1, 1);
  m_Button_addedge.signal_clicked().connect( sigc::mem_fun(*this,
              &ThirdWindow::add_edge_clicked) );



/*  m_Box.pack_start(m_face_frame, Gtk::PACK_EXPAND_WIDGET, 10);
  
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
*/
  m_Box.pack_start(m_create, Gtk::PACK_EXPAND_WIDGET, 10);

  m_create.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::create_clicked) );
  m_reset_point.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_point_clicked) );
  m_reset_last_point.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_last_point_clicked) ); 
  m_reset_edge.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_edge_clicked) );
  m_reset_last_edge.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_last_edge_clicked) );
  m_reset_face.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_face_clicked) );
  m_reset_last_face.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::reset_last_face_clicked) );
  m_input.signal_clicked().connect(sigc::mem_fun(*this,
      &ThirdWindow::m_input_clicked) );
 

  m_Button_addedge.set_sensitive(false);
  m_Button_addface.set_sensitive(false);
  m_reset_edge.set_sensitive(false);
  m_reset_last_edge.set_sensitive(false);
  m_reset_face.set_sensitive(false);
  m_reset_last_face.set_sensitive(false);
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
  twoDFigXYw3.addPoint(pointxy);
  twoDFigYZw3.addPoint(pointyz);
  twoDFigXZw3.addPoint(pointxz);
  m_input.set_sensitive(false);
  m_Button_addedge.set_sensitive(true);
  m_create.set_sensitive(true); 
}

void ThirdWindow::add_edge_clicked()
{

  int point_index1 = atoi(first_vertex.get_text().c_str());
  int point_index2 = atoi(second_vertex.get_text().c_str());
  int index = atoi(m_label_edge.get_text().c_str());
  twoDFigXYw3.addEdge(point_index1,point_index2,false);
  twoDFigYZw3.addEdge(point_index1,point_index2,false);
  twoDFigXZw3.addEdge(point_index1,point_index2,false);
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

void ThirdWindow::create_clicked()
{
	newWireframew3.regenerate(twoDFigXYw3, twoDFigYZw3, twoDFigXZw3);
	threeDfigw3.reconstruct(newWireframew3);
	// windowWireframew3();
	window3Dw3();
}
void ThirdWindow::reset_point_clicked()
{
  twoDFigXYw3.resetAllPoints();
  twoDFigYZw3.resetAllPoints();
  twoDFigXZw3.resetAllPoints();
}
void ThirdWindow::reset_last_point_clicked()
{
  twoDFigXYw3.resetLastPoint();
  twoDFigYZw3.resetLastPoint();
  twoDFigXZw3.resetLastPoint();
}
void ThirdWindow::reset_edge_clicked()
{
  twoDFigXYw3.resetAllEdges();
  twoDFigYZw3.resetAllEdges();
  twoDFigXZw3.resetAllEdges();
}
void ThirdWindow::reset_last_edge_clicked()
{
  twoDFigXYw3.resetLastEdge();
  twoDFigYZw3.resetLastEdge();
  twoDFigXZw3.resetLastEdge();
}
void ThirdWindow::reset_face_clicked()
{
  
}
void ThirdWindow::reset_last_face_clicked()
{
  
}
void ThirdWindow::m_input_clicked()
{
  m_reset_point.set_sensitive(false);
  m_reset_last_point.set_sensitive(false);
  m_create.set_sensitive(true);
  m_Button_addvertex.set_sensitive(false);
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
      double x_xy,y_xy,y_yz,z_yz,x_zx,z_zx;
      //getline(myfile,line);
      std::string substring;
      int l = line.length();
      int fp = 0;
      int lp = 0;
      int te = 0;
    for (int k=1;k<=3;k++){
	cout<<"\nGetting one proj of a point\n";
	getline(myfile,line);
	cout<<"\n At pos "<<k<<"  string : "<<line<<endl;
	int l = line.length();
      	int fp = 0;
      	int lp = 0;
      	int te = 0;
	//cout<<"\nLength : "<<l;
      	for (int i = 0; i < l; i++){
           char t = line.at(i);
           if(t == ','){
		lp = i;
		substring =line.substr(fp,(lp-fp));
		cout<<"\nSubstring1 is "<<substring<<endl;
		//cout<<"\n\n\nSubstring is::"<<substring;
                if(te==0 && k==1){ 
		x_xy=atof(substring.c_str());}
                if(te==0 && k==2){ 
		y_yz=atof(substring.c_str());}
                if(te==0 && k==3){ 
		x_zx=atof(substring.c_str());}
		//cout<<"\n\n\n\nVert is::"<<vert[te];
		te+=1;
		fp = i+1;
	   }
        }
	lp = l;
      	substring = line.substr(fp,(lp-fp));
	cout<<"\nSubstring2 is "<<substring<<endl;
	if(k==1){ 
	y_xy=atof(substring.c_str());}
	if(k==2){ 
	z_yz=atof(substring.c_str());}
	if(k==3){ 
	z_zx=atof(substring.c_str());}
      }
      getline(myfile,line); 
      int index=atoi(line.c_str());
	cout<<"\nGOT IT\n";	
  cout<<x_xy<<"  "<<y_xy<<"  "<<y_yz<<"  "<<z_yz<<"  "<<x_zx<<"  "<<z_zx<<"  : "<<index<<endl;
  Point2 pointxy(x_xy, y_xy, index, true, false, false, false);
  Point2 pointyz(y_yz, z_yz, index, false, true, false, false);
  Point2 pointxz(x_zx, z_zx, index, false, false, true, false);
  //string label = std::string(m_label.get_text());
  twoDFigXYw3.addPoint(pointxy);
  twoDFigYZw3.addPoint(pointyz);
  twoDFigXZw3.addPoint(pointxz);
 
   }
 //extracting edges----------------------------------------
    getline(myfile, line);
    int num_edges = atoi(line.c_str());
    for (int j=1;j<=num_edges;j++ )
    {
      std::string substring;
      getline(myfile,line);
      int l = line.length();
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
      twoDFigXYw3.addEdge(first_point,second_point,false);
      twoDFigYZw3.addEdge(first_point,second_point,false);
      twoDFigXZw3.addEdge(first_point,second_point,false);
      
    }
 //extracting faces
    /*int num_faces = atoi(line.c_str());
    for (int j=1;j<=num_faces;j++ )
    {
      getline(myfile,line);
      std::string substring;
      vector<int> vert;
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
      threeDfig.addFace(vert.size(),vert);    
    }*/
    
    myfile.close();
  }
}
