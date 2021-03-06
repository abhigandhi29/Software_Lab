#include<iostream>
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "Station.h"
#include<vector>
using namespace std;

#ifndef _BOOKING_H
#define _BOOKING_H

class Booking{
    private:
        Station fromStation_,toStation_;
        Date data_;
        BookingClasses *bookinClass_;
        bool bookingStatus =  true;
        string bookingMessage_ = "BOOKING SUCCEEDED";
        Passenger *passenger_;
        int fairComputed_,pnr_;

        Booking(const Booking &b);
        static double sBaseFairPerKM;
        static double sACSurpass;
        static double sLuxuryTaxPercent;
        static int sPNRNumber;
    public:
        static vector<Booking *> sBookings;
        Booking(Station to,Station from, Date date,BookingClasses *bcl,Passenger *p = NULL);
        ~Booking();
        void ComputeFair() const;
        inline int GetFair() const{
            return fairComputed_;
        }
        inline int GetPNR() const{
            return pnr_;
        }
        friend ostream &operator<<(ostream &, const Booking &);
};

#endif
