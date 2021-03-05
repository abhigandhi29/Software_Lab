#include "BookingClasses.h"

BookingClasses::BookingClasses(const string &name,const bool &isAc):name_(name),isAC_(isAc){
}
BookingClasses::BookingClasses(const BookingClasses &B):name_(B.name_),isAC_(B.isAC_){
}
BookingClasses::~BookingClasses(){}
BookingClasses &BookingClasses::operator=(const BookingClasses &a){
    return *this;
}
ostream &operator<<(ostream &out, const BookingClasses &B){
    out<<"Travel Class: "<<B.name_<<endl;
    out<<"\t-Confort: "<<(B.IsAC() ? "AC" : "Non-AC")<<endl;
    out<<"\t-Mode: "<<(B.IsSitting() ? "Sitting" : "Sleeping")<<endl;
    out<<"\t-Is Luxury: "<<(B.IsLuxury() ? "Yes" : "No")<<endl;
    out<<"\t-Tiers: "<<B.GetNumberOfTires()<<endl;
    out<<"\t-Load Factor: "<<B.LoadFactor();
    return out;
}

BerthClass::BerthClass(const string &name,const bool &isAc):BookingClasses(name,isAc){
}
BerthClass::~BerthClass(){}

SittingClass::SittingClass(const string &name,const bool &isAc):BookingClasses(name,isAc){
}
SittingClass::~SittingClass(){}

Tire3::Tire3(const string &name,const bool &isAc):BerthClass(name,isAc){
}
Tire3::~Tire3(){}

Tire2::Tire2(const string &name,const bool &isAc):BerthClass(name,isAc){
}
Tire2::~Tire2(){}

Tire1::Tire1(const string &name,const bool &isAc):BerthClass(name,isAc){
}
Tire1::~Tire1(){}

Sleeper::Sleeper(const string &name,const bool &isAc):Tire3(name,isAc){
}
Sleeper::~Sleeper(){}
double Sleeper::sLoadfactor = 1;
bool Sleeper::sisLuxury = false; 
Sleeper *Sleeper::sSleeper=NULL;
Sleeper *Sleeper::Type(){
    if(!sSleeper)
        sSleeper = new Sleeper("Sleeper",false);
    return sSleeper;
}

AC3Tier::AC3Tier(const string &name,const bool &isAc):Tire3(name,isAc){
}
AC3Tier::~AC3Tier(){}
double AC3Tier::sLoadfactor = 1.75;
bool AC3Tier::sisLuxury = false; 
AC3Tier *AC3Tier::sAC3Tier=NULL;
AC3Tier *AC3Tier::Type(){
    if(!sAC3Tier)
        sAC3Tier = new AC3Tier("AC3Tier",true);
    return sAC3Tier;
}

AC2Tier::AC2Tier(const string &name,const bool &isAc):Tire2(name,isAc){
}
AC2Tier::~AC2Tier(){}
double AC2Tier::sLoadfactor = 2;
bool AC2Tier::sisLuxury = false;
AC2Tier *AC2Tier::sAC2Tier=NULL; 
AC2Tier *AC2Tier::Type(){
    if(!sAC2Tier)
        sAC2Tier = new AC2Tier("AC2Tier",true);
    return sAC2Tier;
}


ACFirstClass::ACFirstClass(const string &name,const bool &isAc):Tire1(name,isAc){
}
ACFirstClass::~ACFirstClass(){}
double ACFirstClass::sLoadfactor = 3;
bool ACFirstClass::sisLuxury = true;
ACFirstClass *ACFirstClass::sACfirstClass=NULL; 
ACFirstClass *ACFirstClass::Type(){
    if(!sACfirstClass){
        sACfirstClass = new ACFirstClass("ACFirstClass",true);
    }
    return sACfirstClass;
}


FirstClass::FirstClass(const string &name,const bool &isAc):Tire2(name,isAc){
}
FirstClass::~FirstClass(){}
double FirstClass::sLoadfactor = 2;
bool FirstClass::sisLuxury = true; 
FirstClass *FirstClass::sFirstClass=NULL;
FirstClass *FirstClass::Type(){
    if(!sFirstClass)
        sFirstClass = new FirstClass("FirstClass",true);
    return sFirstClass;
}


SecondSitting::SecondSitting(const string &name,const bool &isAc):SittingClass(name,isAc){
}
SecondSitting::~SecondSitting(){}
double SecondSitting::sLoadfactor = 0.5;
bool SecondSitting::sisLuxury = false;
SecondSitting *SecondSitting::sSecondSitting=NULL; 
SecondSitting *SecondSitting::Type(){
    if(!sSecondSitting)
        sSecondSitting = new SecondSitting("SecondSitting",false);
    return sSecondSitting;
}

ACChairCar::ACChairCar(const string &name,const bool &isAc):SittingClass(name,isAc){
}
ACChairCar::~ACChairCar(){}
double ACChairCar::sLoadfactor = 1.25;
bool ACChairCar::sisLuxury = false;
ACChairCar *ACChairCar::sACChairCar=NULL; 
ACChairCar *ACChairCar::Type(){
    if(!sACChairCar)
        sACChairCar = new ACChairCar("ACChairCar",true);
    return sACChairCar;
}
