#include "Bird.h"
#include <iostream>
#include <sstream>
#include <cmath>

Bird::Bird(){
    //initial/internal values, set and get functions will change these
}

Bird::Bird(TwoVector position, TwoVector velocity)
    : fPosition(position), fVelocity(velocity) {}

Bird::~Bird(){

}

TwoVector Bird::GetPosition(){
    return fPosition;
}

TwoVector Bird::GetVelocity(){
    return fVelocity;
}

//sets x component of velocity:
void Bird::SetXVelocity(double q){
    fVelocity.SetX(q);
}

//sets y component of velocity:
void Bird::SetYVelocity(double q){
    fVelocity.SetY(q);
}

//sets x component of position:
void Bird::SetXPosition(double p){
    fPosition.SetX(p);
}

//sets y component of position:
void Bird::SetYPosition(double p){
    fPosition.SetY(p);
}

//function to prevent birds from leaving display window
TwoVector Bird::AvoidEdges(){
    int xmin = 50;
    int xmax = 950;//max pixel # in x direction
    int ymin = 50;
    int ymax = 950;//max pixel # in y direction

    if (fPosition.X() >= xmax){
        fVelocity.SetX(-(fVelocity.X())); //send bird in opposite direction
    }

    else if (fPosition.X()<=xmin){ //xmin
        fVelocity.SetX(fabs(fVelocity.X())); //send bird in opposite direction
    }

    else if (fPosition.Y()>=ymax){
        fVelocity.SetY(-fabs(fVelocity.Y())); //send bird in opposite direction
    }

    else if (fPosition.Y()<=ymin){
        fVelocity.SetY(fabs(fVelocity.Y())); //send bird in opposite direction
    }
}

//rule preventing velocity from becoming too high
TwoVector Bird::VelocityLimit(){
    //if velocity becomes greater than 3:
    if (fVelocity.Mag()>=3){
        //velocity remains at 3
        fVelocity = fVelocity.Unit()*3;
    }
}


