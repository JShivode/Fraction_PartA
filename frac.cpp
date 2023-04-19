#include<iostream>
#include "sources/Fraction.hpp"
using namespace ariel;
using namespace std;
int main()
{
    Fraction fr1 = Fraction(1, 2);
    Fraction fr2 = Fraction(1, 4);
    Fraction fr3 = Fraction(2, 24);


    cout<<fr1 << "*" << fr2 << "=" << fr1*fr2 <<endl;
    cout<<fr1 << "+" << fr2 << "=" << fr1+fr2 <<endl;    
    cout<<"1.2234+1/2="<<1.2234 + fr1 <<endl;
    cout<<"1.2234-1/2="<<1.2234 - fr1 <<endl;

    cout<<"1/2 + 1.2234="<<fr1 + 1.2234 <<endl;
    cout<<"1/2 - 1.2234="<<fr1 - 1.2234 <<endl;
    cout<<"1/2 ++ = "<<fr1 ++ <<endl;
    cout<<"++ (1/2 ++) = "<< ++ fr1  <<endl; //note this is after first addition.
    cout<<(fr1 >= fr2)<<endl;
    cout<<"0.25 = "<<Fraction::toFraction(0.25)<<endl;
    cout<<"2/3-1/3="<<Fraction(2, 3)- Fraction(1, 3)<<endl;
    Fraction tmp;
    cin>> tmp;
    cout << "You enterd: "<<tmp<<endl;
}
// clang++ frac.cpp sources/Fraction.cpp -o frac && ./frac < input.txt
// ./frac