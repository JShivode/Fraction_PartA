#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("Testing the constructor"){  //Should through custom division by zero exception.
  Fraction fr1, fr2;     
  CHECK_THROWS(fr1 = Fraction(4, 0));
  CHECK_NOTHROW(fr2 = Fraction(0, 4));
  CHECK_EQ(Fraction(0,1), 0.0);
  CHECK_NOTHROW(fr1 = Fraction(4, 2));
}

TEST_CASE("Testing the + (addition) operator"){
  Fraction fr1 = Fraction(4, 6);
  Fraction fr2 = Fraction(5, 10);
  CHECK_EQ(1.167, fr1+fr2);      //checks addition, simplifying and rounding.
}

TEST_CASE("Testing the - (subtraction) operator"){
  Fraction fr1 = Fraction(4, 6);
  Fraction fr2 = Fraction(-5, 10);
  Fraction fr3 = Fraction(3, 9);
  Fraction fr4 = Fraction(1, 3);
  CHECK_EQ((fr1 - fr3) == fr4, 1); // -*- == +
  CHECK_EQ(0.333 == fr4, 1);
  CHECK_LT(fr4-fr1, fr1-fr4);
}

TEST_CASE("Testing the * (multiplication) operator"){
  CHECK_EQ(Fraction(0, 1) * Fraction(2, 3), 0.0);
  CHECK_EQ(Fraction(1, 2) * Fraction(2, 1), 1.0);
  CHECK_EQ(Fraction(1, 2) * Fraction(2, 1) * Fraction(3, 4) * Fraction(4, 3) , 1.0);
}

TEST_CASE("Testing the / (division) operator"){
  CHECK_EQ(Fraction(0, 1) / Fraction(2, 3) == 0.0, 1);
  CHECK_THROWS(Fraction(2, 1) / Fraction(0, 3));
  Fraction frac1 = Fraction(2, 3) / Fraction(1, 5);
  Fraction frac2 = Fraction(2, 3) * Fraction(5, 1);
  CHECK_EQ(frac1.operator==(frac2), 1);
  CHECK_GT(Fraction(1, 2) / 0.5, 1.0*(Fraction(1, 2) / Fraction(10, 5)));
}

TEST_CASE("Testing comparison operators (>, <, >=, <=, ==)"){
    Fraction fr1 = Fraction(3, 7);
    Fraction fr2 = Fraction(3, 16);
    bool tmp;
  CHECK_FALSE( fr2 > fr1);
  CHECK_NOTHROW(tmp = fr2 <= fr1);
  CHECK_EQ(Fraction(1, 2) >= Fraction(1, 3), fr1 >= fr1);
}

TEST_CASE("Testing I/O operators"){
  CHECK_THROWS(cout<< Fraction(-5, 0));
  //CHECK_NOTHROW(cout<<Fraction(3, 4));
  Fraction fr1;
  //cout<<"Please enter a fraction: (one half please..1/2)";
  //cin>> fr1;
  fr1=Fraction(1, 2);
  CHECK_EQ(fr1 == Fraction(1,2), 1);
}

TEST_CASE("Randomize numbers to check Fraction functions"){
    int x = rand() % 100 + 1;  //1-100
    int y = rand() % 30 +200;  //200-260    
    Fraction fr1 = Fraction(x, y);
    Fraction fr2 = Fraction(y, x);
    Fraction frac1 = fr1/fr2;
    Fraction frac2 = fr1*fr2;
    CHECK_EQ(frac2 == Fraction(1, 1), 1);     
    CHECK_FALSE((fr1.operator == (frac1)));
}

TEST_CASE("Division by zero"){
   CHECK_THROWS(Fraction(1, 0));
   CHECK_THROWS(Fraction(1, 2) / 0);
}

TEST_CASE("Checking if the = operator creates a new object"){
   Fraction temp =Fraction(3, 7);
   Fraction fr1 = temp;
   CHECK_EQ(fr1.operator == (temp), 1);//here
   CHECK_NOTHROW(Fraction(Fraction(2, 5)));
}

//////////////////////

TEST_CASE("Constructor test"){
    CHECK_THROWS(Fraction(1,0)); 
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,0));
    
    
}
