/* Fraction.h, includes all function signatures 
   including definitions of a few inline functions declarations, for other function definitions refer Function.cpp

    BY Abhishek Gandhi
    19CS10031
*/
#include <iostream>
using namespace std;

#ifndef Fraction_H
#define Fraction_H

class Fraction {
        
public:
    //Constructors and copy-constructors
    Fraction(int m=1,int n=1);         //Regular Constructor when both numerator and denominator are mentioned.
    Fraction(double d);            //Constructor when a decimal number is to be converted into a fraction.
    Fraction(const Fraction &a);   //Copy Constructor.
    
    //Assignment operator
    Fraction& operator=(const Fraction &f);

    //Destructor- Like constructor mo return value, called at the end of the program by default.
    ~Fraction();

    //Static Constants- Declared as static and are initialised in Fraction.cpp
    static const Fraction sc_fUnity;
    static const Fraction sc_fZero;

    // Unary positive and negative operator
    inline Fraction operator+(){return Fraction(+p,q);}
    inline Fraction operator-(){return Fraction(-p,q);}
    // Unary arithmetic operators- Return type Fraction

    //Prefix  Operators: Return Fraction as a copy of the input fraction before the arithmetic operation
    Fraction operator++();
    Fraction operator--();

    //Postfix Operators: Return Fraction as a copy of the input fraction after the arithmetic operation
    Fraction operator++(int);
    Fraction operator--(int);

    //As the members p and q are declared private, therefore these functions were needed to be able to use these numbers outside the class.
    //Makes sure that nothing is edited in such a way that it might bring an error afterwards and hence makees it easier and more error free to use and edit the members p and q.
    inline int getNum() const {return p;}         //Returns p
    inline int getDenum() const {return q;}       //Returns q
    void setNum(int a);         //To edit p
    void setDenum(int a);       //To edit q

    //I/O operators, defined as friend operators as the private members, p and q were needed for easy implementation.
    // Call by reference is used to make changes directly in the fraction used in cin and cout
    friend ostream & operator << (ostream &out,const Fraction &a); 
    friend istream & operator >> (istream &in,Fraction &a); 

    //Binary Arithmetic Operators, defined as friend functions as the private members, p and q were needed for easy implementation.
    //Const values are used as function parameters to make sure that there are no changes in the input fraction values.
    //Return type is fraction.
    friend Fraction operator+ (const Fraction &a,const Fraction &b);
    friend Fraction operator- (const Fraction &a,const Fraction &b);
    friend Fraction operator* (const Fraction &a,const Fraction &b);
    friend Fraction operator/ (const Fraction &a,const Fraction &b);        //Uses try & catch to throw an error if division by 0 is attempted. Cerr is used to notify the user of the error.
    friend Fraction operator% (const Fraction &a,const Fraction &b);        //% is modelled on the basis of how remainder function would have been used if the fractional input would have been whole numbers.

    //Binary Operator, Due to small defination defied as a Inline
    //return type bool as instructed.
    //Function parameter is taken as constant to make sure no edits are made in the input fractions hence making the program less prone to errors
    inline bool operator==(const Fraction &b){return(p==b.p&&q==b.q);}
    inline bool operator!=(const Fraction &b){return !(p==b.p&&q==b.q);}
    //comparisions have been made after Cross Multiplication so as to not introduce any errors because of division of two int values.
    inline bool operator<(const Fraction &b){return(p*b.q<q*b.p);}
    inline bool operator>(const Fraction &b){return(p*b.q>q*b.p);}
    inline bool operator<=(const Fraction &b){return(p*b.q<=q*b.p);}
    inline bool operator>=(const Fraction &b){return(p*b.q>=q*b.p);}

    //Inversion Operator, Overloaded on the negation operator.
    //Return type fraction as no changes are to be made on the fraction value on which this operator is used, instead a copy is to be returned with the necessary changes
    Fraction operator!();

    //Utility functions
    int precision() const;          //const is used to make be able to access the element prec even though it is declared as static constant.
    static int gcd(int a,int b);    //return Greatest Common Divisor
    static int lcm(int a,int b);    //return Least Common Multiple

private: 
    int p;
    unsigned int q;
    const int preci=10000;
    
};


#endif