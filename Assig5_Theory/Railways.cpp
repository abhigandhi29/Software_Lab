//Abhishek Gandhi
//19CS10031
#include "Railway.h"
#include <map>


Railway::Railway(){}
Railway::~Railway(){}
const Railway &Railway::IndianRailways(){
    
    try{
        VerifyData();
    }
    catch(...){        
        throw;
    }
    static Railway sIndianRailways;
    return sIndianRailways;
}
int Railway::GetDistance(const Station &a,const Station &b){
    BadBookingStation t;
    if(a==b)
        throw t;
    vector<pair<pair<Station,Station>,int>>::const_iterator itr;
    for(itr=sDistStation.begin();itr!=sDistStation.end();++itr){
        if((itr->first.first==a &&  itr->first.second==b) ||
            (itr->first.second==a && itr->first.first==b)){
            return itr->second;
        }
    }
    throw t;
    return 0;
}
ostream &operator<<(ostream &out,const Railway &r){
    out<<r.name_<<endl;
    out<<"Name of Stations: "<<endl;
    for(int i=0;i<r.sStations.size();i++)
        out<<"\t-"<<r.sStations[i]<<endl;
    out<<endl;
    out<<"Distances: ";
    vector<pair<pair<Station,Station>,int>>::const_iterator itr;
    for(itr=r.sDistStation.begin();itr!=r.sDistStation.end();++itr)
        out<<endl<<"\t-"<<itr->first.first<<"<--->"<<itr->first.second<<"-->"<<itr->second;
    return out;
}

bool Railway::VerifyData(){
    map<string,int> m;
    vector<Station>::const_iterator itr;
    for(itr=sStations.begin();itr!=sStations.end();itr++){
        if(m.count(itr->GetName())==1){
            BadRailwaysDuplicate t;
            throw t;
        }
        m[itr->GetName()] = 1;
    }
    map<pair<string,string>,int> m2;
    vector<pair<pair<Station,Station>,int>>::const_iterator itr2;
    for(itr2=sDistStation.begin();itr2!=sDistStation.end();++itr2){
        if(m2.count(make_pair(itr2->first.first.GetName(),itr2->first.second.GetName()))==1){
            BadRailwaysDuplicate t;
            throw t;
        }
        if(m2.count(make_pair(itr2->first.second.GetName(),itr2->first.first.GetName()))==1){
            BadRailwaysDuplicate t;
            throw t;
        }
        m2[make_pair(itr2->first.first.GetName(),itr2->first.second.GetName())] = 1;
        m2[make_pair(itr2->first.second.GetName(),itr2->first.first.GetName())] = 1;
    }
    return true;
}
