#include "Station.h"

int Station::GetDistance(string other) const{
    return -1;
}
ostream &operator<<(ostream &out, const Station &s){
    out<<s.name_;
    return out;
}
bool operator==(const Station &s1, const Station &s2){
    if(s1.name_==s2.name_){
        return true;
    }
    return false;
}

