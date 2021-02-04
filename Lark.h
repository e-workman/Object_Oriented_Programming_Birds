#ifndef LARK_H
#define LARK_H

#include "Bird.h"

//lark inherits from Bird:
class Lark: public Bird
{
public:
    Lark();

    Lark(TwoVector position, TwoVector velocity);

    virtual ~Lark();

    //updates position and velocity of a lark
    virtual void update(TwoVector v_steer1, TwoVector v_steer2 , TwoVector v_steer3);

    int Species();
};

#endif // LARK_H
