#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <map> 
#include <vector>
#include "Station.h"
using namespace std;

#ifndef _RAILWAY_H
#define _RAILWAY_H
class Railway{
    private:
        string name = "Indian Railway";
        static const vector<Station> sStations;
        static const map<pair<Station,Station>, int> data;
    protected:
        Railway();
        ~Railway();
    public:
        static const Railway &IndianRailways();
        static int GetDistance(Station a,Station b);
};

#endif