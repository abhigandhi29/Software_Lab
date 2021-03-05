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
    out<<"Booking Class: "<<B.name_<<endl;
    out<<"\t-Is AC: "<<(B.IsAC() ? "Yes" : "No")<<endl;
    out<<"\t-Is Sitting: "<<(B.IsSitting() ? "Yes" : "No")<<endl;
    out<<"\t-Is Luxury: "<<(B.IsLuxury() ? "Yes" : "No")<<endl;
    out<<"\t-Tiers: "<<B.GetNumberOfTires()<<endl;
    out<<"\t-Load Factor: "<<B.LoadFactor()<<endl;
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
const double &Sleeper::sLoadfactor = 1;
const bool &Sleeper::sisLuxury = false; 
const Sleeper &Sleeper::Type(){
    static const Sleeper sSleeper("Sleeper",false);
    return sSleeper;
}

AC3Tire::AC3Tire(const string &name,const bool &isAc):Tire3(name,isAc){
}
AC3Tire::~AC3Tire(){}
const double &AC3Tire::sLoadfactor = 1.75;
const bool &AC3Tire::sisLuxury = false; 
const AC3Tire &AC3Tire::Type(){
    static const AC3Tire sAC3Tire("AC3Tire",true);
    return sAC3Tire;
}

AC2Tire::AC2Tire(const string &name,const bool &isAc):Tire2(name,isAc){
}
AC2Tire::~AC2Tire(){}
const double &AC2Tire::sLoadfactor = 2;
const bool &AC2Tire::sisLuxury = false; 
const AC2Tire &AC2Tire::Type(){
    static const AC2Tire sAC2Tire("AC2Tire",true);
    return sAC2Tire;
}


ACFirstClass::ACFirstClass(const string &name,const bool &isAc):Tire1(name,isAc){
}
ACFirstClass::~ACFirstClass(){}
const double &ACFirstClass::sLoadfactor = 3;
const bool &ACFirstClass::sisLuxury = true; 
const ACFirstClass &ACFirstClass::Type(){
    static const ACFirstClass sACFirstClass("ACFirstClass",true);
    return sACFirstClass;
}


FirstClass::FirstClass(const string &name,const bool &isAc):Tire2(name,isAc){
}
FirstClass::~FirstClass(){}
const double &FirstClass::sLoadfactor = 2;
const bool &FirstClass::sisLuxury = true; 
const FirstClass &FirstClass::Type(){
    static const FirstClass sFirstClass("FirstClass",true);
    return sFirstClass;
}


SecondSitting::SecondSitting(const string &name,const bool &isAc):SittingClass(name,isAc){
}
SecondSitting::~SecondSitting(){}
const double &SecondSitting::sLoadfactor = 0.5;
const bool &SecondSitting::sisLuxury = false; 
const SecondSitting &SecondSitting::Type(){
    static const SecondSitting sSecondSitting("SecondSitting",false);
    return sSecondSitting;
}

ACChairCar::ACChairCar(const string &name,const bool &isAc):SittingClass(name,isAc){
}
ACChairCar::~ACChairCar(){}
const double &ACChairCar::sLoadfactor = 1.25;
const bool &ACChairCar::sisLuxury = false; 
const ACChairCar &ACChairCar::Type(){
    static const ACChairCar sACChairCar("ACChairCar",true);
    return sACChairCar;
}


int main(){
    return 1;
}