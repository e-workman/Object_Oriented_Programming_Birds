#include <iostream>
#include "Flock.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>


Flock::Flock(){
}

Flock::Flock(std::vector<Bird*> Birds){
    fBirds = Birds;
}


//Destructor:
Flock::~Flock(){
}

int Flock::GetNBirds(){ // gets N birds, number of birds in flock, returns number of birds in the flock
    return fBirds.size();
}

Bird* Flock::GetBird(int iBird){ //gets pointer to ith bird, returns the pointer to ith bird in the array
    return fBirds[iBird];
}

//creates NBirds with random velocities and positions:
//initial state of the flock:
void Flock::CreateFlock(int NStarlings, int NLarks){

    srand(time(NULL)); //the seed of the random number generator is the time.

    //loop over all starlings, NStarlings is number of starlings input by user
    for (int iBird=0; iBird<NStarlings; iBird++){

        //random x and y positions in display window:
        TwoVector a(rand() % 1000, rand() % 1000);

        //Set random initial x and y velocities between -1 and 1:
        TwoVector b(rand() %2 - 1, rand() %2 -1);

        //pointer to bird:
        Bird *ptrStarling = new Starling(a,b);

        //push_back: Adds a new element at the end of the vector, after its current last element.
        //increases the size of the container by one.
        fBirds.push_back(ptrStarling);
    }

    for (int iBird=0; iBird<NLarks; iBird++){

        //random x and y positions in display window between 0 and 300 pixels (so they initially start out as group):
        TwoVector a(rand() % 1000, rand() % 1000);

        //Set random initial x and y velocities between -1 and 1:
        TwoVector b(rand() % 2 - 1, rand() % 2 - 1);

        //pointer to bird:
        Bird *ptrLark = new Lark(a,b);

        //push_back: Adds a new element at the end of the vector, after its current last element.
        //increases the size of the container by one.
        fBirds.push_back(ptrLark);
    }
}

//calculating alignment velocity of one bird:
//will return a velocity vector
TwoVector Flock::Align(std::vector<Bird *> birds, int iBird){
    int NBirds = birds.size(); //number of birds in the flock

    TwoVector v_tot_star; //sum of velocities of all the starlings
    TwoVector v_tot_lark; //sum of velocities of all the larks
    TwoVector v_star; //velocity vector pointing from starling to average velocity of other starlings
    TwoVector v_lark; //velocity vector pointing from lark to average velocity of other larks

    //calculate v_steer1 (align):
    //loop over all birds in flock:
    for(int jBird = 0; jBird<NBirds; jBird++){
        //if bird in the flock is not the bird being considered
        if (jBird != iBird){
            //distance between birds:
            TwoVector x = birds[iBird]->GetPosition() - birds[jBird]->GetPosition();
            //magnitude of distance between birds
            double x_mag = x.Mag();
            //if bird in the flock is a starling:
            if (birds[jBird]->Species() == 1){
                //if the distance between the bird being considered and another bird in the flock is less than 1000 pixels, then the bird will steer in its direction
                if (x_mag < 100){
                    //want to match velocity of other starlings
                    //velocity of jBird:
                    TwoVector v_jBird_Star = birds[jBird]->GetVelocity();
                    //vector of total velocity of all starlings in flock:
                    v_tot_star +=  v_jBird_Star;

                }
            }
            //if bird is a lark (Species() = 2):
            if (birds[jBird]->Species() == 2){
                //if the distance between the bird being considered and another bird in the flock is less than 100 pixels, then the bird will steer in its direction
                if (x_mag < 100){
                    //want to match velocity of other larks
                    //velocity of jBird:
                    TwoVector v_jBird_Lark = birds[jBird]->GetVelocity();
                    //vector of total velocity of all larks in flock:
                    v_tot_lark += v_jBird_Lark;

                }
            }
        }
    }
    //if bird being considered is a starling
    if (birds[iBird]->Species() == 1){
        //direction starling will steer towards
        v_star = v_tot_star - birds[iBird]->GetVelocity();
        //unit vector pointing in direction starling will steer
        TwoVector a = v_star.Unit();
        return a;
    }
    //if bird being considered is a lark
    if (birds[iBird]->Species() == 2){
        //direction lark will steer towards
        v_lark = v_tot_lark - birds[iBird]->GetVelocity();
        //unit vector pointing in direction lark will steer
        TwoVector a = v_lark.Unit();
        return a;
    }
}


//calculating cohesion velocity of one bird:
//will return a velocity vector:
TwoVector Flock::Cohesion(std::vector<Bird *> birds, int iBird){
    int NBirds = birds.size(); // number of birds in flock

    TwoVector P_tot_star; //sum of the positions of all the starlings
    TwoVector P_tot_lark; //sum of the positions of all the larks
    //calculate v_steer2 (cohesion):
    //loop over all birds in flock:
    for(int jBird=0; jBird<NBirds; jBird++){
        //if the bird in the flock is not the bird we are looking at:
        if (jBird != iBird){
            //if bird in flock is a starling:
            if (birds[jBird]->Species() == 1){
                //find centre of mass of all starlings
                //get position of jBird:
                TwoVector P_jBird_star = birds[jBird]->GetPosition()- birds[iBird]->GetPosition();
                //sum of the positions of all the birds:
                P_tot_star += P_jBird_star;
            }
            //if bird in flock is a lark:
            if (birds[jBird]->Species() == 2){
                //find centre of mass of all larks
                //get position of jBird:
                TwoVector P_jBird_lark = birds[jBird]->GetPosition() - birds[iBird]->GetPosition();
                //sum of the positions of all the birds
                P_tot_lark += P_jBird_lark;
            }
        }
    }
    //if bird is a starling:
    if (birds[iBird]->Species()==1){
        //vector pointing from starling towards the centre of mass of all starlings
        TwoVector COM = P_tot_star ;
        //unit vector pointing from starling towards the centre of mass of all starlings
        TwoVector v = COM.Unit();
        return v;
    }
    //if bird is a lark
    if (birds[iBird]->Species()==2){
        //vector pointing from lark towards the centre of mass of all larks
        TwoVector COM = P_tot_lark;
        //unit vector pointing from lark towards the centre of mass of all larks
        TwoVector v = COM.Unit();
        return v;
    }
}

//calculating separation velocity of one bird:
//will return a velocity vector
TwoVector Flock::Separation(std::vector<Bird *> birds, int iBird){
    //number of birds in the flock
    int NBirds = birds.size();

    //calculate the distance between the birds (separation):
    TwoVector d_star; //a vector pointing away from position of starling in the flock:
    TwoVector d_lark; //a vector pointing away from position of lark in the flock:

    //loops over all the birds in the flock:
    for (int jBird=0; jBird<NBirds; jBird++){
        //if the bird in the flock is not the bird we are looking at:
        if (jBird != iBird){
            //if bird in flock is a starling:
            if(birds[jBird]->Species() == 1){
                //if bird is less than 50 pixels away from a starling in the flock
                if ((birds[iBird]->GetPosition() - birds[jBird]->GetPosition()).Mag() < 30) {
                    //a vector, d_star, pointing away from position of starling in the flock:
                    d_star += birds[iBird]->GetPosition() - birds[jBird]->GetPosition();
                }
            }
            //if bird in flock is a lark:
            if(birds[jBird]->Species() == 2){
                //if bird is less than 50 pixels away from a lark in the flock
                if ((birds[iBird]->GetPosition() - birds[jBird]->GetPosition()).Mag() < 20) {
                    //a vector pointing away from position of lark in the flock:
                    d_lark += (birds[iBird]->GetPosition() - birds[jBird]->GetPosition());
                }
           }
        }
    }
    //if bird being considered is a starling, it only separates from other starlings
    if (birds[iBird]->Species() == 1){
            //unit vector in direction away from the starling in the flock
            TwoVector v = d_star.Unit();
            return v;
    }
    //if bird being considered is a lark, it only separates from other lark
    if (birds[iBird]->Species() == 2){
            //unit vector in direction away from the lark in the flock
            TwoVector v = d_lark.Unit();
            return v;
    }
}

//find align, cohesion, speartion velocity of each bird in the flock.
void Flock::Simulate(){
    //loops through all the birds:
    for (unsigned int iBird = 0; iBird < GetNBirds(); ++iBird){
        TwoVector v_steer1;
        TwoVector v_steer2;
        TwoVector v_steer3;

        TwoVector v_align = Align(fBirds, iBird);
        v_steer1.SetXY(v_align.X(), v_align.Y()); //sets v_steer1 to align velocity

        TwoVector v_cohesion = Cohesion(fBirds, iBird);
        v_steer2.SetXY(v_cohesion.X(), v_cohesion.Y()); //sets v_steer2 to cohesion velocity

        TwoVector v_separation = Separation(fBirds, iBird);
        v_steer3.SetXY(v_separation.X(), v_separation.Y()); //sets v_stee3 to separation velocity

        //Calling update on each bird:
        GetBird(iBird)->update(v_steer1, v_steer2, v_steer3);
    }
}
