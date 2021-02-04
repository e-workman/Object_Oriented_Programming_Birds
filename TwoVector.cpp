#include <math.h>
#include <iostream>

#include "TwoVector.h"

TwoVector::TwoVector()
: fX(0.0), fY(0.0) {}

TwoVector::TwoVector(const TwoVector & p)
: fX(p.fX), fY(p.fY) {}

TwoVector::TwoVector(double xx, double yy)
: fX(xx), fY(yy) {}

TwoVector::TwoVector(const double * x0)
: fX(x0[0]), fY(x0[1]) {}

TwoVector::~TwoVector() {
}

double TwoVector::Mag() const
{
   // return the magnitude

   return sqrt(Mag2());
}

TwoVector TwoVector::Unit() const
{
   // return unit vector parallel to this.
   double  tot2 = Mag2();
   double tot = (tot2 > 0) ?  1.0/sqrt(tot2) : 1.0;
   TwoVector p(fX*tot,fY*tot);
   return p;
}

TwoVector operator + (const TwoVector & a, const TwoVector & b) {
   return TwoVector(a.X() + b.X(), a.Y() + b.Y());
}

TwoVector operator - (const TwoVector & a, const TwoVector & b) {
   return TwoVector(a.X() - b.X(), a.Y() - b.Y());
}

TwoVector operator * (const TwoVector &p, double a) {
   return TwoVector(a*p.X(), a*p.Y());
}

TwoVector operator * (double a, const TwoVector & p) {
   return TwoVector(a*p.X(), a*p.Y());
}

TwoVector operator / (TwoVector & p, int b) {
   return TwoVector(b/p.X(), b/p.Y());
}

TwoVector operator / (int b, TwoVector & p) {
   return TwoVector(b/p.X(), b/p.Y());
}

TwoVector operator / (TwoVector & p, float c) {
   return TwoVector(c/p.X(), c/p.Y());
}

TwoVector operator / (float c, TwoVector & p) {
   return TwoVector(c/p.X(), c/p.Y());
}

TwoVector operator /(TwoVector p, float c){
    return TwoVector(c/p.X(), c/p.Y());
}



