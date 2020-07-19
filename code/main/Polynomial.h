// A Polynomial Class
#include <iostream>
using namespace std;
class Polynomial
{
//define private member functions
private:
   int coef[100];  // array of coefficients
	//int *coef;
   // coef[0] would hold all coefficients of x^0
   // coef[1] would hold all x^1
   // coef[n] = x^n ...
   int deg;        // degree of polynomial (0 for the zero polynomial)
//define public member functions
public:
   Polynomial::Polynomial() //default constructor
   {
      for ( int i = 0; i < 100; i++ ) coef[i] = 0;
   }

 void set ( int a , int b ) //setter function
   {
      //coef = new Polynomial[b+1];
      coef[b] = a;
      deg = degree();
   }
 // Return the degree of this polynomial,
 // i.e., the highest exponential order 
 int degree()
   {
      int d = 0;
      for(int i =99;i>=0;i--){
		  if(coef[i]!=0){
			  d=i;
			  break;
		  }
	  }
      return d;
   } 

   friend ostream & operator <<(ostream &os, Polynomial &s)
   {   os<<"(";
	   for ( int i = 99; i >= 0; i-- ) {
		   if ( s.coef[i] != 0 ) {
            if(s.coef[i]>0) os<<"+";
            os << s.coef[i] << "x^" << i << " ";
         }
      }
	   os<<")";
	  return os;
   }

// use Horner's method to compute and return the polynomial evaluated at x
// https://www.youtube.com/watch?v=RGrmEWj38bs
// return the polynomial evaluation with value x,
// i.e., if c(x) = 2x^2 + 3, then c(2)= 11
// this is the operator overloading format function.
int operator()(int x) {
	Polynomial a = *this;
	int p=0;
    for ( int i = a.degree(); i >= 0; i-- ){
		p+=a.coef[i];
		if(i!=0) p=p*x;
	  }
    return p;
   }

// differentiate this polynomial and return it
Polynomial differentiate()
   {
	  Polynomial a = *this;
      if ( a.degree() == 0 )  {
         Polynomial t;
         t.set ( 0, 0 );
         return t;
      }
      Polynomial deriv;// = new Polynomial ( 0, deg - 1 );
      //  Do it by yourself
	  deriv.deg = degree() - 1;
	  for(int i=0;i<=a.degree();i++){
		  deriv.set(coef[i+1]*(i+1),i);
	  }
      return deriv;
   }
 // polynomial addition
Polynomial &operator+(Polynomial &b) 
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] += b.coef[i];
      c.deg = c.degree();
      return c;
   }
  // polynomial subtraction
Polynomial &operator-(Polynomial &b)  
   {
	  Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] -= b.coef[i];
      return c;
   }
   
   Polynomial &operator*(Polynomial &b)  // polynomial multiplication
   {
	  Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i =a.deg;i>=0;i-- ){
		  for(int j =b.deg;j>=0;j--){
			  c.coef[i+j]+=a.coef[i]*b.coef[j];
		  }
	  }
      return c;
   }

   
};