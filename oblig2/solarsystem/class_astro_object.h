#ifndef CLASS_ASTRO_OBJECT_H
#define	CLASS_ASTRO_OBJECT_H
/* A astronomical object. (sun, planet, moon, etc...)
 */
#include <vector>
class astro_object {
protected:
    float x;
    float y;
    float r;
    astro_object* isGrav; // is graviating around
    //orbit radius
    float distance_x;
    float distance_y;
    std::vector<astro_object*> hasGrav; // has graviating around
    astro_object(float dist_x, float dist_y, float _r, astro_object* _isGrav=0);
public:
    void add_hasGrav(astro_object* astro_obj);
    float getX();
    float getY();
    virtual ~astro_object(){};
};

#endif	/* CLASS_ASTRO_OBJECT_H */

