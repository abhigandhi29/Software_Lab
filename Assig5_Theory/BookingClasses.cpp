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
    out<<"\t-Is Luxury: "<<(B.IsLuxury() ? "Yes" : "No")<<endl;
    out<<"\t-TatkaalFactor: "<<B.TatkaalLoadFactor()<<endl;
    out<<"\t-MinTatkaalDistance: "<<B.MinTatkaalDistance()<<endl;
    out<<"\t-MinTatkaalCharge: "<<B.MinTatkaalChange()<<endl;
    out<<"\t-MaxTatkaalCharge: "<<B.MaxTatkaalCharge();
    return out;
}
//template<typename T>
//const BookingClassesTypes<T> & BookingClassesTypes<T>::Type(){
//    static const BookingClassesTypes<T> obj;
//    return obj;
//}
template<> const string BookingClasses::AC2Tier::sName = "AC2Tier";
template<> const bool BookingClasses::AC2Tier::sIsAC = true;
template<> const int BookingClasses::AC2Tier::sNumberOfTires = 2;
template<> const bool BookingClasses::AC2Tier::sIsSitting = false;

template<> const string BookingClasses::ACFirstClass::sName = "ACFirstClass";
template<> const bool BookingClasses::ACFirstClass::sIsAC = true;
template<> const int BookingClasses::ACFirstClass::sNumberOfTires = 1;
template<> const bool BookingClasses::ACFirstClass::sIsSitting = false;

template<> const string BookingClasses::ExecutiveChairCar::sName = "ExecutiveChairCar";
template<> const bool BookingClasses::ExecutiveChairCar::sIsAC = true;
template<> const int BookingClasses::ExecutiveChairCar::sNumberOfTires = 0;
template<> const bool BookingClasses::ExecutiveChairCar::sIsSitting = true;

template<> const string BookingClasses::AC3Tier::sName = "AC3Tier";
template<> const bool BookingClasses::AC3Tier::sIsAC = true;
template<> const int BookingClasses::AC3Tier::sNumberOfTires = 3;
template<> const bool BookingClasses::AC3Tier::sIsSitting = false;

template<> const string BookingClasses::Sleeper::sName = "Sleeper";
template<> const bool BookingClasses::Sleeper::sIsAC = false;
template<> const int BookingClasses::Sleeper::sNumberOfTires = 3;
template<> const bool BookingClasses::Sleeper::sIsSitting = false;

template<> const string BookingClasses::SecondSitting::sName = "SecondSitting";
template<> const bool BookingClasses::SecondSitting::sIsAC = false;
template<> const int BookingClasses::SecondSitting::sNumberOfTires = 0;
template<> const bool BookingClasses::SecondSitting::sIsSitting = true;

template<> const string BookingClasses::ACChairCar::sName = "ACChairCar";
template<> const bool BookingClasses::ACChairCar::sIsAC = true;
template<> const int BookingClasses::ACChairCar::sNumberOfTires = 0;
template<> const bool BookingClasses::ACChairCar::sIsSitting = true;

template<> const string BookingClasses::FirstClass::sName = "FirstClass";
template<> const bool BookingClasses::FirstClass::sIsAC = true;
template<> const int BookingClasses::FirstClass::sNumberOfTires = 2;
template<> const bool BookingClasses::FirstClass::sIsSitting = false;

template<> double BookingClasses::FirstClass::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorFirstClass();
}
template<> double BookingClasses::ACFirstClass::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorACFirstClass();
}
template<> double BookingClasses::AC3Tier::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorAC3Tier();
}
template<> double BookingClasses::AC2Tier::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorAC2Tire();
}
template<> double BookingClasses::SecondSitting::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorSecondSitting();
}
template<> double BookingClasses::Sleeper::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorSleeper();
}
template<> double BookingClasses::ExecutiveChairCar::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorExecutiveChairCar();
}
template<> double BookingClasses::ACChairCar::GetDivyaangConcession(Divyaang &d) const{
    return d.GetConcessionFactorACChairCar(); 
}