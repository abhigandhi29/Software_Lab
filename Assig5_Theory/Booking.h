//Abhishek Gandhi
//19CS10031
#include<iostream>
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "Station.h"
#include<vector>
#include "Concession.h"
using namespace std;

#ifndef _BOOKING_H
#define _BOOKING_H

template<typename T>
class BookingTypes;

class Booking{
    private:
        struct ACFirstClassType{};
        struct ExecuticeChairCarType{};
        struct AC2TireType{};
        struct SleeperType{};
        struct SecondSittingType{};
        struct FirstClassType{};
        struct AC3TireType{};
        struct ACChairCarType{};
        Station fromStation_,toStation_;
        Date data_;
        BookingClasses *bookinClass_;
        Concession category_;
        bool bookingStatus_ =  true;
        string bookingMessage_ = "BOOKING SUCCEEDED";
        Passenger passenger_;
        int fairComputed_,pnr_;

        Booking(const Booking &b);
        static double sBaseFairPerKM;
        //static double sACSurpass;
        //static double sLuxuryTaxPercent;
        static int sPNRNumber;
    protected:
        Booking(Station to,Station from, Date date,BookingClasses *bcl,Passenger p,Concession c);
        ~Booking();
    public:
        void ComputeFair() const;
        static vector<Booking *> sBookings;
        
        inline int GetFair() const{
            return fairComputed_;
        }
        inline int GetPNR() const{
            return pnr_;
        }
        friend ostream &operator<<(ostream &, const Booking &);
        virtual const Booking &MakeReservation(Station to,Station from, Date date,Passenger p);
        typedef BookingTypes<ACFirstClassType> ACFirstClass; 
        typedef BookingTypes<ExecuticeChairCarType> ExecutiveChairCar;
        typedef BookingTypes<AC2TireType> AC2Tier;
        typedef BookingTypes<SleeperType> Sleeper;
        typedef BookingTypes<AC3TireType> AC3Tier;
        typedef BookingTypes<ACChairCarType> ACChairCar;
        typedef BookingTypes<SecondSittingType> SecondSitting;
        typedef BookingTypes<FirstClassType> FirstClass;
};

template<typename T>
class BookingTypes : public  Booking{
    BookingTypes(Station to,Station from, Date date,BookingClasses *bcl,Passenger &p,Concession c):Booking(to,from,date,bcl,p,c){}
    ~BookingTypes(){}
public:
    const BookingTypes<T> &MakeReservation(Station to,Station from, Date date,Passenger p,Concession c);    
};


#endif
