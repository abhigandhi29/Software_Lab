//Abhishek Gandhi
//19CS10031
#include "Passenger.h"

Passenger::Passenger(string name, string aadhar, string gender, Date dob, string number,Divyaang *d,string ID):
    name_(name),aadhar_(aadhar),gender_(gender),dob_(dob),number_(number),disabiltyType_(d),disabiltyID_(ID){}

Passenger::~Passenger(){}
ostream &operator<<(ostream &out, const Passenger &p){
    out<<"Passenger: "<<p.name_<<endl;
    out<<"Aadhar: "<<p.aadhar_<<endl;
    out<<"Gender: "<<p.gender_<<endl;
    out<<"DOB: "<<p.dob_;

    if(!p.number_.empty()){
        out<<endl<<"Phone Number: "<<p.number_;
    }
    return out;
}
Passenger::Passenger(const Passenger &p):name_(p.GetName()),aadhar_(p.aadhar_),gender_(p.GetGender()),dob_(p.GetBOD()),number_(p.GetNumber()),disabiltyType_(p.disabiltyType_),disabiltyID_(p.disabiltyID_){
}