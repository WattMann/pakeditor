#include "pakeditor/ui.hpp"
#include "gtkmm/filechooser.h"
#include "gtkmm/menuitem.h"
#include "sigc++/functors/mem_fun.h"
#include <iostream>

void Pakeditor::MasterWindow::on_file_open() {
 Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("Select", Gtk::RESPONSE_OK);

  int result = dialog.run();

  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "File chooser: selected -> " << dialog.get_filename()
          << std::endl;
      this->load_file(dialog.get_filename());    
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      std::cout << "File chooser: cancelled" << std::endl;
      break;
    }
    default:
    {
      std::cout << "File chooser: unexpected action selected" << std::endl;
      break;
    }
  }
}

void Pakeditor::MasterWindow::load_file(std::string path) {
    //TODO: implement
}

Pakeditor::MasterWindow::MasterWindow() : ui{Gtk::Builder::create_from_file("master.glade")} {
    if(ui) {
        ui->get_widget<Gtk::Grid>("master_grid", grid);
        ui->get_widget<Gtk::ListBox>("explorer", explorer);


        ui->get_widget<Gtk::MenuItem>("file_open", file_open);
        file_open->signal_activate().connect(
        sigc::mem_fun(*this,
      &Pakeditor::MasterWindow::on_file_open)
        );

        add(*grid);
    }

    set_title("Pakeditor");
    set_default_size(400, 400);
    show_all();
}