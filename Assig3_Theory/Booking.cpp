//Abhishek Gandhi
//19CS10031
#include "Booking.h"
#include "Railway.h"

Booking::Booking(Station from,Station to, Date date,BookingClasses *bcl,Passenger *p)
    :fromStation_(from),toStation_(to),data_(date),bookinClass_(bcl),passenger_(p){
        sPNRNumber++;
        pnr_ = sPNRNumber;
        ComputeFair();
        sBookings.push_back(this);
    }
Booking::Booking(const Booking &b):fromStation_(b.fromStation_),toStation_(b.toStation_),data_(b.data_),bookinClass_(b.bookinClass_),passenger_(b.passenger_){
}
vector<Booking *> Booking::sBookings;
Booking::~Booking(){}
double Booking::sBaseFairPerKM = 0.5;
double Booking::sACSurpass = 50;
double Booking::sLuxuryTaxPercent = 25;
int Booking::sPNRNumber = 0;

void Booking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    if(bookinClass_->IsAC()){
        price+=sACSurpass;
    }
    if(bookinClass_->IsLuxury()){
        price = price*(1+sLuxuryTaxPercent/100);
    }
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking *>(this)->fairComputed_ = final_price;
}

ostream &operator<<(ostream &out, const Booking &b){
    out<<b.bookingMessage_<<":"<<endl;
    out<<"PNR Number = "<<b.pnr_<<endl;
    out<<"From Station = "<<b.fromStation_<<endl;
    out<<"To Station = "<<b.toStation_<<endl;
    out<<"Travel Date = "<<b.data_<<endl;
    out<<*(b.bookinClass_)<<endl;
    out<<"fair = "<<b.fairComputed_;
    return out;
}

