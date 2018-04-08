#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

private:
  // Signal handlers:
  void on_button_quit();
  void on_button_numbered1(const Glib::ustring& data);
  void on_button_numbered2(const Glib::ustring& data);

  // Child widgets:
  Gtk::Grid m_grid;
  Gtk::Button m_button_1, m_button_2, m_button_quit;
  Gtk::Box m_Vbox1, m_Vbox2, m_Vbox3, m_Vbox4;

};

#endif /* GTKMM_EXAMPLEWINDOW_H */
