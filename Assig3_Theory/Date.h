#include<iostream>
#include<vector>
using namespace std;
#ifndef _DATE_H
#define _DATE_H

using namespace std;

class Date
{
private:
    static vector<string> sMonthNames;
    static vector<string> sDayNames;
    const uint32_t day_;
    const uint32_t month_;
    const uint32_t year_;

public:
    Date(uint32_t d, uint32_t m, uint32_t y);
    Date(const Date &d);
    friend ostream &operator<<(ostream &, const Date &);
    friend bool operator==(const Date &, const Date &);
    ~Date();
    inline uint32_t getDay() const{
        return day_;
    }
    inline uint32_t getMonth() const{
        return month_;
    }
    inline uint32_t getYear() const{
        return year_;
    }
};
#endif