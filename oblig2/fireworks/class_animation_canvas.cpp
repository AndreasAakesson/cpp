#include "class_animation_canvas.h"

#include <FL/Fl_Window.H>
#include "class_animated.h"

#include <iostream> // slett
#include "class_rocket.h" // slett

int animation_canvas::fps = 25;

animation_canvas::animation_canvas(const char *l,int w, int h)
        : Fl_Box(0, 0, w, h, l)
{
    // new window
    Fl_Window * win = new Fl_Window(w, h, l);
    // center window
    win->position((Fl::w() - win->w())/2, (Fl::h() - win->h())/2);
    // enables window
    win->show();
    //win->fullscreen();
    
    // creates canvas (black background)
    box(FL_FLAT_BOX);
    color(FL_BLACK);
    Fl_Box::draw();
    
    // starts animation
    Fl::add_timeout(1, timer, (void*)this);
}

animation_canvas::~animation_canvas() {
    for(auto it = parts.begin(); it != parts.end(); ++it) {
        delete *it;
    }
}

void animation_canvas::draw() {
    puts("Incrementing rockets");
    /*for(auto it = parts.begin(); it != parts.end(); ++it) {
        auto partptr = *it;
        ++(*partptr);
    }*/
}

void animation_canvas::add(animated* part) {
    parts.emplace_back(part); 
}

void animation_canvas::timer(void* canvas) {
    animation_canvas *c = static_cast<animation_canvas*>(canvas);
    
    for(int i = 0; i < c->parts.size(); i++) {
        auto p = c->parts[i];
        ++(*p);
    }
    
    Fl::repeat_timeout((float)1/fps, timer, canvas);
}
 