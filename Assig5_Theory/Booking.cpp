//Abhishek Gandhi
//19CS10031
#include "Booking.h"
#include "Railway.h"

Booking::Booking(Station from,Station to, Date date,const BookingClasses *bcl,Passenger p)
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
int Booking::sPNRNumber = 0;

void Booking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    
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
//template<typename T>
//const BookingTypes<T> &BookingTypes<T>::MakeReservation(Station to,Station from, Date date,const BookingClasses *bcl,Passenger p){
//    BookingTypes<T> b1(Station to,Station from, Date date,const BookingClasses *bcl,Passenger p);
//    return b1;
//}

template<> void Booking::GeneralBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::GeneralBooking *>(this)->fairComputed_ = final_price;
}

template<> void Booking::LadiesBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::LadiesBooking *>(this)->fairComputed_ = final_price;
}

template<> void Booking::TatkalBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::TatkalBooking *>(this)->fairComputed_ = final_price;
}

template<> void Booking::PremiumTatkalBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::PremiumTatkalBooking *>(this)->fairComputed_ = final_price;
}

template<> void Booking::DivyaangBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::DivyaangBooking *>(this)->fairComputed_ = final_price;
}

template<> void Booking::SeniorCitizenBooking::ComputeFair() const{
    int dist = Railway::GetDistance(fromStation_,toStation_);
    float price = sBaseFairPerKM*dist;
    price = price*(bookinClass_->LoadFactor());
    int final_price = static_cast<int>(price+0.5);
    const_cast<Booking::SeniorCitizenBooking *>(this)->fairComputed_ = final_price;
}

