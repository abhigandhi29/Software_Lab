//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include <set>
#include "Station.h"
#include "Exception.h"
using namespace std;

#ifndef _RAILWAY_H
#define _RAILWAY_H
class Railway{
    private:
        string name_ = "Indian Railway";
        
    protected:
        Railway();
    public:
        ~Railway();
        static vector<Station> sStations;
        static vector<pair<pair<Station,Station>,int>> sDistStation;
        static const Railway &IndianRailways();
        static int GetDistance(const Station &a,const Station &b);
        friend ostream &operator<<(ostream &,const Railway &);
        static bool VerifyData();
};

#endif