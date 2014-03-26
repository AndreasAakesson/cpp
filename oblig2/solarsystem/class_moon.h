/* 
 * File:   class_moon.h
 * Author: Andreas
 *
 * Created on den 21 mars 2014, 13:44
 */

#ifndef CLASS_MOON_H
#define	CLASS_MOON_H

//Local includes
#include "class_is_vector.h"
#include "class_has_color.h"
#include "class_animated.h"
#include "class_astro_object.h"

class moon : public animated, is_vector, has_color, public astro_object {
  void draw() override;
public:
  moon(float _r, int _color, astro_object* _gravAround, float dist_x, float dist_y);  
  ~moon() override;
  void clear() override;
  void operator++() override;
  //void reset() override;
};


#endif	/* CLASS_MOON_H */

