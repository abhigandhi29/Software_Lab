//Abhishek Gandhi
//19CS10031
#include<iostream>
#include "Date.h"
#include "Divyaang.h"
#include "Exception.h"
#include "Gender.h"
using namespace std;

#ifndef _PASSENGER_H
#define _PASSENGER_H

class Passenger{
    private:
        const string name_,aadhar_,number_,disabiltyID_;
        const Gender &gender_;
        const Divyaang *disabiltyType_;
        const Date dob_;
        
    public:
        Passenger(const Passenger &); 
        Passenger(string name, string aadhar,const Gender &gender, Date dob, string number="",const Divyaang *disabiltyType = NULL,string disabiltyID = "");
        ~Passenger();
        friend ostream &operator<<(ostream &, const Passenger &);
        inline string GetName() const{
            return name_;
        }
        inline const Gender &GetGender() const{
            return gender_;
        }
        inline string GetNumber() const{
            return number_;
        }
        inline Date GetBOD() const{
            return dob_;
        }
        inline Divyaang *GetDisabilityType() const{
            return const_cast<Divyaang *>(disabiltyType_);
        }
        inline string GetDisabilityID() const{
            return disabiltyID_;
        }
        int ComputeAge() const;

};
#endif