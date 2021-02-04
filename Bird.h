#ifndef BIRD_H
#define BIRD_H
#include "TwoVector.h"

class Bird
{
public:
    //default constructor
    Bird();
    //destructor
    Bird(TwoVector position, TwoVector velocity);
    virtual ~Bird();

    //update function will update the bird's velocity and position:
    virtual void update(TwoVector v_steer1, TwoVector v_steer2 , TwoVector v_steer3)=0;

    //two functions which get position and velocity of the bird:
    TwoVector GetPosition();
    TwoVector GetVelocity();

    //sets the x and y components of the velocity:
    void SetXVelocity(double q);
    void SetYVelocity(double q);

    //sets the x and y components of the position:
    void SetXPosition(double p);
    void SetYPosition(double p);

    //defines what species the bird is:
    virtual int Species()=0;

    //prevents birds from leaving display window:
    TwoVector AvoidEdges();

    //prevents velocity of birds from bcoming too large:
    TwoVector VelocityLimit();

//private data members (velocity and position of bird):
protected:
    TwoVector fVelocity;
    TwoVector fPosition;
};

#endif // BIRD_H
