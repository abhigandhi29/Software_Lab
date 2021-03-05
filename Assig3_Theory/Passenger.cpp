#include "Passenger.h"

Passenger::Passenger(string name, string aadhar, string gender, string category, Date dob, string number=""):
    name_(name),aadhar_(aadhar),gender_(gender),category_(category),dob_(dob),number_(number){}

Passenger::~Passenger(){}
ostream &operator<<(ostream &out, const Passenger &p){
    out<<"Passenger: "<<p.name_<<endl;
    out<<"Addar: "<<p.aadhar_<<endl;
    out<<"Gender: "<<p.gender_<<endl;
    out<<"DOB: "<<p.dob_;
    out<<"Category: "<<p.category_<<endl;
    if(!p.number_.empty()){
        out<<"Phone Number: "<<p.number_;
       
    }
    return out;
}