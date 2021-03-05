#include<iostream>
#include "Date.h"
using namespace std;

#ifndef _PASSENGER_H
#define _PASSENGER_H

class Passenger{
    private:
        const string name_,aadhar_,gender_,category_,number_;
        const Date dob_; 
    public:
        Passenger(string name, string aadhar, string gender, string category, Date dob, string number);
        ~Passenger();
        friend ostream &operator<<(ostream &, const Passenger &);
};

#endif