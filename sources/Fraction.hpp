#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <numeric>
#include<cmath>

using namespace std;
 namespace ariel{
class Fraction
{
   int nom ;//numerator
   int denom ;//denominator
public:
   //int getNom();
   //int getDenom();
   int const getNom();
   int const getDenom();
    //Constructors:
    Fraction();
    Fraction(int new_n, int new_d);
    Fraction(double dbl)
    {
      Fraction temp = Fraction::toFraction(dbl);
      nom = temp.getNom();
      denom = temp.getDenom();
    }
    //

    void simplify();
    static int gcd(int a, int b); //Greatest Common Divider.
    int lcm(int a, int b); //Least Common Multiple.
    static double roundNumber(double num, int decimalPlaces)  //roundin numbers to any number of digits after
        {                                                     //the decimal point.
           double multiplyer = pow(10, decimalPlaces);
           double shifted = num * multiplyer;
           if(fabs(fmod(shifted, 1)) >= 0.5)
              shifted = (shifted>0) ? ceil(shifted) : floor(shifted);   //based on the sign of the number
           else                                                         // we decide to floor or ceil.
              shifted = (shifted>0) ? floor(shifted) : ceil(shifted);
           return shifted/multiplyer;
        }
    static double toDouble(Fraction frac){
        return roundNumber((1.0*frac.nom)/frac.denom, 3);
    }
    static Fraction toFraction(double dbl)
    {
        static int MAX_DIGITS = 3;
        
        int numinator =round(dbl * pow(10, MAX_DIGITS));
        int dominator = pow(10, MAX_DIGITS);
        int commonDivsor = Fraction::gcd(numinator, dominator);
        numinator /= commonDivsor;
        dominator /= commonDivsor;
        return Fraction(numinator, dominator);
    }
    /*Overloaded Arithmetic Aperators:*/

    //addition
        Fraction operator+(const Fraction&);        
        double operator+(const double);
        //Fraction operator+(const double);                
        friend double operator+(double dbl,  Fraction& frac)
        {
            return roundNumber(((frac.nom*1.0)/frac.denom)+dbl, 3);  //*1.0 for casting to double          
        }
        
        //subtraction
        Fraction operator-(const Fraction&);        
        double operator-(const double);
        friend double operator-(double dbl, const Fraction& frac) {
            return roundNumber(dbl-((frac.nom*1.0)/frac.denom), 3);  //*1.0 for casting to double          
        }
        
        //multiplication
        Fraction operator*(const Fraction&);
        friend double operator*( double d, const Fraction&);
        //Fraction operator*(const float);
        double operator*(const double);
        
        //devision
        Fraction operator/(const Fraction&);
        //Fraction operator/(const float);
        double operator/(const double);
    
        
        bool operator==(Fraction& frac1) const;
        bool operator==(double dbl) const;
        
        
        // (>,<,>=,<=)
        bool operator>(const Fraction& frac) const;
        friend bool operator>(const double dbl, const Fraction& frac);
        friend bool operator>(const Fraction& frac,  double dbl);
        bool operator>(double dbl)
        {
            return *this*1.0 > dbl;
        }

               
        friend bool operator<(const double dbl, const Fraction& frac);
        friend bool operator<(const Fraction& frac, const double dbl);
        bool operator<(const Fraction& frac) const;

        bool operator>=(const Fraction& frac) const;        
        bool operator>=(const double dbl);

        bool operator<=(const Fraction& frac);
        bool operator<=(const double dbl);

        Fraction& operator++();           //pre increment
        const Fraction operator++(int f); //post increment
        Fraction& operator--();           //pre decrement
        const Fraction operator--(int f); //post decrement
       

   
    
    friend ostream& operator<< (ostream& ost, Fraction fr);
    friend istream& operator>> (istream& is, Fraction& fr);
}; 
} 

#endif