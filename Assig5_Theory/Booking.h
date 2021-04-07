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
        virtual void ComputeFair() const;
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
    BookingTypes(Station to,Station from, Date date,const BookingClasses *bcl,Passenger &p):Booking(to,from,date,bcl,p){}
public:
    ~BookingTypes(){}
void ComputeFair() const;
    static BookingTypes *MakeReservation(Station to,Station from, Date date,const BookingClasses *bcl,Passenger p){
        BookingTypes *b1 = new BookingTypes(to,from, date,bcl,p);
        return b1;
    }
};


#endif
