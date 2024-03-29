//Abhishek Gandhi
//19CS10031
#include "Passenger.h"
#include<ctime>

Passenger::Passenger(Name name, string aadhar,const Gender &gender, Date dob, string number,const Divyaang *d,string ID):
    name_(name),aadhar_(aadhar),gender_(gender),dob_(dob),number_(number),disabiltyType_(d),disabiltyID_(ID){}

Passenger::~Passenger(){}
ostream &operator<<(ostream &out, const Passenger &p){
    out<<"\tPassenger: "<<p.name_<<endl;
    out<<"\tAadhar: "<<p.aadhar_<<endl;
    out<<"\tGender: "<<p.gender_<<endl;
    out<<"\tPhone Number: "<<p.number_<<endl;
    if(p.disabiltyType_!=NULL)
        out<<"\tDisabilty Type: "<<p.disabiltyType_->GetName()<<endl;
    if(p.disabiltyID_!="")
        out<<"\tDisabilty ID: "<<p.disabiltyID_<<endl;
    out<<"\tDOB: "<<p.dob_;
    
    return out;
}
Passenger::Passenger(const Passenger &p):name_(p.GetName()),aadhar_(p.aadhar_),gender_(p.GetGender()),dob_(p.GetBOD()),number_(p.GetNumber()),disabiltyType_(p.disabiltyType_),disabiltyID_(p.disabiltyID_){
}

int Passenger::ComputeAge() const{
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    if(ltm->tm_mon > dob_.GetMonth())
        return ltm->tm_year+1900 -dob_.GetYear();
    else if(ltm->tm_mon == dob_.GetMonth()){
        if(ltm->tm_mday >= dob_.GetDay())
            return ltm->tm_year+1900 -dob_.GetYear();
    }
    return ltm->tm_year+1900 -dob_.GetYear()-1;
};

Passenger Passenger::GetInstance(string firstName,string middleName,string lastName,string aadhar,const Gender &gender, Date dob, string number,const Divyaang *disabiltyType ,string disabiltyID){
    try{
       Name n = Name::GetInstance(firstName,middleName,lastName);
    } 
    catch(...){
        throw;
    }
    if(aadhar.length()!=12){
        BadPassengerAddhar t;
        throw t;
    }
    else{
        for(auto i : aadhar){
            if(int(i)<48 || int(i)>57){
                BadPassengerAddhar t;
                throw t;
            }
        }
    }
    if(number.length()!=10){
        BadPassengerMobile t;
        throw t;
    }
    else{
        for(auto i : number){
            if(int(i)<48 || int(i)>57){
                BadPassengerMobile t;
                throw t;
            }
        }
    }
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    Date dnow(ltm->tm_mday,ltm->tm_mon,1900+ltm->tm_year);
    if(dob>dnow){
        BadPassengerDate t;
        throw t;
    }
    if(disabiltyType!=NULL){
        if(disabiltyID.length()!=18){
            BadPassengerDisabilityID t;
            throw t;
        }
    }
    Passenger p1(Name::GetInstance(firstName,middleName,lastName),aadhar,gender, dob, number,disabiltyType,disabiltyID);
    return p1;
}