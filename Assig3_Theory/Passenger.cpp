#include "Passenger.h"

Passenger::Passenger(string name, string aadhar, string gender, Date dob, string number):
    name_(name),aadhar_(aadhar),gender_(gender),dob_(dob),number_(number){}

Passenger::~Passenger(){}
ostream &operator<<(ostream &out, const Passenger &p){
    out<<"Passenger: "<<p.name_<<endl;
    out<<"Aadhar: "<<p.aadhar_<<endl;
    out<<"Gender: "<<p.gender_<<endl;
    out<<"DOB: "<<p.dob_<<endl;;
    out<<"Category: "<<p.GetCategory();
    if(!p.number_.empty()){
        out<<endl<<"Phone Number: "<<p.number_;
       
    }
    return out;
}
Passenger::Passenger(const Passenger &p):name_(p.GetName()),aadhar_(p.aadhar_),gender_(p.GetGender()),dob_(p.GetBOD()),number_(p.GetNumber()){
}
General::General(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
General::~General(){}
const string General::sCategory = "General";

Ladies::Ladies(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
Ladies::~Ladies(){}
const string Ladies::sCategory = "Ladies";

Senior_Citizen::Senior_Citizen(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
Senior_Citizen::~Senior_Citizen(){}
const string Senior_Citizen::sCategory = "Senior Citizen";

Divyaang::Divyaang(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
Divyaang::~Divyaang(){}
const string Divyaang::sCategory = "Divyaang";

Tatkal::Tatkal(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
Tatkal::~Tatkal(){}
const string Tatkal::sCategory = "Tatkal";

Premium_Tatkal::Premium_Tatkal(string name, string aadhar, string gender, Date dob, string number):Passenger(name,aadhar,gender,dob,number){
}
Premium_Tatkal::~Premium_Tatkal(){}
const string Premium_Tatkal::sCategory = "Premium Tatkal";

