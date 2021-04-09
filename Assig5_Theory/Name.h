//Abhishek Gandhi
//19CS10031
#include<iostream>
#include "Date.h"
#include "Divyaang.h"
#include "Exception.h"
#include "Gender.h"
using namespace std;

#ifndef _NAME_H
#define _NAME_H

class Name{
    const string firstName_;
    const string middleName_;
    const string lastName_;
    Name(string firstName, string middleName,string lastName);
public:
    string GetName() const;
    Name(const Name &n);
    Name(){}
    ~Name();
    static Name GetInstance(string firstName, string middleName,string lastName);
    friend ostream &operator<<(ostream &, const Name &);
};

#endif