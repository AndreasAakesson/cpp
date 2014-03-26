#ifndef CLASS_FIREWORKS_H
#define CLASS_FIREWORKS_H

//Local includes
#include "class_animation_canvas.h"

class solarsystem: public animation_canvas  {
  int rocketcount;

 public:
  solarsystem(const char* title,int w, int h);
  ~solarsystem() override;
};


#endif
