#include "Station.h"

int Station::GetDistance(string other) const{
    return -1;
}
ostream &operator<<(ostream &out, const Station &s){
    out<<"Station: "<<s.name_<<endl;
    return out;
}

int main(){
    return 1;
}