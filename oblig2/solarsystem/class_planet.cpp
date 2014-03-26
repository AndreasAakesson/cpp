#include "class_planet.h"

#include <FL/fl_draw.H>

planet::planet(float _r, int _color, astro_object* _gravAround, float dist_x, float dist_y) 
        : astro_object(dist_x, dist_y, _r, _gravAround) {
    r = _r;
    color = _color;
    distance_x = dist_x;
    distance_y = dist_y;
    speed=TAU/200;
    direction=-1;
    
    _gravAround->add_hasGrav(this);
    
}

planet::~planet() {
}

void planet::draw() {
    fl_color(color);
    fl_pie(x, y, r, r, 0.0, 360.0);
}

void planet::operator ++() {
    clear();
    angle += speed*direction;
    x = distance_x * cos(angle) + (isGrav->getX()-(r/2));
    y = distance_y * sin(angle) + (isGrav->getY()-(r/2));
    draw();
}

void planet::clear() {
    fl_color(FL_BLACK);
    fl_pie(x, y, r, r, 0.0, 360.0);
}
