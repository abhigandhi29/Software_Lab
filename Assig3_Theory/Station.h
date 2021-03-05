#include<iostream>
using namespace std;

#ifndef _STATION_H
#define _STATION_H

class Station{
    private:
        const string name_;
    public:
        Station(string name);
        inline string GetName() const{
            return name_;
        }
        int GetDistance(string other) const;
        friend ostream &operator<<(ostream &, const Station &);

};

#endif