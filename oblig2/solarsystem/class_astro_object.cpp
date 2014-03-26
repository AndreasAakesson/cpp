#include "class_astro_object.h"
#include <cstdlib>
#include <FL/Fl.H>

astro_object::astro_object(float dist_x, float dist_y, float _r, astro_object* _isGrav) {
    distance_x = dist_x;
    distance_y = dist_y;
    r = _r;
    if(_isGrav) {
        isGrav = _isGrav;
        x = isGrav->getX();
        y = isGrav->getY();
    }
    else {
        x = rand()%Fl::w();
        y = rand()%Fl::h();
    }
}

void astro_object::add_hasGrav(astro_object* astro_obj) {
    hasGrav.emplace_back(astro_obj);
}

float astro_object::getX() {
    return x+(r/2);
}

float astro_object::getY() {
    return y+(r/2);
}