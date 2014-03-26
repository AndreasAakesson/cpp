#ifndef CLASS_PLANET_H
#define	CLASS_PLANET_H

//Local includes
#include "class_is_vector.h"
#include "class_has_color.h"
#include "class_animated.h"
#include "class_astro_object.h"

class planet : public animated, is_vector, has_color, public astro_object {
  void draw() override;
public:
  planet(float _r, int _color, astro_object* _gravAround, float dist_x, float dist_y);  
  ~planet() override;
  void clear() override;
  void operator++() override;
  //void reset() override;
};

#endif	/* CLASS_PLANET_H */

