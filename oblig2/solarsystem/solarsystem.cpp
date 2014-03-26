#include <cstdlib>
#include <FL/Fl_Window.H>
#include <FL/Fl.H>

#include "class_solarsystem.h"
using namespace std;

int main(int argc, char** argv) {
    srand(static_cast <unsigned> (time(0)));
    Fl_Window * win = new Fl_Window(Fl::w(), Fl::h(), "Custom animation");
    win->position((Fl::w() - win->w())/2, (Fl::h() - win->h())/2);
    win->show();
    solarsystem ss("Custom animation", Fl::w(), Fl::h());
    
    return Fl::run();
}

