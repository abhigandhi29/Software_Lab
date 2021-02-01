/* Fraction.cpp, includes all function implementations 
   except a few inline functions as declared in the header file Fraction.h

    BY Abhishek Gandhi
    19CS10031
*/



#include <iostream>
using namespace std;

#include "Fraction.h"

// INITIALISING STATIC CONSTANTS
const Fraction Fraction::sc_fUnity=Fraction();
const Fraction Fraction::sc_fZero=Fraction(0);

//CONSTRUCTORS
//For general initialisation 
Fraction::Fraction(int m,int n){
    if(n<0){
        m*=-1;
        n*=-1;
    }
    p=m;
    q=n;
    if(q==0){
        cout<<"Fraction can't have denominator 0."<<endl;
        exit(1);
    }
    int x=gcd(p,q);
    p/=x;q/=x;
    if(p==0){
        q=1;
    }
}
//Constructor for fractional input
Fraction::Fraction(double d){
    p=(int)(d*preci);
    q=preci;
    int x=gcd(p,q);
    p/=x;q/=x;
    if(p==0){
        q=1;
    }
}
//Copy constructor
Fraction::Fraction(const Fraction &a){
    p=a.p;
    q=a.q;
}

// DESTRUCTOR, Default will work since no array or pointer is defiened
Fraction::~Fraction(){};

//TO EDIT THE PRIVATE CONSTANTS, Normalising the numerator and denominator has also been carried out here.
void Fraction::setNum(int a){
    int x=gcd(q,a);
    p=a/x;
    q/=x;
}
//Check that 0 is not given as denominator has been kept, to ensure error free programming
void Fraction::setDenum(int a){
    if(a==0){
        cout<<"Invalid Operation.\n";
        exit(1);
    }
    int x=gcd(p,a);
    q=a/x;
    p/=x;
}

// COPY ASSIGNMENT OPERATOR
//Return value is a reference as changes made in the input parameter in this function have to be reflected everywhere.
//The fraction that is being copied is taken as a const fraction to ensure that no edits are made on that fraction.
Fraction& Fraction::operator=(const Fraction &f){
    if(this!=&f){
        p=f.getNum();
        q=f.getDenum();
    }
    return *this;
}
// Unary + and - operators are defined as inline functions in Function.hpp

//URINARY ARETHMETIC PREFIX OPERATORS, here *this has been returned as the fraction is to be returned AFTER the arithmetic operation has been performed


Fraction Fraction::operator++(){
    p+=q;
    return *this;
}
Fraction Fraction::operator--(){
    p-=q;
    return *this;
}

//UNARY ARITHMETIC POSTFIX OPERATOR, here a new fraction value is returned as the change is made on the input fraction but it's previous value is to be used first.
Fraction Fraction::operator++(int){
    p+=q;
    return Fraction(p-q,q);
}
Fraction Fraction::operator--(int){
    p-=q;
    return Fraction(p+q,q);
}

// BINARY ARITHMETIC OPERATORS
//New fraction values are returned, and const fractions are taken to make sure that no unwarranted edits are performed with the input fraction values.
Fraction operator+ (const Fraction &a,const Fraction &b){
    return Fraction(a.p*b.q+a.q*b.p,a.q*b.q);
}
Fraction operator- (const Fraction &a,const Fraction &b){
    return Fraction(a.p*b.q-a.q*b.p,a.q*b.q);
}
Fraction operator* (const Fraction &a,const Fraction &b){
    return Fraction(a.p*b.p,a.q*b.q);
}
//Try catch has been used to make sure division by 0 never takes place. Exit(1) is used afterwards.
Fraction operator/ (const Fraction &a,const Fraction &b){
    try{
        if(b.getNum()==0)
        throw(b.getNum());
        else
        {
            return Fraction(a.p*b.q,a.q*b.p);
        }
        
    }
    catch(int bq){
        cerr<<"Invalid Division Operation";
        exit(1);
    }
    
}
Fraction operator% (const Fraction &a,const Fraction &b){
    try{
        if(b.getNum()==0)
        throw(b.getNum());
        else{
            Fraction x((a.getNum()*b.getDenum()),(a.getDenum()*b.getNum()));
            if(x.getDenum()<0){
                x.setNum(a.getNum()*-1);
                x.setDenum(a.getDenum()*-1);
            }
            x.setNum(x.getNum()%x.getDenum());
            if(x.getNum()==0)
            x.setDenum(1);
            return x*b;
        }
    }
    catch(int bq){
        cerr<<"Invalid Remainder Operation";
        exit(1);
    }
    
}

//BINARY RELATIONAL OPERATORS
//If both numbers are 0 then denominator comparision is not needed, hence the return value as mentioned in the function


// SPECIAL OPERATOR (NEGATION)
Fraction Fraction::operator!(){
    try{
        if(p==0)
        throw(p);
        else
        {
            return Fraction(q,p);
        }
        
    }
    catch(int ap){
        cerr<<"Invalid Inversion Operation";
        exit(1);
    }
    
}

// UTILITY FUNCTIONS
int Fraction::precision() const{
    return preci;
}
int Fraction::gcd(int a,int b){
    if(b==0)
    return a;
    return (gcd(b,a%b));
}
int Fraction::lcm(int a,int b){
    return a*b/gcd(a,b);
}

// I/0 OPERATORS
ostream & operator << (ostream &out, const Fraction &a) 
{ 
    out << a.p;
    if(a.q!=1 || a.p==0)
        out << "/" << a.getDenum();
    return out;
}
istream & operator >> (istream &in,Fraction &a) 
{ 
    int n,m;
    cout << "Enter Numerator "; 
    in >> n;
    a.setNum(n); 
    cout << "Enter Denominator "; 
    in >> m;
    a.setDenum(m);
    int x=Fraction::gcd(a.getNum(),a.getDenum());
    a.setNum(a.getNum()/x);
    a.setDenum(a.getDenum()/x);
    if(a.getDenum()<0){
        a.setNum(a.getNum()*(-1));a.setDenum(a.getDenum()*(-1));
    }
    if(a.getNum()==0){
        a.setDenum(1);
    }
    return in; 
} 

