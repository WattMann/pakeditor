#include "pakeditor/ui.hpp"
#include <libpak/libpak.hpp>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "me.martin.pakeditor");

    Pakeditor::MasterWindow window;

    return app->run(window);
}