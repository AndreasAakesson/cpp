#include "class_solarsystem.h"
#include "class_star.h"
#include "class_planet.h"
#include "class_moon.h"

using namespace std;

solarsystem::solarsystem(const char* title, int w, int h) 
        : animation_canvas(title, w, h)
{
    for(int i = 0; i < 50; i++)
        add(new star(5, FL_CYAN));
    
    star* sun = new star(200, FL_YELLOW);
    sun->center();
    add(sun);
    planet* earth = new planet(80, FL_DARK_GREEN, sun, 400, 250);
    add(earth);
    moon* damoon = new moon(30, FL_GRAY, earth, 60, 60);
    add(damoon);
}

solarsystem::~solarsystem(){
}
