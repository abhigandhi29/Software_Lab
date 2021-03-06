#include "Railway.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Passenger.h"
#include "Booking.h"


void UnitTesting(){
    Station s1 = Station("Mumbai"),s2=Station("Delhi"),s3=Station("Mumbai");
    if(s1.GetName()!="Mumbai" || s2.GetName()!="Delhi" || s3.GetName()!="Mumbai")
        cout<<"Station: Error in name_ string variable value"<<endl;
    if(!(s1==s3))
        cout<<"Station: Error in operator="<<endl;
    Station s4 = Station(s2);
    if(!(s4==s2))
        cout<<"Station: Error in copy operator"<<endl;
    if(s1.GetDistance(s2)!=1447)
        cout<<"Station: Error in GetDistance Function"<<endl;

    const Railway *r1 = Railway::IndianRailways();
    const Railway *r2 = Railway::IndianRailways();
    if(r1 != r2)
        cout<<"Railway: Error IndianRailways function, failed to create a singleton class"<<endl;
    if(r1->GetDistance(s1,s2)!=1447)
        cout<<"Railway: Error in GetDistance function"<<endl;
    
    Date d1 = Date(29,01,2001),d2 = Date(7,03,2021);
    if(d1.getDay()!=29 || d1.getMonth()!=01 || d1.getYear()!=2001)
        cout<<"Date: Error during construction of 29/Jan/2001"<<endl;
    if(d2.getDay()!=7 || d2.getMonth()!=03 || d2.getYear()!=2021)
        cout<<"Date: Error during construction of 7/Mar/2021"<<endl;
    Date d3 = Date(d1);
    if(d3.getDay()!=29 || d3.getMonth()!=01 || d3.getYear()!=2001)
        cout<<"Date: Error in copy constructor"<<endl;
    if(d1==d2 || !(d1==d3))  
        cout<<"Date: Error in comparison"<<endl;
    
    Passenger *p1 = new General("abhishek","123456789065","male",d1,"8888888888");
    Passenger *p2 = new Ladies("Gunjan","098765432123","female",d2);
    Passenger *p3 = new Senior_Citizen("uncle","1354","male",Date(26,12,1999));
    Passenger *p4 = new Divyaang("Tony","674676854","male",Date(4,6,1994),"1234567890");
    Passenger *p5 = new Tatkal("fast","2586435","female",Date(11,04,2006));
    Passenger *p6 = new Premium_Tatkal("prem","4464364636","male",Date(4,1,1991));
    if(p1->GetName()!="abhishek" || p1->GetGender()!="male" || p1->GetNumber()!="8888888888" || p1->GetCategory()!="General" || !(p1->GetBOD()==d1))
        cout<<"Passenger: Error in construction of general"<<endl;
    if(p2->GetName()!="Gunjan" || p2->GetGender()!="female" || p2->GetNumber()!="" || p2->GetCategory()!="Ladies" || !(p2->GetBOD()==d2))
        cout<<"Passenger: Error in construction of ladies"<<endl;
    if(p3->GetName()!="uncle" || p3->GetGender()!="male" || p3->GetNumber()!="" || p3->GetCategory()!="Senior Citizen" || !(p3->GetBOD()==Date(26,12,1999)))
        cout<<"Passenger: Error in construction of Senior Citizen"<<endl;
    if(p4->GetName()!="Tony" || p4->GetGender()!="male" || p4->GetNumber()!="1234567890" || p4->GetCategory()!="Divyaang" || !(p4->GetBOD()==Date(4,6,1994)))
        cout<<"Passenger: Error in construction of Divyaang"<<endl;
    if(p5->GetName()!="fast" || p5->GetGender()!="female" || p5->GetNumber()!="" || p5->GetCategory()!="Tatkal" || !(p5->GetBOD()==Date(11,04,2006)))
        cout<<"Passenger: Error in construction of Tatkal"<<endl;
    if(p6->GetName()!="prem" || p6->GetGender()!="male" || p6->GetNumber()!="" || p6->GetCategory()!="Premium Tatkal" || !(p6->GetBOD()==Date(4,1,1991)))
        cout<<"Passenger: Error in construction of Premium Tatkaal"<<endl;

}

int main(){
    UnitTesting();
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