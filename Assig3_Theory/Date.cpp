#include "Date.h"

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
Date::~Date(){}

