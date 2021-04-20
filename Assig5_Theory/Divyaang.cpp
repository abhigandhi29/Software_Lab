#include "Divyaang.h"

Divyaang::Divyaang(){}
Divyaang::~Divyaang(){}

template<> string const Divyaang::Blind::sName = "Blind";
template<> string const Divyaang::CancerPatients::sName = "CancerPatients";
template<> string const Divyaang::TBPatients::sName = "TBPatients";
template<> string const Divyaang::OrthopaedicallyHandicapped::sName = "Handicapped";

ostream &operator<<(ostream &out, const Divyaang &d){
    out<<"Divyaang Type:"<< d.GetName()<<endl;
    out<<"\t AC2Tier: "<<d.GetConcessionFactorAC2Tire()<<endl;
    out<<"\t AC3Tier: "<< d.GetConcessionFactorAC3Tier()<<endl;
    out<<"\t ACFirstClass: "<<d.GetConcessionFactorACFirstClass()<<endl;
    out<<"\t FirstClass: "<<d.GetConcessionFactorFirstClass()<< endl;
    out<<"\t Sleeper: "<<d.GetConcessionFactorSleeper()<< endl;
    out<<"\t SecondSitting: "<<d.GetConcessionFactorSecondSitting()<< endl;
    out<<"\t ACChairCar: "<<d.GetConcessionFactorACChairCar() <<endl;
    out<<"\t ExecutiveChairCar: "<<d.GetConcessionFactorExecutiveChairCar();
    return out;
}