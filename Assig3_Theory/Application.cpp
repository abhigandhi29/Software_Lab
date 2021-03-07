#include "Railway.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Passenger.h"
#include "Booking.h"


void UnitTesting(){
    cout<<"-----------------Unit Testing For Station Class------------------------"<<endl;
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
    cout<<s1<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    cout<<"-----------------Unit Testing For Railway Class------------------------"<<endl;
    const Railway *r1 = Railway::IndianRailways();
    const Railway *r2 = Railway::IndianRailways();
    if(r1 != r2)
        cout<<"Railway: Error IndianRailways function, failed to create a singleton class"<<endl;
    if(r1->GetDistance(s1,s2)!=1447)
        cout<<"Railway: Error in GetDistance function"<<endl;
    cout<<*r1<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"--------------------Unit Testing For Date Class------------------------"<<endl;
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
    cout<<"d1 = "<<d1<<endl;
    cout<<"d2 = "<<d2<<endl;
    cout<<"d3 = "<<d3<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"-----------------Unit Testing For Passenger Classes--------------------"<<endl;
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
    cout<<"p1 = "<<*p1<<endl;
    cout<<"p2 = "<<*p2<<endl;
    cout<<"p3 = "<<*p3<<endl;
    cout<<"p4 = "<<*p4<<endl;
    cout<<"p5 = "<<*p5<<endl;
    cout<<"p6 = "<<*p6<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"------------Unit Testing For BookingClasses Classes--------------------"<<endl;
    BookingClasses *b11 = Sleeper::Type();
    BookingClasses *b12 = Sleeper::Type();
    BookingClasses *b21 = AC3Tier::Type();
    BookingClasses *b22 = AC3Tier::Type();
    BookingClasses *b31 = AC2Tier::Type();
    BookingClasses *b32 = AC2Tier::Type();
    BookingClasses *b41 = ACFirstClass::Type();
    BookingClasses *b42 = ACFirstClass::Type();
    BookingClasses *b51 = FirstClass::Type();
    BookingClasses *b52 = FirstClass::Type();
    BookingClasses *b61 = SecondSitting::Type();
    BookingClasses *b62 = SecondSitting::Type();
    BookingClasses *b71 = ACChairCar::Type();
    BookingClasses *b72 = ACChairCar::Type();
    if(b11!=b12)
        cout<<"BookingClasses: Not a Singleton, Check Sleeper Type Function"<<endl;
    if(b21!=b22)
        cout<<"BookingClasses: Not a Singleton, Check AC3Tier Type Function"<<endl;
    if(b31!=b32)
        cout<<"BookingClasses: Not a Singleton, Check AC2Tier Type Function"<<endl;
    if(b41!=b42)
        cout<<"BookingClasses: Not a Singleton, Check ACFirstClass Type Function"<<endl;
    if(b51!=b52)
        cout<<"BookingClasses: Not a Singleton, Check FirstClass Type Function"<<endl;
    if(b61!=b62)
        cout<<"BookingClasses: Not a Singleton, Check ACChairCar Type Function"<<endl;
    if(b71!=b72)
        cout<<"BookingClasses: Not a Singleton, Check Sleeper Type Function"<<endl;
    if(b11->GetName()!="Sleeper" || b11->GetNumberOfTires()!=3 || b11->IsAC()!=false || b11->LoadFactor()!=1 || b11->IsSitting()!=false)
        cout<<"BookingClasses: Constructor error in sleeper"<<endl;
    if(b21->GetName()!="AC3Tier" || b21->GetNumberOfTires()!=3 || b21->IsAC()!=true || b21->LoadFactor()!=1.75 || b21->IsSitting()!=false)
        cout<<"BookingClasses: Constructor error in AC3Tier"<<endl;
    if(b31->GetName()!="AC2Tier" || b31->GetNumberOfTires()!=2 || b31->IsAC()!=true || b31->LoadFactor()!=2 || b31->IsSitting()!=false)
        cout<<"BookingClasses: Constructor error in AC2Tier"<<endl;
    if(b41->GetName()!="ACFirstClass" || b41->GetNumberOfTires()!=1 || b41->IsAC()!=true || b41->LoadFactor()!=3 || b41->IsSitting()!=false)
        cout<<"BookingClasses: Constructor error in ACFirstClass"<<endl;
    if(b51->GetName()!="FirstClass" || b51->GetNumberOfTires()!=2 || b51->IsAC()!=false || b51->LoadFactor()!=2 || b51->IsSitting()!=false)
        cout<<"BookingClasses: Constructor error in FirstClass"<<endl;
    if(b61->GetName()!="SecondSitting" || b61->GetNumberOfTires()!=0 || b11->IsAC()!=false || b61->LoadFactor()!=0.5 || b61->IsSitting()!=true)
        cout<<"BookingClasses: Constructor error in SecondSitting"<<endl;
    if(b71->GetName()!="ACChairCar" || b71->GetNumberOfTires()!=0 || b71->IsAC()!=true || b71->LoadFactor()!=1.25 || b71->IsSitting()!=true)
        cout<<"BookingClasses: Constructor error in ACChairCar"<<endl;
    cout<<*b11<<endl;
    cout<<*b21<<endl;
    cout<<*b31<<endl;
    cout<<*b41<<endl;
    cout<<*b51<<endl;
    cout<<*b61<<endl;
    cout<<*b71<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"---------------------Unit testing for Booking Class--------------------"<<endl;
    Booking book1(Station("Mumbai"),Station("Delhi"),Date(19,8,2021),dynamic_cast<BookingClasses *>(Sleeper::Type()));
    Booking book2(Station("Mumbai"),Station("Kolkata"),Date(19,8,2021),dynamic_cast<BookingClasses *>(AC2Tier::Type()));
    if(book1.GetFair()!=724 || book1.GetPNR()!=1)
        cout<<"Error in Booking Class"<<endl;
    if(book2.GetPNR()!=2)
        cout<<"Error in PNR allocation";
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
        cout << *(*it)<<endl;
    Booking::sBookings.clear();
    cout<<"-----------------------------------------------------------------------"<<endl;
    
}

void ApplicationTest(){
    cout << "------------------Booking Application Testing------------------------"<<endl;
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(21, 12, 2015), AC2Tier::Type());
    Booking b2(Station("Mumbai"), Station("Delhi"), Date(24, 12, 2022), AC3Tier::Type());
    Booking b3(Station("Mumbai"), Station("Delhi"), Date(14, 8, 2017), ACChairCar::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(28, 6, 2021), ACFirstClass::Type());
    Booking b5(Station("Mumbai"), Station("Delhi"), Date(24, 4, 2021), FirstClass::Type());
    Booking b6(Station("Mumbai"), Station("Delhi"), Date(9, 1, 2022), SecondSitting::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(22, 12, 2020), Sleeper::Type());
    Booking b8(Station("Mumbai"), Station("Bangalore"), Date(20, 5, 2017), AC2Tier::Type());
    Booking b9(Station("Mumbai"), Station("Bangalore"), Date(27, 1, 2022), AC3Tier::Type());
    Booking b10(Station("Mumbai"), Station("Bangalore"), Date(13, 9, 2018), ACChairCar::Type());
    Booking b11(Station("Mumbai"), Station("Bangalore"), Date(1, 1, 2015), ACFirstClass::Type());
    Booking b12(Station("Mumbai"), Station("Bangalore"), Date(29, 3, 2020), FirstClass::Type());
    Booking b13(Station("Mumbai"), Station("Bangalore"), Date(4, 9, 2020), SecondSitting::Type());
    Booking b14(Station("Mumbai"), Station("Bangalore"), Date(14, 9, 2018), Sleeper::Type());
    Booking b15(Station("Mumbai"), Station("Kolkata"), Date(20, 12, 2021), AC2Tier::Type());
    Booking b16(Station("Mumbai"), Station("Kolkata"), Date(13, 6, 2016), AC3Tier::Type());
    Booking b17(Station("Mumbai"), Station("Kolkata"), Date(5, 3, 2020), ACChairCar::Type());
    Booking b18(Station("Mumbai"), Station("Kolkata"), Date(27, 1, 2021), ACFirstClass::Type());
    Booking b19(Station("Mumbai"), Station("Kolkata"), Date(15, 12, 2015), FirstClass::Type());
    Booking b20(Station("Mumbai"), Station("Kolkata"), Date(22, 1, 2022), SecondSitting::Type());
    Booking b21(Station("Mumbai"), Station("Kolkata"), Date(13, 5, 2020), Sleeper::Type());
    Booking b22(Station("Mumbai"), Station("Chennai"), Date(15, 8, 2021), AC2Tier::Type());
    Booking b23(Station("Mumbai"), Station("Chennai"), Date(9, 2, 2021), AC3Tier::Type());
    Booking b24(Station("Mumbai"), Station("Chennai"), Date(5, 12, 2020), ACChairCar::Type());
    Booking b25(Station("Mumbai"), Station("Chennai"), Date(15, 3, 2020), ACFirstClass::Type());
    Booking b26(Station("Mumbai"), Station("Chennai"), Date(24, 9, 2022), FirstClass::Type());
    Booking b27(Station("Mumbai"), Station("Chennai"), Date(16, 5, 2022), SecondSitting::Type());
    Booking b28(Station("Mumbai"), Station("Chennai"), Date(30, 9, 2018), Sleeper::Type());
    Booking b29(Station("Delhi"), Station("Mumbai"), Date(22, 1, 2017), AC2Tier::Type());
    Booking b30(Station("Delhi"), Station("Mumbai"), Date(11, 1, 2021), AC3Tier::Type());
    Booking b31(Station("Delhi"), Station("Mumbai"), Date(15, 2, 2016), ACChairCar::Type());
    Booking b32(Station("Delhi"), Station("Mumbai"), Date(11, 3, 2019), ACFirstClass::Type());
    Booking b33(Station("Delhi"), Station("Mumbai"), Date(10, 2, 2016), FirstClass::Type());
    Booking b34(Station("Delhi"), Station("Mumbai"), Date(11, 3, 2021), SecondSitting::Type());
    Booking b35(Station("Delhi"), Station("Mumbai"), Date(19, 5, 2016), Sleeper::Type());
    Booking b36(Station("Delhi"), Station("Bangalore"), Date(18, 8, 2017), AC2Tier::Type());
    Booking b37(Station("Delhi"), Station("Bangalore"), Date(29, 3, 2015), AC3Tier::Type());
    Booking b38(Station("Delhi"), Station("Bangalore"), Date(28, 4, 2022), ACChairCar::Type());
    Booking b39(Station("Delhi"), Station("Bangalore"), Date(16, 6, 2018), ACFirstClass::Type());
    Booking b40(Station("Delhi"), Station("Bangalore"), Date(30, 2, 2020), FirstClass::Type());
    Booking b41(Station("Delhi"), Station("Bangalore"), Date(7, 2, 2015), SecondSitting::Type());
    Booking b42(Station("Delhi"), Station("Bangalore"), Date(2, 3, 2022), Sleeper::Type());
    Booking b43(Station("Delhi"), Station("Kolkata"), Date(20, 12, 2017), AC2Tier::Type());
    Booking b44(Station("Delhi"), Station("Kolkata"), Date(3, 8, 2019), AC3Tier::Type());
    Booking b45(Station("Delhi"), Station("Kolkata"), Date(7, 10, 2015), ACChairCar::Type());
    Booking b46(Station("Delhi"), Station("Kolkata"), Date(3, 10, 2022), ACFirstClass::Type());
    Booking b47(Station("Delhi"), Station("Kolkata"), Date(15, 8, 2019), FirstClass::Type());
    Booking b48(Station("Delhi"), Station("Kolkata"), Date(8, 10, 2018), SecondSitting::Type());
    Booking b49(Station("Delhi"), Station("Kolkata"), Date(5, 8, 2022), Sleeper::Type());
    Booking b50(Station("Delhi"), Station("Chennai"), Date(22, 7, 2020), AC2Tier::Type());
    Booking b51(Station("Delhi"), Station("Chennai"), Date(26, 6, 2018), AC3Tier::Type());
    Booking b52(Station("Delhi"), Station("Chennai"), Date(1, 7, 2015), ACChairCar::Type());
    Booking b53(Station("Delhi"), Station("Chennai"), Date(4, 10, 2019), ACFirstClass::Type());
    Booking b54(Station("Delhi"), Station("Chennai"), Date(14, 10, 2021), FirstClass::Type());
    Booking b55(Station("Delhi"), Station("Chennai"), Date(28, 1, 2020), SecondSitting::Type());
    Booking b56(Station("Delhi"), Station("Chennai"), Date(17, 1, 2020), Sleeper::Type());
    Booking b57(Station("Bangalore"), Station("Mumbai"), Date(23, 3, 2022), AC2Tier::Type());
    Booking b58(Station("Bangalore"), Station("Mumbai"), Date(2, 1, 2019), AC3Tier::Type());
    Booking b59(Station("Bangalore"), Station("Mumbai"), Date(28, 11, 2019), ACChairCar::Type());
    Booking b60(Station("Bangalore"), Station("Mumbai"), Date(31, 2, 2018), ACFirstClass::Type());
    Booking b61(Station("Bangalore"), Station("Mumbai"), Date(31, 11, 2020), FirstClass::Type());
    Booking b62(Station("Bangalore"), Station("Mumbai"), Date(11, 7, 2017), SecondSitting::Type());
    Booking b63(Station("Bangalore"), Station("Mumbai"), Date(10, 9, 2015), Sleeper::Type());
    Booking b64(Station("Bangalore"), Station("Delhi"), Date(13, 9, 2018), AC2Tier::Type());
    Booking b65(Station("Bangalore"), Station("Delhi"), Date(20, 6, 2017), AC3Tier::Type());
    Booking b66(Station("Bangalore"), Station("Delhi"), Date(20, 11, 2021), ACChairCar::Type());
    Booking b67(Station("Bangalore"), Station("Delhi"), Date(14, 7, 2019), ACFirstClass::Type());
    Booking b68(Station("Bangalore"), Station("Delhi"), Date(29, 11, 2022), FirstClass::Type());
    Booking b69(Station("Bangalore"), Station("Delhi"), Date(8, 12, 2018), SecondSitting::Type());
    Booking b70(Station("Bangalore"), Station("Delhi"), Date(10, 12, 2022), Sleeper::Type());
    Booking b71(Station("Bangalore"), Station("Kolkata"), Date(14, 5, 2017), AC2Tier::Type());
    Booking b72(Station("Bangalore"), Station("Kolkata"), Date(28, 6, 2020), AC3Tier::Type());
    Booking b73(Station("Bangalore"), Station("Kolkata"), Date(20, 1, 2017), ACChairCar::Type());
    Booking b74(Station("Bangalore"), Station("Kolkata"), Date(21, 3, 2018), ACFirstClass::Type());
    Booking b75(Station("Bangalore"), Station("Kolkata"), Date(16, 11, 2018), FirstClass::Type());
    Booking b76(Station("Bangalore"), Station("Kolkata"), Date(17, 12, 2021), SecondSitting::Type());
    Booking b77(Station("Bangalore"), Station("Kolkata"), Date(8, 4, 2017), Sleeper::Type());
    Booking b78(Station("Bangalore"), Station("Chennai"), Date(24, 12, 2021), AC2Tier::Type());
    Booking b79(Station("Bangalore"), Station("Chennai"), Date(22, 9, 2021), AC3Tier::Type());
    Booking b80(Station("Bangalore"), Station("Chennai"), Date(7, 3, 2016), ACChairCar::Type());
    Booking b81(Station("Bangalore"), Station("Chennai"), Date(26, 3, 2015), ACFirstClass::Type());
    Booking b82(Station("Bangalore"), Station("Chennai"), Date(19, 12, 2015), FirstClass::Type());
    Booking b83(Station("Bangalore"), Station("Chennai"), Date(20, 9, 2020), SecondSitting::Type());
    Booking b84(Station("Bangalore"), Station("Chennai"), Date(22, 1, 2020), Sleeper::Type());
    Booking b85(Station("Kolkata"), Station("Mumbai"), Date(20, 4, 2019), AC2Tier::Type());
    Booking b86(Station("Kolkata"), Station("Mumbai"), Date(7, 9, 2016), AC3Tier::Type());
    Booking b87(Station("Kolkata"), Station("Mumbai"), Date(28, 6, 2021), ACChairCar::Type());
    Booking b88(Station("Kolkata"), Station("Mumbai"), Date(6, 3, 2016), ACFirstClass::Type());
    Booking b89(Station("Kolkata"), Station("Mumbai"), Date(1, 4, 2019), FirstClass::Type());
    Booking b90(Station("Kolkata"), Station("Mumbai"), Date(8, 3, 2016), SecondSitting::Type());
    Booking b91(Station("Kolkata"), Station("Mumbai"), Date(11, 9, 2018), Sleeper::Type());
    Booking b92(Station("Kolkata"), Station("Delhi"), Date(31, 1, 2019), AC2Tier::Type());
    Booking b93(Station("Kolkata"), Station("Delhi"), Date(14, 7, 2019), AC3Tier::Type());
    Booking b94(Station("Kolkata"), Station("Delhi"), Date(23, 5, 2020), ACChairCar::Type());
    Booking b95(Station("Kolkata"), Station("Delhi"), Date(17, 4, 2020), ACFirstClass::Type());
    Booking b96(Station("Kolkata"), Station("Delhi"), Date(4, 10, 2018), FirstClass::Type());
    Booking b97(Station("Kolkata"), Station("Delhi"), Date(9, 4, 2016), SecondSitting::Type());
    Booking b98(Station("Kolkata"), Station("Delhi"), Date(17, 8, 2015), Sleeper::Type());
    Booking b99(Station("Kolkata"), Station("Bangalore"), Date(27, 11, 2015), AC2Tier::Type());
    Booking b100(Station("Kolkata"), Station("Bangalore"), Date(30, 10, 2021), AC3Tier::Type());
    Booking b101(Station("Kolkata"), Station("Bangalore"), Date(8, 4, 2015), ACChairCar::Type());
    Booking b102(Station("Kolkata"), Station("Bangalore"), Date(30, 6, 2016), ACFirstClass::Type());
    Booking b103(Station("Kolkata"), Station("Bangalore"), Date(29, 10, 2017), FirstClass::Type());
    Booking b104(Station("Kolkata"), Station("Bangalore"), Date(15, 1, 2015), SecondSitting::Type());
    Booking b105(Station("Kolkata"), Station("Bangalore"), Date(21, 3, 2016), Sleeper::Type());
    Booking b106(Station("Kolkata"), Station("Chennai"), Date(1, 8, 2021), AC2Tier::Type());
    Booking b107(Station("Kolkata"), Station("Chennai"), Date(15, 5, 2017), AC3Tier::Type());
    Booking b108(Station("Kolkata"), Station("Chennai"), Date(18, 3, 2016), ACChairCar::Type());
    Booking b109(Station("Kolkata"), Station("Chennai"), Date(29, 4, 2017), ACFirstClass::Type());
    Booking b110(Station("Kolkata"), Station("Chennai"), Date(11, 12, 2017), FirstClass::Type());
    Booking b111(Station("Kolkata"), Station("Chennai"), Date(16, 2, 2020), SecondSitting::Type());
    Booking b112(Station("Kolkata"), Station("Chennai"), Date(25, 9, 2020), Sleeper::Type());
    Booking b113(Station("Chennai"), Station("Mumbai"), Date(30, 7, 2021), AC2Tier::Type());
    Booking b114(Station("Chennai"), Station("Mumbai"), Date(13, 5, 2019), AC3Tier::Type());
    Booking b115(Station("Chennai"), Station("Mumbai"), Date(21, 6, 2021), ACChairCar::Type());
    Booking b116(Station("Chennai"), Station("Mumbai"), Date(23, 7, 2016), ACFirstClass::Type());
    Booking b117(Station("Chennai"), Station("Mumbai"), Date(2, 5, 2017), FirstClass::Type());
    Booking b118(Station("Chennai"), Station("Mumbai"), Date(19, 9, 2016), SecondSitting::Type());
    Booking b119(Station("Chennai"), Station("Mumbai"), Date(28, 5, 2018), Sleeper::Type());
    Booking b120(Station("Chennai"), Station("Delhi"), Date(30, 12, 2018), AC2Tier::Type());
    Booking b121(Station("Chennai"), Station("Delhi"), Date(5, 7, 2016), AC3Tier::Type());
    Booking b122(Station("Chennai"), Station("Delhi"), Date(30, 10, 2016), ACChairCar::Type());
    Booking b123(Station("Chennai"), Station("Delhi"), Date(29, 2, 2020), ACFirstClass::Type());
    Booking b124(Station("Chennai"), Station("Delhi"), Date(2, 8, 2021), FirstClass::Type());
    Booking b125(Station("Chennai"), Station("Delhi"), Date(6, 4, 2022), SecondSitting::Type());
    Booking b126(Station("Chennai"), Station("Delhi"), Date(23, 5, 2020), Sleeper::Type());
    Booking b127(Station("Chennai"), Station("Bangalore"), Date(2, 6, 2022), AC2Tier::Type());
    Booking b128(Station("Chennai"), Station("Bangalore"), Date(17, 6, 2019), AC3Tier::Type());
    Booking b129(Station("Chennai"), Station("Bangalore"), Date(18, 4, 2017), ACChairCar::Type());
    Booking b130(Station("Chennai"), Station("Bangalore"), Date(1, 8, 2022), ACFirstClass::Type());
    Booking b131(Station("Chennai"), Station("Bangalore"), Date(27, 6, 2019), FirstClass::Type());
    Booking b132(Station("Chennai"), Station("Bangalore"), Date(12, 1, 2020), SecondSitting::Type());
    Booking b133(Station("Chennai"), Station("Bangalore"), Date(4, 3, 2020), Sleeper::Type());
    Booking b134(Station("Chennai"), Station("Kolkata"), Date(4, 12, 2020), AC2Tier::Type());
    Booking b135(Station("Chennai"), Station("Kolkata"), Date(14, 3, 2019), AC3Tier::Type());
    Booking b136(Station("Chennai"), Station("Kolkata"), Date(3, 1, 2016), ACChairCar::Type());
    Booking b137(Station("Chennai"), Station("Kolkata"), Date(26, 9, 2019), ACFirstClass::Type());
    Booking b138(Station("Chennai"), Station("Kolkata"), Date(18, 11, 2015), FirstClass::Type());
    Booking b139(Station("Chennai"), Station("Kolkata"), Date(24, 4, 2017), SecondSitting::Type());
    Booking b140(Station("Chennai"), Station("Kolkata"), Date(25, 7, 2016), Sleeper::Type());

    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
        cout << *(*it)<<endl<<endl;
    Booking::sBookings.clear();
    cout << "---------------------------------------------------------------------------" << endl;
}

void CreateBooking(){
    cout<<"--------------------Given Application Test Part-3----------------------------" << endl;
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
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
        cout << *(*it)<<endl<<endl;
    Booking::sBookings.clear();
    cout << "---------------------------------------------------------------------------" << endl;
}


int main(){
    UnitTesting();
    ApplicationTest();
    CreateBooking();
}