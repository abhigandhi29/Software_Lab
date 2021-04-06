//Abhishek Gandhi
//19CS10031

#include "BookingClasses.h"

BookingClasses::~BookingClasses(){}
BookingClasses::BookingClasses(){}
BookingClasses::BookingClasses(const BookingClasses &b){}

ostream &operator<<(ostream &out, const BookingClasses &B){
    out<<"Travel Class: "<<B.GetName()<<endl;
    out<<"\t-Load Factor: "<<B.LoadFactor()<<endl;
    out<<"\t-Confort: "<<(B.IsAC() ? "AC" : "Non-AC")<<endl;
    out<<"\t-Mode: "<<(B.IsSitting() ? "Sitting" : "Sleeping")<<endl;
    out<<"\t-Bunks: "<<B.GetNumberOfTires()<<endl;
    out<<"\t-Is Luxury: "<<(B.IsLuxury() ? "Yes" : "No");
    return out;
}
template<typename T>
const BookingClassesTypes<T> & BookingClassesTypes<T>::Type(){
    static const BookingClassesTypes<T> obj;
    return obj;
}
template<> const string BookingClasses::AC2Tier::sName = "AC2Tier";
template<> const bool BookingClasses::AC2Tier::sIsAC = true;
template<> const int BookingClasses::AC2Tier::sNumberOfTires = 2;
template<> bool BookingClasses::AC2Tier::sIsLuxury = false;
template<> double BookingClasses::AC2Tier::sLoadFactor = 4.0;
template<> double BookingClasses::AC2Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC2Tier::sMaxTatkaalCharge = 500;
template<> double BookingClasses::AC2Tier::sMinTatkaalCharge = 400;
template<> double BookingClasses::AC2Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC2Tier::sReservationCharge = 50;

template<> const string BookingClasses::ACFirstClass::sName = "ACFirstClass";
template<> const bool BookingClasses::ACFirstClass::sIsAC = true;
template<> const int BookingClasses::ACFirstClass::sNumberOfTires = 1;
template<> bool BookingClasses::ACFirstClass::sIsLuxury = true;
template<> double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template<> double BookingClasses::ACFirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACFirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ACFirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::ACFirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::ACFirstClass::sReservationCharge = 60;

template<> const string BookingClasses::ExecutiveChairCar::sName = "ExecutiveChairCar";
template<> const bool BookingClasses::ExecutiveChairCar::sIsAC = true;
template<> const int BookingClasses::ExecutiveChairCar::sNumberOfTires = 0;
template<> bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template<> double BookingClasses::ExecutiveChairCar::sLoadFactor = 5.0;
template<> double BookingClasses::ExecutiveChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ExecutiveChairCar::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalCharge = 400;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ExecutiveChairCar::sReservationCharge = 60;

template<> const string BookingClasses::AC3Tier::sName = "AC3Tier";
template<> const bool BookingClasses::AC3Tier::sIsAC = true;
template<> const int BookingClasses::AC3Tier::sNumberOfTires = 3;
template<> bool BookingClasses::AC3Tier::sIsLuxury = false;
template<> double BookingClasses::AC3Tier::sLoadFactor = 2.5;
template<> double BookingClasses::AC3Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC3Tier::sMaxTatkaalCharge = 400;
template<> double BookingClasses::AC3Tier::sMinTatkaalCharge = 300;
template<> double BookingClasses::AC3Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC3Tier::sReservationCharge = 40;

template<> const string BookingClasses::Sleeper::sName = "Sleeper";
template<> const bool BookingClasses::Sleeper::sIsAC = false;
template<> const int BookingClasses::Sleeper::sNumberOfTires = 3;
template<> bool BookingClasses::Sleeper::sIsLuxury = false;
template<> double BookingClasses::Sleeper::sLoadFactor = 1.0;
template<> double BookingClasses::Sleeper::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::Sleeper::sMaxTatkaalCharge = 200;
template<> double BookingClasses::Sleeper::sMinTatkaalCharge = 100;
template<> double BookingClasses::Sleeper::sMinTatkaalDistance = 500;
template<> double BookingClasses::Sleeper::sReservationCharge = 20;

template<> const string BookingClasses::SecondSitting::sName = "SecondSitting";
template<> const bool BookingClasses::SecondSitting::sIsAC = false;
template<> const int BookingClasses::SecondSitting::sNumberOfTires = 0;
template<> bool BookingClasses::SecondSitting::sIsLuxury = false;
template<> double BookingClasses::SecondSitting::sLoadFactor = 0.6;
template<> double BookingClasses::SecondSitting::sTatkalLoadFactor = 0.1;
template<> double BookingClasses::SecondSitting::sMaxTatkaalCharge = 15;
template<> double BookingClasses::SecondSitting::sMinTatkaalCharge = 10;
template<> double BookingClasses::SecondSitting::sMinTatkaalDistance = 100;
template<> double BookingClasses::SecondSitting::sReservationCharge = 15;

template<> const string BookingClasses::ACChairCar::sName = "ACChairCar";
template<> const bool BookingClasses::ACChairCar::sIsAC = true;
template<> const int BookingClasses::ACChairCar::sNumberOfTires = 0;
template<> bool BookingClasses::ACChairCar::sIsLuxury = false;
template<> double BookingClasses::ACChairCar::sLoadFactor = 2.0;
template<> double BookingClasses::ACChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACChairCar::sMaxTatkaalCharge = 225;
template<> double BookingClasses::ACChairCar::sMinTatkaalCharge = 125;
template<> double BookingClasses::ACChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ACChairCar::sReservationCharge = 40;

template<> const string BookingClasses::FirstClass::sName = "FirstClass";
template<> const bool BookingClasses::FirstClass::sIsAC = true;
template<> const int BookingClasses::FirstClass::sNumberOfTires = 2;
template<> bool BookingClasses::FirstClass::sIsLuxury = true;
template<> double BookingClasses::FirstClass::sLoadFactor = 3.0;
template<> double BookingClasses::FirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::FirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::FirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::FirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::FirstClass::sReservationCharge = 50;

int main(){
    return 1;
}