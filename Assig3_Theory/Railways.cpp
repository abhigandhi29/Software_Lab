#include "Railway.h"

vector<Station> Railway::sStations{
    Station("Mumbai"),
    Station("Delhi"),
    Station("Banglore"),
    Station("Kolkata"),
    Station("Chennai")
};
vector<pair<pair<Station,Station>,int>> Railway::sDistStation{
    {{Station("Mumbai"),Station("Delhi")},1447},
    {{Station("Mumbai"),Station("Banglore")},981},
    {{Station("Mumbai"),Station("Kolkata")},2014},
    {{Station("Mumbai"),Station("Chennai")},1338},
    {{Station("Banglore"),Station("Delhi")},2150},
    {{Station("Kolkata"),Station("Delhi")},1472},
    {{Station("Chennai"),Station("Delhi")},2180},
    {{Station("Banglore"),Station("Kolkata")},1871},
    {{Station("Banglore"),Station("Chennai")},350},
    {{Station("Kolkata"),Station("Chennai")},1659}
};
Railway *Railway::sIndianRailways = NULL;
Railway::Railway(){}
Railway::~Railway(){}
const Railway &Railway::IndianRailways(){
    if(!sIndianRailways){
        sIndianRailways = new Railway();
    }
    return *sIndianRailways;
}
int Railway::GetDistance(const Station &a,const Station &b){
    vector<pair<pair<Station,Station>,int>>::const_iterator itr;
    for(itr=sDistStation.begin();itr!=sDistStation.end();++itr){
        if((itr->first.first==a &&  itr->first.second==b) ||
            (itr->first.second==a && itr->first.first==b)){
            return itr->second;
        }
    }
    return 0;
}

