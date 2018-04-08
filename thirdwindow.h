#ifndef GTKMM_ThirdWindow_H
#define GTKMM_ThirdWindow_H

#include <gtkmm.h>

class ThirdWindow : public Gtk::Window
{
public:
  ThirdWindow();
  virtual ~ThirdWindow();

protected:
  //Signal handlers:
  void add_vertex_clicked();
  void add_edge_clicked();
  void add_face_clicked();
  void create_clicked();
  void reset_point_clicked();
  void reset_last_point_clicked();
  void reset_edge_clicked();
  void reset_last_edge_clicked();
  void reset_face_clicked();
  void reset_last_face_clicked();
  void m_input_clicked();  

  //Child widgets:
  Gtk::Grid m_point_grid_xy,m_point_grid_yz,m_point_grid_zx,m_edge_grid,m_face_grid,m_point_grid_buttons;
  Gtk::Frame m_point_frame,m_edge_frame,m_face_frame,m_point_frame_xy,m_point_frame_yz,m_point_frame_zx,m_point_frame_buttons;
  Gtk::Box m_Box,m_point_box;
  Gtk::Entry m_point;
  Gtk::Entry x_coordinate_xy;
  Gtk::Entry y_coordinate_xy;
  Gtk::Entry z_coordinate_xy;
  Gtk::Entry x_coordinate_yz;
  Gtk::Entry y_coordinate_yz;
  Gtk::Entry z_coordinate_yz;
  Gtk::Entry x_coordinate_zx;
  Gtk::Entry y_coordinate_zx;
  Gtk::Entry z_coordinate_zx;
  Gtk::Entry first_vertex;
  Gtk::Entry second_vertex;
  Gtk::Entry m_label_edge;
  Gtk::Entry number_of_vertices;
  Gtk::Entry vertices_face;
  Gtk::Entry m_label_face;
  Gtk::Button m_Button_addvertex;
  Gtk::Button m_Button_addedge;
  Gtk::Button m_Button_addface;
  Gtk::Button m_create;
  Gtk::Button m_reset_point;
  Gtk::Button m_reset_last_point;
  Gtk::Button m_reset_edge;
  Gtk::Button m_reset_last_edge;
  Gtk::Button m_reset_face;
  Gtk::Button m_reset_last_face;
  //Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_ThirdWindow_H
