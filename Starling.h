#ifndef STARLING_H
#define STARLING_H

#include "Bird.h"

//starling inherits from Bird:
class Starling: public Bird
{
public:
    Starling();

    Starling(TwoVector position, TwoVector velocity);

    virtual ~Starling();

    //updates position and velocity of a starling
    virtual void update(TwoVector v_steer1, TwoVector v_steer2 , TwoVector v_steer3);

    int Species();
};

#endif // STARLING_H
