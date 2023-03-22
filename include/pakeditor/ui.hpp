#ifndef pakeditor_ui_hpp
#define pakeditor_ui_hpp

#include <exception>
#include <gtkmm.h>
#include <string>

namespace Pakeditor {
  
class MasterWindow : public Gtk::ApplicationWindow {
    Glib::RefPtr<Gtk::Builder> ui;
    Gtk::Grid *grid;
    Gtk::ListBox *explorer;
    Gtk::MenuItem *file_open;
public:
    MasterWindow();
    void load_file(std::string path);

private:
    void on_file_open();
};

}

#endif // pakeditor_ui_hpp