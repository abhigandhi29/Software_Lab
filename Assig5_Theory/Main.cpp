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

int main(){
    Passenger p1("Abhishek","1234",Gender::Male::Type(),Date(29,01,2001),"232134");
    Booking *b1 = dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station("Mumbai"), Station("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1));
    cout<<b1->GetFair()<<endl;
    Passenger p2("aaaa","sfas",Gender::Male::Type(),Date(11,04,1996),"1234",&Divyaang::Blind::Type(),"ef");
    Booking *b2 = dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station("Mumbai"), Station("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p2));
    cout<<b2->GetFair()<<endl;
}