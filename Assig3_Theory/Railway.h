#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "Station.h"
using namespace std;

#ifndef _RAILWAY_H
#define _RAILWAY_H
class Railway{
    private:
        string name = "Indian Railway";
        static vector<Station> sStations;
        static Railway *sIndianRailways;
        static vector<pair<pair<Station,Station>,int>> sDistStation;
    protected:
        Railway();
    public:
        ~Railway();
        static const Railway *IndianRailways();
        static int GetDistance(const Station &a,const Station &b);
};

#endif