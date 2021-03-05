#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <map> 
using namespace std;

#ifndef _RAILWAY_H
#define _RAILWAY_H
class Railway{
    private:
        static const map<pair<string,string>, int> data;
        static Railway *obj;
        Railway(map<pair<string,string>, int> data);
    public:
        ~Railway();
        static const Railway &IndianRailways();
        //static int GetDistance(Station a,Station b);
};

#endif