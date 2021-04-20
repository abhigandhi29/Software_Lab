//Abhishek Gandhi
//19CS10031
#include<iostream>
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Exception.h"
#include<vector>
#include <algorithm>
#include "Concession.h"
#include "Railway.h"
using namespace std;

#ifndef _BOOKING_H
#define _BOOKING_H

template<typename T>
class BookingTypes;

class Booking{
    private:
        struct GeneralBookingType{};
        struct LadiesBookingType{};
        struct SeniorCitizenBOokingType{};
        struct TatkalBookingType{};
        struct PremiumTatkalBookingType{};
        struct DivyaangBookingType{};
        struct SeniorCitizenBookingType{};      
    protected:
        
        static double sBaseFairPerKM;
        static int sPNRNumber;
        Station fromStation_,toStation_;
        Date data_;
        const BookingClasses *bookinClass_;
        //Concession category_;
        bool bookingStatus_ =  true;
        string bookingMessage_ = "BOOKING SUCCEEDED";
        Passenger passenger_;
        int fairComputed_,pnr_;
        Booking(Station to,Station from, Date date,const BookingClasses *bcl,Passenger p);
    public:
        Booking(const Booking &b);
        virtual ~Booking();
        virtual void ComputeFair() const = 0;
        static vector<Booking *> sBookings;
        
        inline int GetFair() const{
            return fairComputed_;
        }
        inline int GetPNR() const{
            return pnr_;
        }
        friend ostream &operator<<(ostream &, const Booking &);
        const Booking &MakeReservation(Station to,Station from, Date date,Passenger p);
        typedef BookingTypes<GeneralBookingType> GeneralBooking;
        typedef BookingTypes<LadiesBookingType> LadiesBooking;
        typedef BookingTypes<TatkalBookingType> TatkalBooking;
        typedef BookingTypes<PremiumTatkalBookingType> PremiumTatkalBooking;
        typedef BookingTypes<DivyaangBookingType> DivyaangBooking;
        typedef BookingTypes<SeniorCitizenBookingType> SeniorCitizenBooking;
};

template<typename T>
class BookingTypes : public  Booking{
    BookingTypes(Station to,Station from, Date date,const BookingClasses *bcl,Passenger &p):Booking(to,from,date,bcl,p){
        ComputeFair();
    }
public:
    ~BookingTypes(){}
    void ComputeFair() const;
    static bool CheckValidity(Passenger &p);
    static BookingTypes *MakeReservation(Station to,Station from, Date date,const BookingClasses *bcl,Passenger p){
        if(find(Railway::sStations.begin(),Railway::sStations.end(),to)==Railway::sStations.end() ||
            find(Railway::sStations.begin(),Railway::sStations.end(),from)==Railway::sStations.end()){
            BadBookingStation t;
            throw t;
            }
        time_t now = time(0);
        tm *ltm = gmtime(&now);
        Date dnow(ltm->tm_mday,ltm->tm_mon,ltm->tm_year+1900);
        if(!(date>dnow)){
            BadBookingReservation t;
            throw t;
        }
        Date afterYear(ltm->tm_mday,ltm->tm_mon,ltm->tm_year+1+1900);
        if(date>afterYear){
            BadBookingReservation t;
            throw t;
        }
        if(!CheckValidity(p)){
            BadBookingCategory t;
            throw t;
        }
        BookingTypes *b1 = new BookingTypes(to,from, date,bcl,p);
        return b1;
    }
};


#endif
