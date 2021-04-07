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
    return p.GetDisabilityType()->GetConcessionFactor(b);
}

LadiesConcession::LadiesConcession(){}
LadiesConcession::~LadiesConcession(){}

double LadiesConcession::sConcessioFactor = 0;

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