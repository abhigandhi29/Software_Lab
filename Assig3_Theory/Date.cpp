#include "Date.h"

vector<string> Date::sMonthNames{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
vector<string> Date::sDayNames{"Monday", "Tuesday", "Wednesday", "Thursday",
                                     "Friday", "Saturday", "Sunday"};

Date::Date(uint32_t d, uint32_t m, uint32_t y) : date_(d), month_(m), year_(y) {}
Date::Date(const Date& d):date_(d.date_),month_(d.month_),year_(d.year_){}
ostream &operator<<(ostream &out, const Date &d){
    out<<d.date_<<'/'<<d.sMonthNames[d.month_-1]<<'/'<<d.year_;
    return out;
}
Date::~Date(){}

