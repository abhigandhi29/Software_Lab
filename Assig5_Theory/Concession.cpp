#include "Concession.h"

Concession::Concession(){}
Concession::~Concession(){}

DivyaangConcession::DivyaangConcession(){}
DivyaangConcession::~DivyaangConcession(){}

const DivyaangConcession &DivyaangConcession::Type(){
    static const DivyaangConcession temp;
    return temp;
}

double DivyaangConcession::GetConcessionFactor(Passenger &p,BookingClasses &b) const {
    Divyaang *d = p.GetDisabilityType();
    return b.GetDivyaangConcession(*d);
    //return 1;
}

LadiesConcession::LadiesConcession(){}
LadiesConcession::~LadiesConcession(){}

const LadiesConcession &LadiesConcession::Type(){
    static const LadiesConcession temp;
    return temp;
}

double LadiesConcession::GetConcessionFactor(Passenger &p) const{
    return sConcessioFactor;
}

SeniorCitizenConcession::SeniorCitizenConcession(){};
SeniorCitizenConcession::~SeniorCitizenConcession(){};

const SeniorCitizenConcession &SeniorCitizenConcession::Type(){
    static const SeniorCitizenConcession temp;
    return temp;
}

double SeniorCitizenConcession::GetConcessionFactor(Passenger &p) const {
    if(p.ComputeAge()>=p.GetGender().GetConcessionAge()){
        return p.GetGender().GetSeniorCitizenCon();
    }
    return 0;
}

GeneralConcession::GeneralConcession(){}
GeneralConcession::~GeneralConcession(){}