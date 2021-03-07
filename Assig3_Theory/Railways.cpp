#include "Railway.h"

vector<Station> Railway::sStations{
    Station("Mumbai"),
    Station("Delhi"),
    Station("Bangalore"),
    Station("Kolkata"),
    Station("Chennai")
};
vector<pair<pair<Station,Station>,int>> Railway::sDistStation{
    {{Station("Mumbai"),Station("Delhi")},1447},
    {{Station("Mumbai"),Station("Bangalore")},981},
    {{Station("Mumbai"),Station("Kolkata")},2014},
    {{Station("Mumbai"),Station("Chennai")},1338},
    {{Station("Bangalore"),Station("Delhi")},2150},
    {{Station("Kolkata"),Station("Delhi")},1472},
    {{Station("Chennai"),Station("Delhi")},2180},
    {{Station("Bangalore"),Station("Kolkata")},1871},
    {{Station("Bangalore"),Station("Chennai")},350},
    {{Station("Kolkata"),Station("Chennai")},1659}
};
Railway::Railway(){}
Railway::~Railway(){}
const Railway &Railway::IndianRailways(){
    static Railway sIndianRailways;
    return sIndianRailways;
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
ostream &operator<<(ostream &out,const Railway &r){
    out<<r.name_<<endl;
    out<<"Name of Stations: "<<endl;
    for(int i=0;i<r.sStations.size();i++)
        out<<"\t-"<<r.sStations[i]<<endl;
    out<<endl;
    out<<"Distances: ";
    for(int i=0;i<r.sDistStation.size();i++)
        out<<endl<<"\t-"<<r.sDistStation[i].first.first<<"<--->"<<r.sDistStation[i].first.second<<"-->"<<r.sDistStation[i].second;
    return out;
}
