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