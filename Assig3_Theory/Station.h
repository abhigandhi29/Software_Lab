#include<iostream>
using namespace std;

#ifndef _STATION_H
#define _STATION_H

class Station{
    private:
        string name_;
    public:
        Station(string name);
        Station(const Station &s);
        inline string GetName() const{
            return name_;
        }
        int GetDistance(Station &other) const;
        friend ostream &operator<<(ostream &, const Station &);
        friend bool operator==(const Station &, const Station &);

};

#endif