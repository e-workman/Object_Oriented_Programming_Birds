#include "Lark.h"

#include <cmath>

Lark::Lark(TwoVector position, TwoVector velocity)
    :Bird(position, velocity){}

Lark::~Lark(){}

//update calculates velocity and position of each bird:
void Lark::update(TwoVector v_steer1, TwoVector v_steer2 , TwoVector v_steer3) {
    //larks more strongly align, but have weaker separation force when compared to starling
    //they also have a weaker cohesion force than starlings
    //weighting of each force is determined by the constant each steering velcoity is multiplied by
    fVelocity +=( 2 * v_steer1 +0.3 * v_steer2 + 2 * v_steer3);

    Bird::VelocityLimit();

    fPosition += fVelocity;

    Bird::AvoidEdges();
}

int Lark::Species(){
    return 2;
}
