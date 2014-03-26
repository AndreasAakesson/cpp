#ifndef CLASS_STAR_H
#define	CLASS_STAR_H

//Local includes
#include "class_is_vector.h"
#include "class_has_color.h"
#include "class_animated.h"
#include "class_astro_object.h"

class star : public animated, is_vector, has_color, public astro_object {
  void draw() override;
public:
  star(float _r, int _color);  
  ~star() override;
  void clear() override;
  void operator++() override;
  void center();
  //void reset() override;
};


#endif	/* CLASS_SUN_H */

