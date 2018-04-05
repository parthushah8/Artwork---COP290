#ifndef GTKMM_SecondWindow_H
#define GTKMM_SecondWindow_H

#include <gtkmm.h>

class SecondWindow : public Gtk::Window
{
public:
  SecondWindow();
  virtual ~SecondWindow();

protected:
  //Signal handlers:
  void add_vertex_clicked();
  void add_edge_clicked();
  void add_face_clicked();
  void on_button_close();
  void rotate_x_clicked();
  void rotate_y_clicked();
  void rotate_z_clicked();
  void create_3D_clicked();
  void create_top_clicked();
  void create_front_clicked();
  void create_side_clicked();
  void create_isometric_clicked();
  void reset_point_clicked();
  void reset_last_point_clicked();
  void reset_edge_clicked();
  void reset_last_edge_clicked();
  void reset_face_clicked();
  void reset_last_face_clicked();
  void m_input_clicked();
 
  //Child widgets:
  Gtk::Grid m_point_grid,m_edge_grid,m_face_grid,m_rotate_grid,m_create_grid;
  Gtk::Frame m_point_frame,m_edge_frame,m_face_frame,m_rotate_frame,m_create_frame;
  Gtk::Box m_Box;
  Gtk::Entry x_coordinate;
  Gtk::Entry y_coordinate;
  Gtk::Entry z_coordinate;
  Gtk::Entry m_label;
  Gtk::Entry first_vertex;
  Gtk::Entry second_vertex;
  Gtk::Entry m_label_edge;
  Gtk::Entry number_of_vertices;
  Gtk::Entry vertices_face;
  Gtk::Entry m_label_face;
  Gtk::Entry degrees_x;
  Gtk::Entry degrees_y;
  Gtk::Entry degrees_z;
  Gtk::Button m_Button_addvertex;
  Gtk::Button m_Button_addedge;
  Gtk::Button m_Button_addface;
  Gtk::Button m_rotate_x;
  Gtk::Button m_rotate_y;
  Gtk::Button m_rotate_z;
  Gtk::Button m_create_3D;
  Gtk::Button m_create_top;
  Gtk::Button m_create_front;
  Gtk::Button m_create_side;
  Gtk::Button m_create_isometric;
  Gtk::Button m_reset_point;
  Gtk::Button m_reset_last_point;
  Gtk::Button m_reset_edge;
  Gtk::Button m_reset_last_edge;
  Gtk::Button m_reset_face;
  Gtk::Button m_reset_last_face;


  //Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_SecondWindow_H
