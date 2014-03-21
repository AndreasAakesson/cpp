#include "class_rocket.h"

#include <FL/fl_draw.H> // hjelper å sette "overvekts"-farge

rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) {
    // rocket
    dotcount = _dotcount;
    fuse = _fuse;
    
    // animated
    done = false;
    t = 70;
    
    // bestemmer overvekts færge for dots i rocket, dvs første dotens færge.
    fl_color((rand()%206)+50);
    // creates dots
    for(int i = 0; i < dotcount; i++) {
        dot d(x,y,dotsize);
        dots.push_back(d);
    }
}

rocket::~rocket(){
    dots.clear();
    puts("Deleting rocket");
}

void rocket::draw(){
    for(auto it = dots.begin(); it != dots.end(); ++it) {
        ++(*it);
    }
}

void rocket::clear(){
    for(auto i = dots.begin(); i != dots.end(); i++) {
        ((dot)*i).clear();
        // i->clear(); IDE gir feil
    }
}

void rocket::reset(){
    for(auto i = dots.begin(); i != dots.end(); i++) {
        ((dot)*i).reset();
        // i->reset(); IDE gir feil
    }
}

void rocket::operator++(){
    if(done)
        return;
    --fuse; // dekrementerer fuse
    if(fuse > 0)
        return; // return hvis raketens lunte ikke brunnet opp ennå (venter på sin tur)
    
    draw();
    if(--t == 0) {
        reset();
        done = true;
    }
    //done = (--t == 0);
}