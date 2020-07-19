#include "Polynomial.h"

int main()
{
   Polynomial a, b, c, d;
   a.set ( 7, 4 ); //7x^4
   a.set ( 1, 2 ); //x^2
   b.set ( 6, 3 ); //6x^3
   b.set ( -3, 2 ); //-3x^2
   c = a-b;      // (7x^4 + x^2) - (6x^3 - 3x^2) operator overloading of "-"
   cout <<a << " - " << b << " = " << c << endl;    // print out the c polynomial
 
   c = a + b; 
   cout << endl << a << " + " << b << " = " << c << endl;    // operator overloading of "+"

   c = a * b; // (7x^4 + x^2) * (6x^3 - 3x^2), operator overloading of "*"
   cout << endl << a << " * " << b << " = " << c << endl ;  //  operator overloading for output polynomial
   
   d = c.differentiate().differentiate(); cout << "\n\ndifferentiate " << c << "two times lead to: "<< endl;
   cout << endl<< d << endl;   // operator overloading <<
   cout << endl<< c(2) << endl; // evaluate the polynomial with x=2 by horner's method
   cin.get();
}





