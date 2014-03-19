#include "class_rocket.h"

#include <FL/fl_draw.H> // hjelper å sette "overvekts"-farge

rocket::rocket(int _dotcount,int dotsize, int _fuse, int x, int y) {
    // rocket
    dotcount = _dotcount;
    fuse = _fuse;
    
    // animated
    done = false;
    t = 150;
    
    fl_color((rand()%236)+20);
    // creates dots
    for(int i = 0; i < dotcount; i++) {
        //dot* d = new dot(x,y,dotsize);
        //dots.push_back(*(d));
        dot d(x,y,dotsize);
        dots.push_back(d);
    }
    //++(*this);
    
}

rocket::~rocket(){
    dots.clear();
    puts("Deleting rocket");
}

void rocket::draw(){
    
}

void rocket::clear(){
    for(auto i = dots.begin(); i != dots.end(); i++) {
        i->clear();
    }
}

void rocket::reset(){
    for(auto i = dots.begin(); i != dots.end(); i++) {
        i->reset();
    }
}

void rocket::operator++(){
    --fuse; // dekrementerer fuse
    if(fuse > 0)
        return; // return hvis raketens lunte ikke brunnet opp ennå (venter på sin tur)
    
    t--; // dekrementer tiden
    for(auto it = dots.begin(); it != dots.end(); ++it) {
        ++(*it);
    }
}