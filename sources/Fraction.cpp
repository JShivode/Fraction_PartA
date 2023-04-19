#include "Fraction.hpp"
#include <iostream>
#include <numeric>
#include<cmath>
using namespace std;
using namespace ariel;

    //Constructors:
    Fraction::Fraction(){
        nom = 0;
        denom =1;
    };
    Fraction::Fraction(int new_n, int new_d){        
        if(new_d == 0)
           throw std::invalid_argument("Denominator cannot be zero.");
        nom = new_n;
        denom = new_d;
        simplify();
    };

    int const Fraction::getNom(){ return nom;}
    int const Fraction::getDenom(){ return denom;}
    void Fraction::simplify()
    {
       int value = gcd(nom, denom);
       nom /= value;
       denom /= value;
    }

        

    int Fraction::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
    }

    int Fraction::lcm(int a, int b) {
    return (a * b) / gcd(a, b);
    }
    /*Overloaded Arithmetic Aperators:*/

    //addition
    Fraction Fraction::operator+(const Fraction& fr)
        {
            int common_denom = lcm(fr.denom, denom);  
            
            Fraction result = Fraction(fr.nom * (common_denom / fr.denom)+
                                          nom * (common_denom /    denom), common_denom);
            return result;            
        }
        
    double Fraction::operator+(const double dbl)
        {
           return roundNumber(((nom*1.0)/denom)+dbl, 3);
        }

    // Fraction Fraction::operator+(const double dbl)
    //     {
    //        return Fraction::toFraction(roundNumber(((nom*1.0)/denom)+dbl, 3));
    //     }
    
        
        //subtraction
    Fraction Fraction::operator-(const Fraction& frac)
        {
        int common_denom = lcm(frac.denom, denom);  
            
            Fraction result = Fraction(nom * (common_denom / denom)-
                                          frac.nom * (common_denom /    frac.denom), common_denom);
            return result;            
        }
      
        double Fraction::operator-(const double dbl)
        {
           return roundNumber(((nom*1.0)/denom)-dbl, 3);
        }
        
        
        //multiplication
        Fraction Fraction::operator*(const Fraction& fr)
        {
          Fraction result = Fraction(nom*fr.nom, denom*fr.denom);
          result.simplify();
          return result;
        }
    double ariel::operator*( double d, const Fraction& frac)
    {
        return  Fraction::roundNumber(Fraction::toDouble(frac)*d, 3);
    }
        //Fraction Fraction::operator*(const float f){return Fraction(1,1);};
        double Fraction::operator*(const double dbl)
    {
        return roundNumber(toDouble(Fraction(nom, denom))*dbl, 3);
    }
        
        //devision
        Fraction Fraction::operator/(const Fraction& frac)
        {
            return Fraction(nom, denom)*Fraction(frac.denom, frac.nom);
        }
        //Fraction Fraction::operator/(const float f){return Fraction(1,1);};
        double Fraction::operator/(const double dbl)
        {
            if (dbl == 0)
                throw std::invalid_argument("Division by zero!");

            return roundNumber(toDouble(Fraction(nom, denom))/dbl, 3);
        }
    
        

         bool Fraction::operator==(Fraction& frac) const
        {           
            return nom == frac.getNom() && denom == frac.getDenom();
        }
        

        bool Fraction::operator==(double dbl) const
        {
          return Fraction::toDouble(*this) == Fraction::roundNumber(dbl, 3) ;
        }
        
        // (>,<,>=,<=)
        
        bool Fraction::operator>(const Fraction& frac) const
        {
            return Fraction::toDouble(*this) > Fraction::toDouble(frac);
        }
        bool operator>(const double dbl, const Fraction& frac){
            return Fraction::toDouble(frac) < Fraction::roundNumber(dbl, 3);
        }
        bool operator>(const Fraction& frac, double dbl)
        {
            return Fraction::toDouble(frac) > Fraction::roundNumber(dbl, 3);
        }
         

        bool operator<(const Fraction& frac1, const Fraction& frac2){
            return Fraction::toDouble(frac1) < Fraction::toDouble(frac2);
        }
        bool operator<(const double dbl, const Fraction& frac)
        {
            return Fraction::toDouble(frac) > Fraction::roundNumber(dbl, 3);
        }
       
       bool Fraction::operator<(const Fraction& frac) const
       {
            return Fraction::toDouble(*this) < Fraction::toDouble(frac);
       }


        bool Fraction::operator>=(const Fraction& frac) const
        {
            return toDouble(Fraction(nom, denom))>= toDouble(frac);
        }        
        bool Fraction::operator>=(const double dbl)
        {
            return Fraction::toDouble(Fraction(nom, denom)) >= dbl;
        }

        bool Fraction::operator<=(const Fraction& frac)
        {
            return toDouble(Fraction(nom, denom))<= toDouble(frac);
        }        
        bool Fraction::operator<=(const double dbl)
        {
            return Fraction::toDouble(Fraction(nom, denom)) <= Fraction::roundNumber(dbl, 3);
        }

        Fraction& Fraction::operator++() //pre
        {
            nom += denom;
            return *this;
        }  
        const Fraction Fraction::operator++(int f)  //post
        {
            Fraction* prev = this;
            nom += denom;
            return *prev;
        }
        Fraction& Fraction::operator--(){return *this;}
        const Fraction Fraction::operator--(int f)
        {return Fraction(1,1);}          
    
       ostream& ariel::operator<< (ostream& ost, Fraction fr){            
            ost<< std::to_string(fr.getNom()) + "/" +std::to_string(fr.getDenom());
            return ost;
       };
      istream& ariel::operator>> (istream& ist, Fraction& frac){
           char slash; // To read the slash character '/' from input
           int nom, denom;
           ist >> nom >> slash >> denom;
           frac = Fraction(nom, denom);
           return ist;
      };


        



        // bool operator==( const Fraction& frac_a, Fraction& frac_b)
        // {
        //     Fraction frac1 = Fraction(frac_a);
        //     Fraction frac2 = Fraction(frac_b);
        //     return frac1.getNom() == frac2.getNom() && frac1.getDenom() == frac2.getDenom();
        // }

        //bool Fraction::operator==(const float f){return 0;};
        // bool operator==(const Fraction& frac, const double dbl)
        // {
        //     double doubled = Fraction::toDouble(frac);
        //     return doubled == Fraction::roundNumber(dbl, 3);
        // }


         // bool operator<(const Fraction& frac, const double dbl)
        // {
        //     return Fraction::toDouble(frac) < Fraction::roundNumber(dbl, 3);
        // }