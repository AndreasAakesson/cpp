#include "class_dot.h"

#include <FL/fl_draw.H>
#include <random>
#include <iostream> // slett
#include <math.h> // ???

using namespace std;

dot::dot(float _x, float _y, float _r) {
    // dot
    x = _x;
    y = _y;
    r = _r;
    x_orig = _x;
    y_orig = _y;
    
    // animated
    done = false;
    t = 100;
    
    // has_color
    //color = (rand()%236)+20;
    color = fl_color();
    
    color = fl_color_average((rand()%236)+20, color, 0.5);
    
    // setter retning og hastighet
    direction = static_cast<float> (rand()) / TAU;
    speed = static_cast<float> (rand()) / static_cast<float> (RAND_MAX/5) + 1.0;
}

dot::~dot() {
    
}

void dot::draw() {
    //fl_color(*red, *green, *blue);
    fl_color(color);
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void dot::clear() {
    //använd bakgrundsfärg till canvas
    fl_color(FL_BLACK);
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void dot::operator++(){
    clear();
    if(done)
        return;
    
    //justerer færge/fader ut..
    if(t < 50) {
       float fade = t/(50.0);
       color = fl_color_average(color, FL_BLACK, fade);
    }
    //color = fl_color_average(color, FL_BLACK, 0.97); - annen løsning
    
    // beregne ny x/y med hjelp av has_vector
    float incx = sin(direction)*speed;
    float incy = cos(direction)*speed;
    // setter ny koordinat/"flytter"
    x += incx;
    y += incy;
    // tegner dot
    
    
    
    /* Gjør animasjonen VELDIG treg.
    if((x > Fl::w() || x < 0) || (y > Fl::h() || y < 0 ))
        done = true;
    */
    done = (--t == 0);
    draw();
}

void dot::reset(){
    x = x_orig;
    y = y_orig;
    //clear();
}
