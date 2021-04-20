//Abhishek Gandhi
//19CS10031
#include "BookingClasses.h"
#include "Booking.h"
#include "Railway.h"
#include "Date.h"
#include "Passenger.h"
#include "Gender.h"
#include "Concession.h"
#include "Station.h"
#include "Divyaang.h"
#include "Exception.h"
#include "Name.h"

template<> bool BookingClasses::AC2Tier::sIsLuxury = false;
template<> double BookingClasses::AC2Tier::sLoadFactor = 4.0;
template<> double BookingClasses::AC2Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC2Tier::sMaxTatkaalCharge = 500;
template<> double BookingClasses::AC2Tier::sMinTatkaalCharge = 400;
template<> double BookingClasses::AC2Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC2Tier::sReservationCharge = 50;

template<> bool BookingClasses::ACFirstClass::sIsLuxury = true;
template<> double BookingClasses::ACFirstClass::sLoadFactor = 6.50;
template<> double BookingClasses::ACFirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACFirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ACFirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::ACFirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::ACFirstClass::sReservationCharge = 60;

template<> bool BookingClasses::ExecutiveChairCar::sIsLuxury = true;
template<> double BookingClasses::ExecutiveChairCar::sLoadFactor = 5.0;
template<> double BookingClasses::ExecutiveChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ExecutiveChairCar::sMaxTatkaalCharge = 500;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalCharge = 400;
template<> double BookingClasses::ExecutiveChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ExecutiveChairCar::sReservationCharge = 60;

template<> bool BookingClasses::AC3Tier::sIsLuxury = false;
template<> double BookingClasses::AC3Tier::sLoadFactor = 2.5;
template<> double BookingClasses::AC3Tier::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::AC3Tier::sMaxTatkaalCharge = 400;
template<> double BookingClasses::AC3Tier::sMinTatkaalCharge = 300;
template<> double BookingClasses::AC3Tier::sMinTatkaalDistance = 500;
template<> double BookingClasses::AC3Tier::sReservationCharge = 40;

template<> bool BookingClasses::Sleeper::sIsLuxury = false;
template<> double BookingClasses::Sleeper::sLoadFactor = 1.0;
template<> double BookingClasses::Sleeper::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::Sleeper::sMaxTatkaalCharge = 200;
template<> double BookingClasses::Sleeper::sMinTatkaalCharge = 100;
template<> double BookingClasses::Sleeper::sMinTatkaalDistance = 500;
template<> double BookingClasses::Sleeper::sReservationCharge = 20;

template<> bool BookingClasses::SecondSitting::sIsLuxury = false;
template<> double BookingClasses::SecondSitting::sLoadFactor = 0.6;
template<> double BookingClasses::SecondSitting::sTatkalLoadFactor = 0.1;
template<> double BookingClasses::SecondSitting::sMaxTatkaalCharge = 15;
template<> double BookingClasses::SecondSitting::sMinTatkaalCharge = 10;
template<> double BookingClasses::SecondSitting::sMinTatkaalDistance = 100;
template<> double BookingClasses::SecondSitting::sReservationCharge = 15;

template<> bool BookingClasses::ACChairCar::sIsLuxury = false;
template<> double BookingClasses::ACChairCar::sLoadFactor = 2.0;
template<> double BookingClasses::ACChairCar::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::ACChairCar::sMaxTatkaalCharge = 225;
template<> double BookingClasses::ACChairCar::sMinTatkaalCharge = 125;
template<> double BookingClasses::ACChairCar::sMinTatkaalDistance = 250;
template<> double BookingClasses::ACChairCar::sReservationCharge = 40;

template<> bool BookingClasses::FirstClass::sIsLuxury = true;
template<> double BookingClasses::FirstClass::sLoadFactor = 3.0;
template<> double BookingClasses::FirstClass::sTatkalLoadFactor = 0.3;
template<> double BookingClasses::FirstClass::sMaxTatkaalCharge = 500;
template<> double BookingClasses::FirstClass::sMinTatkaalCharge = 400;
template<> double BookingClasses::FirstClass::sMinTatkaalDistance = 500;
template<> double BookingClasses::FirstClass::sReservationCharge = 50;

double Booking::sBaseFairPerKM = 0.5;

double LadiesConcession::sConcessioFactor = 0;

template<> double Divyaang::Blind::sACFirstClassConcession = 0.5;
template<> double Divyaang::Blind::sFirstClassConcession = 0.75;
template<> double Divyaang::Blind::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::Blind::sAC2TierConcession = 0.5;
template<> double Divyaang::Blind::sAC3TierConcession = 0.75;
template<> double Divyaang::Blind::sACChairCarConcession = 0.75;
template<> double Divyaang::Blind::sSleeperConcession = 0.75;
template<> double Divyaang::Blind::sSecondSittingConcession = 0.75;

template<> double Divyaang::OrthopaedicallyHandicapped::sACFirstClassConcession = 0.5;
template<> double Divyaang::OrthopaedicallyHandicapped::sFirstClassConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sAC2TierConcession = 0.5;
template<> double Divyaang::OrthopaedicallyHandicapped::sAC3TierConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sACChairCarConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sSleeperConcession = 0.75;
template<> double Divyaang::OrthopaedicallyHandicapped::sSecondSittingConcession = 0.75;

template<> double Divyaang::CancerPatients::sACFirstClassConcession = 0.5;
template<> double Divyaang::CancerPatients::sFirstClassConcession = 0.75;
template<> double Divyaang::CancerPatients::sExecutiveChairCarConcession = 0.75;
template<> double Divyaang::CancerPatients::sAC2TierConcession = 0.5;
template<> double Divyaang::CancerPatients::sAC3TierConcession = 1.0;
template<> double Divyaang::CancerPatients::sACChairCarConcession = 1.0;
template<> double Divyaang::CancerPatients::sSleeperConcession = 1.0;
template<> double Divyaang::CancerPatients::sSecondSittingConcession = 1.0;

template<> double Divyaang::TBPatients::sACFirstClassConcession = 0;
template<> double Divyaang::TBPatients::sFirstClassConcession = 0.75;
template<> double Divyaang::TBPatients::sExecutiveChairCarConcession = 0;
template<> double Divyaang::TBPatients::sAC2TierConcession = 0;
template<> double Divyaang::TBPatients::sAC3TierConcession = 0;
template<> double Divyaang::TBPatients::sACChairCarConcession = 0;
template<> double Divyaang::TBPatients::sSleeperConcession = 0.75;
template<> double Divyaang::TBPatients::sSecondSittingConcession = 0.75;

template<> double Gender::Male::sSeniorCitizenConsessionFactor =  0.4;
template<> double Gender::Female::sSeniorCitizenConsessionFactor =  0.5;

template<> int Gender::Male::sConcessionAge = 60;
template<> int Gender::Female::sConcessionAge = 58;

vector<Station> Railway::sStations{
    Station::GetInstance("Mumbai"),
    Station::GetInstance("Delhi"),
    Station::GetInstance("Bangalore"),
    Station::GetInstance("Kolkata"),
    Station::GetInstance("Chennai")
};
vector<pair<pair<Station,Station>,int>> Railway::sDistStation{
    {{Station::GetInstance("Mumbai"),Station::GetInstance("Delhi")},1447},
    {{Station::GetInstance("Mumbai"),Station::GetInstance("Bangalore")},981},
    {{Station::GetInstance("Mumbai"),Station::GetInstance("Kolkata")},2014},
    {{Station::GetInstance("Mumbai"),Station::GetInstance("Chennai")},1338},
    {{Station::GetInstance("Bangalore"),Station::GetInstance("Delhi")},2150},
    {{Station::GetInstance("Kolkata"),Station::GetInstance("Delhi")},1472},
    {{Station::GetInstance("Chennai"),Station::GetInstance("Delhi")},2180},
    {{Station::GetInstance("Bangalore"),Station::GetInstance("Kolkata")},1871},
    {{Station::GetInstance("Bangalore"),Station::GetInstance("Chennai")},350},
    {{Station::GetInstance("Kolkata"),Station::GetInstance("Chennai")},1659}
};

void UnitTesting(){
    cout<<"Abhishek Gandhi"<<endl;
    cout<<"19CS10031"<<endl;
    cout<<"\n-----------------Unit Testing For Station Class------------------------"<<endl;
    Station s1 = Station::GetInstance("Mumbai"),s2=Station::GetInstance("Delhi"),s3=Station::GetInstance("Mumbai");
    if(s1.GetName()!="Mumbai" || s2.GetName()!="Delhi" || s3.GetName()!="Mumbai")
        cout<<"Station: Error in name_ string variable value assignment"<<endl;
    if(!(s1==s3))
        cout<<"Station: Error in operator="<<endl;
    Station s4 = Station(s2);
    if(!(s4==s2))
        cout<<"Station: Error in copy operator"<<endl;
    if(s1.GetDistance(s2)!=1447)
        cout<<"Station: Error in GetDistance Function"<<endl;
    cout<<s1<<endl;
    try{
        Station::GetInstance("");
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working properly"<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------"<<endl;

    cout<<"-----------------Unit Testing For Railway Class------------------------"<<endl;
    const Railway &r1 = Railway::IndianRailways();
    const Railway &r2 = Railway::IndianRailways();
    //cout<<&r1<<" "<<&r2<<endl;
    if(&r1 != &r2)
        cout<<"Railway: Error IndianRailways function, failed to create a singleton class"<<endl;
    if(r1.GetDistance(s1,s2)!=1447)
        cout<<"Railway: Error in GetDistance function"<<endl;
    cout<<r1<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"\n--------------------Unit Testing For Date Class------------------------"<<endl;
    Date d1 = Date::GetInstance(29,01,2001),d2 = Date::GetInstance(7,03,2021);
    if(d1.GetDay()!=29 || d1.GetMonth()!=01 || d1.GetYear()!=2001)
        cout<<"Date: Error during GetInstanceion of 29/Jan/2001"<<endl;
    if(d2.GetDay()!=7 || d2.GetMonth()!=03 || d2.GetYear()!=2021)
        cout<<"Date: Error during GetInstanceion of 7/Mar/2021"<<endl;
    Date d3 = Date(d1);
    if(d3.GetDay()!=29 || d3.GetMonth()!=01 || d3.GetYear()!=2001)
        cout<<"Date: Error in copy GetInstanceor"<<endl;
    if(d1==d2 || !(d1==d3))  
        cout<<"Date: Error in comparison"<<endl;
    cout<<"d1 = "<<d1<<endl;
    cout<<"d2 = "<<d2<<endl;
    cout<<"d3 = "<<d3<<endl;
    try{
        Date::GetInstance(29,02,2000);
        cout<<"Prime year check working"<<endl;
        Date::GetInstance(29,02,2001);
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Date: Verify Date working Correctly"<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;

    cout<<"\n----------------------Unit Testing For Name Classes--------------------"<<endl;
    Name n= Name::GetInstance("Abhishek","Rajesh","Gandhi");
    if(n.GetName()!="Abhishek Rajesh Gandhi"){
        cout<<"Name: Error in Assignment Operation"<<endl;
    }
    cout<<"Name: "<<n<<endl;
    try{
        Name::GetInstance("","aa","");
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error Catching Working Correctly"<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"\n-----------------Unit Testing For Passenger Classes--------------------"<<endl;
    Passenger p1 = Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"1234567890");
    Passenger p2 = Passenger::GetInstance("someguy","","shit","123456789012",Gender::Male::Type(),Date(11,04,1996),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh");
    if(!(p1.GetName()==Name::GetInstance("Abhishek","","Gandhi") && p1.GetNumber()=="1234567890" || p1.GetBOD()==Date::GetInstance(29,01,2001))){
        cout<<"Passenger: Error! in assignment"<<endl;
    }
    cout<<"p1= "<<p1<<endl;
    cout<<"p2= "<<p2<<endl;
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","1234567812",Gender::Male::Type(),Date(29,1,2001),"1234567890");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","1234AB789012",Gender::Male::Type(),Date(29,1,2001),"1234567890");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"12367890");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"1234a67890");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2022),"1234567890");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    try{
        Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"1234567890",&Divyaang::Blind::Type(),"asd");
        cout<<"Error Exception Handeling"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Exception handling working correctly"<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;

    cout<<"\n----------------------Unit Testing For Gender Classes--------------------"<<endl;
    const Gender *m11 = &Gender::Male::Type();
    const Gender *m12 = &Gender::Male::Type();
    const Gender *f11 = &Gender::Female::Type();
    const Gender *f12 = &Gender::Female::Type();
    if(m11!=m12 || f11!=f12)
        cout<<"Gender: Error Type function, failed to create a singleton class"<<endl;
    if(m11->GetConcessionAge()!=60 || m11->GetSeniorCitizenCon()!=0.4 || m11->GetType()!="Male")
        cout<<"Gender: Error in male class data allotment"<<endl;
    if(f11->GetConcessionAge()!=58 || f11->GetSeniorCitizenCon()!=0.5|| f11->GetType()!="Female")
        cout<<"Gender: Error in female class data allotment"<<endl;
    cout<<"Male: "<<*m11<<endl<<endl;
    cout<<"Female: "<<*f11<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    cout<<"\n----------------------Unit Testing For Divyaang Classes--------------------"<<endl;
    const Divyaang *d11 = &Divyaang::CancerPatients::Type();
    const Divyaang *d12 = &Divyaang::CancerPatients::Type();
    const Divyaang *d21 = &Divyaang::TBPatients::Type();
    const Divyaang *d22 = &Divyaang::TBPatients::Type();
    const Divyaang *d31 = &Divyaang::Blind::Type();
    const Divyaang *d32 = &Divyaang::Blind::Type();
    const Divyaang *d41 = &Divyaang::OrthopaedicallyHandicapped::Type();
    const Divyaang *d42 = &Divyaang::OrthopaedicallyHandicapped::Type();
    if(d11!=d12 || d21!=d22 || d31!=d32 || d41!=d42)
        cout<<"Divyaang! Error in creating singleton class"<<endl;
    cout<<"Blind: "<<*d31<<endl<<endl;
    cout<<"CancerPatients: "<<*d11<<endl<<endl;
    cout<<"Handicapped: "<<*d41<<endl<<endl;
    cout<<"TBPatients: "<<*d21<<endl;

    cout<<"-----------------------------------------------------------------------"<<endl;


    cout<<"\n----------------------Unit Testing For Concession Classes--------------------"<<endl;
    LadiesConcession ladies = LadiesConcession::Type();
    DivyaangConcession divyaang = DivyaangConcession::Type();
    GeneralConcession general = GeneralConcession::Type();
    SeniorCitizenConcession senior = SeniorCitizenConcession::Type();
    LadiesConcession ladies1 = LadiesConcession::Type();
    DivyaangConcession divyaang1 = DivyaangConcession::Type();
    GeneralConcession general1 = GeneralConcession::Type();
    SeniorCitizenConcession senior1 = SeniorCitizenConcession::Type();
    Passenger temp = Passenger::GetInstance("Varsha","","Gandhi","123456789098",Gender::Female::Type(),Date(10,9,1950),"1234567890");
    Passenger temp1 = Passenger::GetInstance("","","Gandhi","123456789098",Gender::Male::Type(),Date(10,9,1950),"1234567890");
    if(!(&ladies != &ladies1 || &divyaang1!=&divyaang || &senior1!=&senior1 || &general1!=&general))
        cout<<"Error in singelton creation"<<endl;
    if(ladies.GetConcessionFactor(temp)!=0)
        cout<<"Error in ladies concession"<<endl;
    const BookingClasses &temp2 = dynamic_cast<const BookingClasses &>(BookingClasses::AC2Tier::Type());
    if(divyaang.GetConcessionFactor(p2,const_cast<BookingClasses &>(temp2))!=0.5)
        cout<<"Error in Divyaang concession"<<endl;
    if(general.GetConcessionFactor()!=0)
        cout<<"Error in General concession"<<endl;
    if(senior.GetConcessionFactor(temp)!=0.5 || senior.GetConcessionFactor(temp1)!=0.4)
        cout<<"Error in SeniorCitizen concession"<<endl;

    cout<<"GeneralConcession: "<<general<<endl<<endl;
    cout<<"LadiesConcession: "<<ladies<<endl<<endl;
    cout<<"SeniorCitizenConcession: "<<senior<<endl<<endl;
    cout<<"DivyaangConcession: "<<divyaang<<endl;
    
    cout<<"-----------------------------------------------------------------------"<<endl;

    cout<<"\n------------Unit Testing For BookingClasses Classes--------------------"<<endl;

    const BookingClasses *b11 = &BookingClasses::Sleeper::Type();
    const BookingClasses *b12 = &BookingClasses::Sleeper::Type();
    const BookingClasses *b21 = &BookingClasses::AC3Tier::Type();
    const BookingClasses *b22 = &BookingClasses::AC3Tier::Type();
    const BookingClasses *b31 = &BookingClasses::AC2Tier::Type();
    const BookingClasses *b32 = &BookingClasses::AC2Tier::Type();
    const BookingClasses *b41 = &BookingClasses::ACFirstClass::Type();
    const BookingClasses *b42 = &BookingClasses::ACFirstClass::Type();
    const BookingClasses *b51 = &BookingClasses::FirstClass::Type();
    const BookingClasses *b52 = &BookingClasses::FirstClass::Type();
    const BookingClasses *b61 = &BookingClasses::SecondSitting::Type();
    const BookingClasses *b62 = &BookingClasses::SecondSitting::Type();
    const BookingClasses *b71 = &BookingClasses::ACChairCar::Type();
    const BookingClasses *b72 = &BookingClasses::ACChairCar::Type();
    const BookingClasses *b81 = &BookingClasses::ExecutiveChairCar::Type();
    const BookingClasses *b82 = &BookingClasses::ExecutiveChairCar::Type();
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
        cout<<"BookingClasses: Not a Singleton, Check SecondSitting Type Function"<<endl;
    if(b71!=b72)
        cout<<"BookingClasses: Not a Singleton, Check ACChairCar Type Function"<<endl;
    if(b81!=b82)
        cout<<"BookingClasses: Not a Singleton, Check ExecuitveChairCar Type Function"<<endl;
    if(b11->GetName()!="Sleeper" || b11->GetNumberOfTires()!=3 || b11->IsAC()!=false || b11->LoadFactor()!=1 || b11->IsSitting()!=false)
        cout<<"BookingClasses: GetInstance error in sleeper"<<endl;
    if(b21->GetName()!="AC3Tier" || b21->GetNumberOfTires()!=3 || b21->IsAC()!=true || b21->LoadFactor()!=2.5 || b21->IsSitting()!=false)
        cout<<"BookingClasses: GetInstance error in AC3Tier"<<endl;
    if(b31->GetName()!="AC2Tier" || b31->GetNumberOfTires()!=2 || b31->IsAC()!=true || b31->LoadFactor()!=4.0 || b31->IsSitting()!=false)
        cout<<"BookingClasses: GetInstance error in AC2Tier"<<endl;
    if(b41->GetName()!="ACFirstClass" || b41->GetNumberOfTires()!=1 || b41->IsAC()!=true || b41->LoadFactor()!=6.50 || b41->IsSitting()!=false)
        cout<<"BookingClasses: GetInstance error in ACFirstClass"<<endl;
    if(b51->GetName()!="FirstClass" || b51->GetNumberOfTires()!=2 || b51->IsAC()!=true || b51->LoadFactor()!=3.0 || b51->IsSitting()!=false)
        cout<<"BookingClasses: GetInstance error in FirstClass"<<endl;
    if(b61->GetName()!="SecondSitting" || b61->GetNumberOfTires()!=0 || b11->IsAC()!=false || b61->LoadFactor()!=0.6 || b61->IsSitting()!=true)
        cout<<"BookingClasses: GetInstance error in SecondSitting"<<endl;
    if(b71->GetName()!="ACChairCar" || b71->GetNumberOfTires()!=0 || b71->IsAC()!=true || b71->LoadFactor()!=2.0 || b71->IsSitting()!=true)
        cout<<"BookingClasses: GetInstance error in ACChairCar"<<endl;
    if(b81->GetName()!="ExecutiveChairCar" || b81->GetNumberOfTires()!=0 || b81->IsAC()!=true || b81->LoadFactor()!=5.0 || b81->IsSitting()!=true)
        cout<<"BookingClasses: GetInstance error in ExecutiveChairCar"<<endl;
    cout<<*b11<<endl;
    cout<<*b21<<endl;
    cout<<*b31<<endl;
    cout<<*b41<<endl;
    cout<<*b51<<endl;
    cout<<*b61<<endl;
    cout<<*b71<<endl;
    cout<<*b81<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    
    cout<<"\n---------------------Unit testing for Booking Class--------------------"<<endl;
    
    Booking *b1 = dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1));
    Booking *b2 = dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p2));
    if(b1->GetFair()!=1849 || b1->GetPNR()!=1)
        cout<<"Error in Booking Class"<<endl;
    if(b2->GetPNR()!=2)
        cout<<"Error in PNR allocation";
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
        cout << *(*it)<<endl;
    Booking::sBookings.clear();
    try{
        Booking::GeneralBooking::MakeReservation(Station::GetInstance("Mumb"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1);
        cout<<"Error! Error detection not working"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error handeling working correctly"<<endl;
    }
    try{
        Booking::GeneralBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2022),&BookingClasses::AC3Tier::Type(),p1);
        cout<<"Error! Error detection not working"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error handeling working correctly"<<endl;
    }
    try{
        Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1);
        cout<<"Error! Error detection not working"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error handeling working correctly"<<endl;
    }
    try{
        Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1);
        cout<<"Error! Error detection not working"<<endl;
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error handeling working correctly"<<endl;
    }
    cout<<"-----------------------------------------------------------------------"<<endl;

}

void ApplicationTestingPositive(){

    cout<<"\n-------------------Positive Applicaton Testing-----------------------"<<endl;
    try{
        Booking *b11 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b12 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b13 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b14 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b15 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b16 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b17 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b18 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        
        Booking *b21 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b22 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b23 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b24 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b25 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b26 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b27 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        Booking *b28 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
        
        Booking *b31 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b32 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b33 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b34 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b35 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b36 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b37 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b38 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));

        Booking *b41 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b42 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b43 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b44 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b45 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b46 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b47 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        Booking *b48 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"1234567890")));
        
        Booking *b51 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b52 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b53 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b54 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b55 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b56 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b57 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b58 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));


        Booking *b61 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b62 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b63 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b64 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b65 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b66 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b67 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        Booking *b68 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
        
        Booking *b71 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b72 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b73 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b74 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b75 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b76 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b77 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));
        Booking *b78 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh")));

        Booking *b81 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b82 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b83 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b84 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b85 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b86 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b87 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));
        Booking *b88 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::OrthopaedicallyHandicapped::Type(),"eff1234567890sdfgh")));

        Booking *b91 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b92 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b93 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b94 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b95 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b96 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b97 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        Booking *b98 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff1234567890sdfgh")));
        
        Booking *b101 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));  
        Booking *b102 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC2Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
        Booking *b103 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ExecutiveChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));    
        Booking *b104 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::Sleeper::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
        Booking *b105 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::SecondSitting::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
        Booking *b106 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::FirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
        Booking *b107 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACChairCar::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
        Booking *b108 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::ACFirstClass::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::TBPatients::Type(),"eff1234567890sdfgh")));   
    }
    catch(exception &e){
        cout<<"Error: "<<e.what();
        cout<<"Error in positive Case Preventing Tesmination and Moving on to Negative Case."<<endl;
    }
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
        cout << *(*it)<<endl<<endl;
    Booking::sBookings.clear();
    cout<<"\n-----------------------------------------------------------------------"<<endl;
}

void ApplicationTestingNegative(){
    cout<<"\n--------------------Negative Application Testing----------------------"<<endl;
    try{
        Booking *b1 =dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("D") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{
        Booking *b1 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 5 , 2022) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Female::Type() , Date::GetInstance(8,10,2001),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }
    try{
        Booking *b1 =dynamic_cast<Booking *>(Booking::LadiesBooking::MakeReservation(Station::GetInstance("Mumbai") , Station::GetInstance("Delhi") , Date::GetInstance(17 , 5 , 2022) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Gunjan","","","123456789111",Gender::Male::Type() , Date::GetInstance(8,10,2001),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2020) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,1950),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2020) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Sajal","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::SeniorCitizenBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Sajol","","","123456789111",Gender::Female::Type() , Date::GetInstance(17,12,1950),"12367890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::TatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","123456789111",Gender::Male::Type() , Date::GetInstance(29,01,2031),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::PremiumTatkalBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Abhishek","","","1234567fdg89111",Gender::Male::Type() , Date::GetInstance(29,01,2001),"1234567890")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::Blind::Type(),"eff123490sdfgh")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",NULL,"eff1234567890sdfgh")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    try{    
        Booking *b1 =dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Delhi") , Station::GetInstance("Mumbai")  , Date::GetInstance(17 , 3 , 2021) , &BookingClasses::AC3Tier::Type() , Passenger::GetInstance("Ramu","","","123456789111",Gender::Male::Type() , Date::GetInstance(17,12,2001),"1234567890",&Divyaang::CancerPatients::Type(),"eff123456dfh7890sdfgh")));
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error! Successfully found"<<endl;
    }    
    
    if(Booking::sBookings.size()!=0)
        cout<<"Booking formed Constructor called! Error in MakeReservation"<<endl;
    
    cout<<"\n-----------------------------------------------------------------------"<<endl;
}

int main(){
    try{
        UnitTesting();
        ApplicationTestingPositive();
        ApplicationTestingNegative();
    }
    catch(exception &e){
        cout<<e.what();
        cout<<"Error in UnitTesting- Something is wrong"<<endl;
    }
    try{
        Railway::IndianRailways();
    }
    catch(exception &t){
        cout<<t.what()<<endl;
    }
    try{
        Passenger p1 = Passenger::GetInstance("Abhishek","","Gandhi","123456789012",Gender::Male::Type(),Date(29,1,2001),"1234567890");
        Booking *b1 = dynamic_cast<Booking *>(Booking::GeneralBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p1));
        Passenger p2 = Passenger::GetInstance("someguy","","shit","123456789012",Gender::Male::Type(),Date(11,04,1996),"1234567890",&Divyaang::Blind::Type(),"eff1234567890sdfgh");
        Booking *b2 = dynamic_cast<Booking *>(Booking::DivyaangBooking::MakeReservation(Station::GetInstance("Mumbai"), Station::GetInstance("Delhi"),Date(21, 12, 2021),&BookingClasses::AC3Tier::Type(),p2));
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    return 1;
}