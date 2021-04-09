//Abhishek Gandhi
//19CS10031
#include "Date.h"
int Date::sMinyear = 1900;
int Date::sMaxYear = 2099;

vector<string> Date::sMonthNames{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
vector<string> Date::sDayNames{"Monday", "Tuesday", "Wednesday", "Thursday",
                                     "Friday", "Saturday", "Sunday"};

Date::Date(uint32_t d, uint32_t m, uint32_t y) : day_(d), month_(m), year_(y) {}
Date::Date(const Date& d):day_(d.day_),month_(d.month_),year_(d.year_){}
ostream &operator<<(ostream &out, const Date &d){
    out<<d.day_<<'/'<<d.sMonthNames[d.month_-1]<<'/'<<d.year_;
    return out;
}
bool operator==(const Date&d1, const Date &d2){
    if(d1.GetDay()==d2.GetDay() && d1.GetMonth()==d2.GetMonth() && d1.GetYear()==d2.GetYear())
        return true;
    return false;
}
bool operator>(const Date &d1, const Date &d2){
    //cout<<d1.GetYear()<<d2.GetYear()<<endl;
    if(d1.GetYear()>d2.GetYear()){
        return true;
    }
    else if(d1.GetYear()==d2.GetYear()){
        if(d1.GetMonth()>d2.GetMonth()){
            return true;
        }
        else if(d1.GetMonth()==d2.GetMonth()){
            if(d1.GetDay()>d2.GetDay()){
                return true;
            }
        }
    }
    return false;
}
bool operator<(const Date &d1, const Date &d2){
    //cout<<"here3"<<endl;
    if(d1.GetYear()<d2.GetYear()){
        return true;
    }
    else if(d1.GetYear()==d2.GetYear()){
        if(d1.GetMonth()<d2.GetMonth()){
            return true;
        }
        else if(d1.GetMonth()==d2.GetMonth()){
            if(d1.GetDay()<d2.GetDay()){
                return true;
            }
        }
    }
    return false;
}

Date::~Date(){}


bool Date::IsLeap(int year){
// Return true if year
// is a multiple pf 4 and
// not multiple of 100.
return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
 
bool Date::IsValidDate(int d, int m, int y){
    if (y < sMinyear || y > sMaxYear)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
 
    if (m == 2)
    {
        if (IsLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
 
    
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
 
    return true;
}

Date Date::GetInstance(int d,int m,int y){
    BadDate derror;
    if(!IsValidDate(d,m,y)){
        throw derror;
    }
    return Date(d,m,y);
}
 