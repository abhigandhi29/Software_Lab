#include<iostream>
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "Station.h"
using namespace std;

#ifndef _BOOKING_H
#define _BOOKING_H

class Booking{
    private:
        const Station fromStation_,toStation_;
        const Date data_;
        BookingClasses *bookinClass_;
        bool bookingStatus =  true;
        string bookingMessage_ = "BOOKING SUCCEEDED";
        Passenger *passenger_;
        int fairComputed_,pnr_;

        static double sBaseFairPerKM;
        static double sACSurpass;
        static double sLuxuryTaxPercent;
        static int sPNRNumber;
    public:
        Booking(Station &,Station &, Date &,BookingClasses *,Passenger *);
        Booking();
        void ComputeFair() const;
        friend ostream &operator<<(ostream &, const Booking &);
};

#endif
