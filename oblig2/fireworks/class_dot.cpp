#include "class_dot.h"

#include <FL/fl_draw.H>
#include <random>
#include <iostream> // slett
#include <math.h> // ???

/* Bestemmer hvor stor andel (av den tidligere satte fargen)
 * den ny færgen (denne doten sin) skal innholde */
#define COLOR_DIS 0.75 
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
    t = 70;
    
    // has_color
    // henter tidligere færge (gitt av dot eller rocket) og blander denne med ny random færge.
    color = fl_color_average(fl_color(), (rand()%236)+20, COLOR_DIS);
    
    // setter retning og hastighet
    direction = static_cast<float> (rand()) / TAU;
    speed = static_cast<float> (rand()) / static_cast<float> (RAND_MAX/5) + 1.0;
}

dot::~dot() {
    
}

void dot::draw() {
    fl_color(color);
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void dot::clear() {
    //använd bakgrundsfärg till canvas
    fl_color(FL_BLACK);
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void dot::operator++(){
    
    if(done) // hvis animasjonen er ferdig
        return;
    clear();
    
    //justerer færge/fader ut.. denne er ikke bulletproof.
    if(t < 20) {
       float fade = t/(10.0); // 10.0 gir kul blinkende effekt. 20.0 for riktig fadeout.
       color = fl_color_average(color, FL_BLACK, fade);
    }
    //color = fl_color_average(color, FL_BLACK, 0.97); - annen løsning
    
    // beregne ny x/y med hjelp av has_vector
    float incx = sin(direction)*speed;
    float incy = cos(direction)*speed;
    // setter ny koordinat/"flytter"
    x += incx;
    y += incy;
    
    /* Gjør animasjonen VELDIG treg. Sjekk for å ikke tegne utenfør
    if((x > Fl::w() || x < 0) || (y > Fl::h() || y < 0 ))
        done = true;
    */
    done = (--t == 0); // bestemmer om animasjonen er ferdig
    // tegner dot
    draw();
}

void dot::reset(){
    clear();
    x = x_orig;
    y = y_orig;
}
