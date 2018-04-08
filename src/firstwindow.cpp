#include <iostream>
#include "firstwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"

ExampleWindow::ExampleWindow()
: m_Vbox1(Gtk::ORIENTATION_VERTICAL),
  m_Vbox2(Gtk::ORIENTATION_VERTICAL),
  m_Vbox3(Gtk::ORIENTATION_VERTICAL),
  m_Vbox4(Gtk::ORIENTATION_VERTICAL),
  m_button_1("3D to 2D"),
  m_button_2("2D to 3D"),
  m_button_quit("Quit")
{
  set_title("Artworks");
  set_border_width(12);

  add(m_Vbox1);
  m_Vbox1.pack_start(m_Vbox2);
  m_Vbox1.pack_start(m_Vbox3);
  m_Vbox3.add(m_button_1);
  //m_grid.add(m_button_2);
  m_Vbox3.add(m_button_2);
  m_Vbox3.add(m_button_quit);

  m_button_1.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
      &ExampleWindow::on_button_numbered1), "button 1") );
  m_button_2.signal_clicked().connect(
    sigc::bind<Glib::ustring>( sigc::mem_fun(*this,
      &ExampleWindow::on_button_numbered2), "button 2") );

  m_button_quit.signal_clicked().connect(sigc::mem_fun(*this,
    &ExampleWindow::on_button_quit) );
  	
  show_all_children();
}


ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
  hide();
}

void
ExampleWindow::on_button_numbered1(const Glib::ustring& data)
{
  SecondWindow* window1 = new SecondWindow;
  window1->show();
	 //std::cout << data << " was pressed" << std::endl;
}

void
ExampleWindow::on_button_numbered2(const Glib::ustring& data)
{
  ThirdWindow* window2 = new ThirdWindow;
  window2->show();
	 //std::cout << data << " was pressed" << std::endl;
}
