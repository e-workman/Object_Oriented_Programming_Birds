#include "Starling.h"
#include <cmath>

Starling::Starling()
{

}

Starling::Starling(TwoVector position, TwoVector velocity)
: Bird(position, velocity) {}

Starling::~Starling() {
}

//update calculates velocity and position of each bird:
void Starling::update(TwoVector v_steer1, TwoVector v_steer2 , TwoVector v_steer3) {
    //starlings more display weaker alignment, but have a stronger separation force when compared to larks
    //they also have a dtronger cohesion force than larks
    //weighting of each force is determined by the constant each steering velcoity is multiplied by
    fVelocity +=( 0.6*v_steer1 + 0.3* v_steer2 +3 * v_steer3);

    Bird::VelocityLimit();

    fPosition += fVelocity;

    Bird::AvoidEdges();
}

int Starling::Species(){
    return 1;
}
