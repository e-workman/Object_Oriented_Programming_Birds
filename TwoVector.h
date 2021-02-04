#ifndef TWOVECTOR_H
#define TWOVECTOR_H

class TwoVector
{
public:

    //The default constructor.
    TwoVector();
    //Another constructor.
    TwoVector(double x, double y);

    //Constructor from an array
    TwoVector(const double *);

    TwoVector(const TwoVector &);

    //The destructor.
    virtual ~TwoVector();

    inline double X()  const;
    inline double Y()  const;

    //Set the components
    void SetX(double);
    void SetY(double);
    void SetXY(double xx, double yy);

    //The magnitude squared
    inline double Mag2() const;

    //The magnitude
    double Mag() const;

    //Declaration of operators acting on the invoking instance
    inline TwoVector & operator = (const TwoVector &);

    //Addition.
    inline TwoVector & operator += (const TwoVector &);

    //Subtraction.
    inline TwoVector & operator -= (const TwoVector &);

    //Unary minus.
    inline TwoVector operator - () const;

    //Scaling with real numbers.
    inline TwoVector & operator *= (double);

    //Unit vector parallel to this.
    TwoVector Unit() const;

    //Printing the content in a convenient way
    //void Print() const;

private:

    double fX, fY;
    // The components.
};

//Declaration of operators without an invoking instance. They must be global, thus
//declared outside the scope of the class
//Addition of 3-vectors.
TwoVector operator + (const TwoVector &, const TwoVector &);

//Subtraction of 3-vectors.
TwoVector operator - (const TwoVector &, const TwoVector &);

//Scaling of 3-vectors with a real number
TwoVector operator * (const TwoVector &, double a);
TwoVector operator * (double a, const TwoVector &);

TwoVector operator / (TwoVector &, int b);
TwoVector operator / (int b, const TwoVector &);

TwoVector operator / (TwoVector &, float c);
TwoVector operator / (float c, const TwoVector &);

TwoVector operator /(TwoVector, float c);
TwoVector operator /(float c, const TwoVector);

inline double TwoVector::X()  const { return fX; }
inline double TwoVector::Y()  const { return fY; }

inline void TwoVector::SetX(double xx) { fX = xx; }
inline void TwoVector::SetY(double yy) { fY = yy; }

inline void TwoVector::SetXY(double xx, double yy) {
   fX = xx;
   fY = yy;

}

inline double TwoVector::Mag2() const { return fX*fX + fY*fY; }

//All operators involving assignment return the invoking instance itself
//by dereferencing the pointer this
inline TwoVector & TwoVector::operator = (const TwoVector & p) {
   fX = p.fX;
   fY = p.fY;

   return *this;
}

inline TwoVector& TwoVector::operator += (const TwoVector & p) {
   fX += p.fX;
   fY += p.fY;

   return *this;
}

inline TwoVector& TwoVector::operator -= (const TwoVector & p) {
   fX -= p.fX;
   fY -= p.fY;

   return *this;
}

inline TwoVector TwoVector::operator - () const {
   return TwoVector(-fX, -fY);
}

inline TwoVector& TwoVector::operator *= (double a) {
   fX *= a;
   fY *= a;

   return *this;
}

#endif /* TWOVECTOR_H_ */
