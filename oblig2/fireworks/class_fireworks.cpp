#include "class_fireworks.h"
#include "class_rocket.h"

#include <iostream> // slett

#include <random> // random

#define DOTCOUNT 250
#define DOTSIZE 5

using namespace std;

fireworks::fireworks(const char* title, int w, int h, int _rocketcount) 
        : animation_canvas(title, w, h)
{
    rocketcount = _rocketcount;
    int x_max = w - w/10;
    int x_min = w/10;
    int y_max = h - h/10;
    int y_min = h/10;
    
    //cout << y_max << " " << y_min << endl;
    
    //default_random_engine generator;
    //uniform_int_distribution<int> xrand(x_min,x_max);
    //uniform_int_distribution<int> yrand(y_min,y_max);
    
    for(int i = 0; i < rocketcount; i++) {
        int fuse = i*50;
        int xpos = (rand()% (x_max-x_min)) + x_min;
        int ypos = (rand()% (y_max-y_min)) + y_min;
        //int xpos = xrand(generator);
        //int ypos = yrand(generator);
        
        add(new rocket(DOTCOUNT, DOTSIZE, fuse, xpos, ypos));
        cout << "Adding Rocket to (x:y) " << xpos << ":" << ypos << endl;
    }
}

fireworks::~fireworks(){
}
