/* 
 * File:   main.cpp
 * Author: Andreas
 *
 * Created on den 15 mars 2014, 15:19
 */

#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "class_fireworks.h"
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

//window settings
#define WWIDTH Fl::w()
#define WHEIGHT Fl::h()
#define WFULLSCREEN false
#define WTITLE "Fireworks"

int main(int argc, char** argv) {
    srand(static_cast <unsigned> (time(0)));
    
    fireworks f(WTITLE, WWIDTH, WHEIGHT, 7);
    return Fl::run();
}

