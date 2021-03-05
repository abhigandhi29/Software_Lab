#include "Railway.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Passenger.h"
#include "Booking.h"


int main(){
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021),dynamic_cast<BookingClasses *>(ACFirstClass::Type()));
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), dynamic_cast<BookingClasses *>(AC2Tier::Type()));
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), dynamic_cast<BookingClasses *>(FirstClass::Type()));
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), dynamic_cast<BookingClasses *>(AC3Tier::Type()));
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), dynamic_cast<BookingClasses *>(ACChairCar::Type()));
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), dynamic_cast<BookingClasses *>(Sleeper::Type()));
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), dynamic_cast<BookingClasses *>(SecondSitting::Type()));
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), dynamic_cast<BookingClasses *>(SecondSitting::Type()));
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it)<<endl;
    }
}