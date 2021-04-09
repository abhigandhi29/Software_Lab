//Abhishek Gandhi
//19CS10031
#include "Station.h"
#include "Railway.h"

int Station::GetDistance(Station &other) const{
    return Railway::GetDistance(*this,other);
}
Station::Station(string name):name_(name){}
Station::Station(const Station &s):name_(s.GetName()){}
ostream &operator<<(ostream &out, const Station &s){
    //cout<<s.name_<<endl;
    out<<s.GetName();
    return out;
}
bool operator==(const Station &s1, const Station &s2){
    if(s1.name_==s2.name_){
        return true;
    }
    return false;
}
Station Station::GetInstance(string name) const{
    Bad_Station t;
    if(name=="")
        throw t;
    return Station(name);

}

