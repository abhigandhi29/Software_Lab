#include "BookingClasses.h"
#include "Booking.h"
#include "Railway.h"
#include "Date.h"
#include "Passenger.h"
#include "Gender.h"
#include "Concession.h"
#include "Station.h"
#include "Divyaang.h"
#include "Exception.h"
#include "Name.h"

template<> bool BookingClasses::AC2Tier::sIsLuxury = false;
template<> double BookingClasses::AC2Tier::sLoadFactor = 4.0;
template<> double BookingClasses::AC2Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC2Tier::sMaxTatkaalCharge = 500;
template<> double BookingClasses::AC2Tier::sMinTatkaalCharge = 400;
template<> double BookingClasses::AC2Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC2Tier::sReservationCharge = 50;

template<> bool BookingClasses::ACFirstClass::sIsLuxury = true;
template<> double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template<> double BookingClasses::ACFirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACFirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ACFirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::ACFirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::ACFirstClass::sReservationCharge = 60;

template<> bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template<> double BookingClasses::ExecutiveChairCar::sLoadFactor = 5.0;
template<> double BookingClasses::ExecutiveChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ExecutiveChairCar::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalCharge = 400;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ExecutiveChairCar::sReservationCharge = 60;

template<> bool BookingClasses::AC3Tier::sIsLuxury = false;
template<> double BookingClasses::AC3Tier::sLoadFactor = 2.5;
template<> double BookingClasses::AC3Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC3Tier::sMaxTatkaalCharge = 400;
template<> double BookingClasses::AC3Tier::sMinTatkaalCharge = 300;
template<> double BookingClasses::AC3Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC3Tier::sReservationCharge = 40;

template<> bool BookingClasses::Sleeper::sIsLuxury = false;
template<> double BookingClasses::Sleeper::sLoadFactor = 1.0;
template<> double BookingClasses::Sleeper::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::Sleeper::sMaxTatkaalCharge = 200;
template<> double BookingClasses::Sleeper::sMinTatkaalCharge = 100;
template<> double BookingClasses::Sleeper::sMinTatkaalDistance = 500;
template<> double BookingClasses::Sleeper::sReservationCharge = 20;

template<> bool BookingClasses::SecondSitting::sIsLuxury = false;
template<> double BookingClasses::SecondSitting::sLoadFactor = 0.6;
template<> double BookingClasses::SecondSitting::sTatkalLoadFactor = 0.1;
template<> double BookingClasses::SecondSitting::sMaxTatkaalCharge = 15;
template<> double BookingClasses::SecondSitting::sMinTatkaalCharge = 10;
template<> double BookingClasses::SecondSitting::sMinTatkaalDistance = 100;
template<> double BookingClasses::SecondSitting::sReservationCharge = 15;

template<> bool BookingClasses::ACChairCar::sIsLuxury = false;
template<> double BookingClasses::ACChairCar::sLoadFactor = 2.0;
template<> double BookingClasses::ACChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACChairCar::sMaxTatkaalCharge = 225;
template<> double BookingClasses::ACChairCar::sMinTatkaalCharge = 125;
template<> double BookingClasses::ACChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ACChairCar::sReservationCharge = 40;

template<> bool BookingClasses::FirstClass::sIsLuxury = true;
template<> double BookingClasses::FirstClass::sLoadFactor = 3.0;
template<> double BookingClasses::FirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::FirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::FirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::FirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::FirstClass::sReservationCharge = 50;

double Booking::sBaseFairPerKM = 0.5;

double LadiesConcession::sConcessioFactor = 0;

template<> double Divyaang::Blind::sACFirstClassConcession = 0.5;
template<> double Divyaang::Blind::sFirstClassConcession = 0.75;
template<> double Divyaang::Blind::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::Blind::sAC2TierConcession = 0.5;
template<> double Divyaang::Blind::sAC3TierConcession = 0.75;
template<> double Divyaang::Blind::sACChairCarConcession = 0.75;
template<> double Divyaang::Blind::sSleeperConcession = 0.75;
template<> double Divyaang::Blind::sSecondSittingConcession = 0.75;

template<> double Divyaang::OrthopaedicallyHandicapped::sACFirstClassConcession = 0.5;
template<> double Divyaang::OrthopaedicallyHandicapped::sFirstClassConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sAC2TierConcession = 0.5;
template<> double Divyaang::OrthopaedicallyHandicapped::sAC3TierConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sACChairCarConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sSleeperConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sSecondSittingConcession = 0.75;

template<> double Divyaang::CancerPatients::sACFirstClassConcession = 0.5;
template<> double Divyaang::CancerPatients::sFirstClassConcession = 0.75;
template<> double Divyaang::CancerPatients::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::CancerPatients::sAC2TierConcession = 0.5;
template<> double Divyaang::CancerPatients::sAC3TierConcession = 1.0;
template<> double Divyaang::CancerPatients::sACChairCarConcession = 1.0;
template<> double Divyaang::CancerPatients::sSleeperConcession = 1.0;
template<> double Divyaang::CancerPatients::sSecondSittingConcession = 1.0;

template<> double Divyaang::TBPatients::sACFirstClassConcession = 0;
template<> double Divyaang::TBPatients::sFirstClassConcession = 0.75;
template<> double Divyaang::TBPatients::sExecutiveChairCarConcession = 0;
template<> double Divyaang::TBPatients::sAC2TierConcession = 0;
template<> double Divyaang::TBPatients::sAC3TierConcession = 0;
template<> double Divyaang::TBPatients::sACChairCarConcession = 0;
template<> double Divyaang::TBPatients::sSleeperConcession = 0.75;
template<> double Divyaang::TBPatients::sSecondSittingConcession = 0.75;

template<> double Gender::Male::sSeniorCitizenConsessionFactor =  0.4;
template<> double Gender::Female::sSeniorCitizenConsessionFactor =  0.5;

template<> int Gender::Male::sConcessionAge = 60;
template<> int Gender::Female::sConcessionAge = 58;

vector<Station> Railway::sStations{
    Station("Mumbai"),
    Station("Delhi"),
    Station("Bangalore"),
    Station("Kolkata"),
    Station("Chennai")
};
vector<pair<pair<Station,Station>,int>> Railway::sDistStation{
    {{Station("Mumbai"),Station("Delhi")},1447},
    {{Station("Mumbai"),Station("Bangalore")},981},
    {{Station("Mumbai"),Station("Kolkata")},2014},
    {{Station("Mumbai"),Station("Chennai")},1338},
    {{Station("Bangalore"),Station("Delhi")},2150},
    {{Station("Kolkata"),Station("Delhi")},1472},
    {{Station("Chennai"),Station("Delhi")},2180},
    {{Station("Bangalore"),Station("Kolkata")},1871},
    {{Station("Bangalore"),Station("Chennai")},350},
    {{Station("Kolkata"),Station("Chennai")},1659}
};

int main(){
    try{
        Railway::IndianRailways();
    }
    catch(exception &t){
        cout<<t.what()<<endl;
    }
    try{
        Passenger p1 = Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"1234567890");
        Booking *b1 = dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station("Mumbai"), Station("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1));
        cout<<b1->GetFair()<<endl;
        Passenger p2 = Passenger::GetInstance("someguy","","shit","123456789012",Gender::Male::Type(),Date(11,04,1996),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh");
        Booking *b2 = dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station("Mumbai"), Station("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p2));
        cout<<b2->GetFair()<<endl;
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 1;
}