#include "class_star.h"

#include <FL/fl_draw.H>
#include <math.h>

star::star(float _r, int _color)
        : astro_object(0,0, _r) {
    color = _color;
    
}

star::~star() {
}

void star::draw() {
    int border = r/40;
    fl_color(color+20);
    fl_pie(x-border, y-border, r+(border*2), r+(border*2), 0.0, 360.0);
    
    if((darkness < 0.5 && fade > 0) || (darkness > 0.95 && fade < 0))
            fade *= -1;
    darkness -= 0.02*fade;
    fl_color(fl_color_average(color,FL_WHITE, darkness));
    
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void star::operator ++() {
    draw();
}

void star::clear() {
    // no need..
}

void star::center() {
    x = (Fl::w()/2)-(r/2);
    y = (Fl::h()/2)-(r/2);
}
