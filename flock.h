#ifndef FLOCK_H
#define FLOCK_H

#include <vector>
#include <time.h>

#include "Bird.h"
#include "Starling.h"
#include "Lark.h"

//contains a vector of N birds
//contains functions which describe interactions between the birds (cohesion, separation and alignment)

class Flock
{
public:
    Flock(); //default constructor
    Flock(std::vector<Bird*> Birds); //overload constructor
    virtual ~Flock(); //destructor

    //initial state of the flock (creates NBirds with random velocities and positions):
    void CreateFlock(int NStarlings, int NLarks);


    //gets N birds, number of birds in flock. Returns number of birds in the flock:
    int GetNBirds();

    //gets pointer to ith bird, returns the pointer to ith bird in the array
    Bird*GetBird(int iBird);

    //The 3 rules which the birds in the flock abide; alignment, cohesion and separation:
    //Functions of a vector of pointers of birds and the ith bird in the array:
    TwoVector Align(std::vector<Bird*> birds, int iBird);
    TwoVector Cohesion(std::vector<Bird*> birds, int iBird);
    TwoVector Separation(std::vector<Bird*> birds, int iBird);

    //Simulate finds align, cohesion, speartion velocity of each bird in the flock:
    void Simulate();

private:
    //creates a vector of pointers to Birds class, an array of birds:
    std::vector<Bird*> fBirds;
};

#endif // FLOCK_H
