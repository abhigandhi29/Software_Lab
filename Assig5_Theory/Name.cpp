//Abhishek Gandhi
//19CS10031
#include "Name.h"

Name::Name(string firstName, string middleName,string lastName):firstName_(firstName),lastName_(lastName),middleName_(middleName){}
Name::~Name(){}
Name Name::GetInstance(string firstName, string middleName,string lastName){
    BadPassengerName t;
    if(firstName=="" && lastName=="")
        throw t;
    return Name(firstName,middleName,lastName);
}
string Name::GetName() const { return firstName_+" "+middleName_+" "+lastName_;}


ostream &operator<<(ostream &out, const Name &n){
    out<<n.GetName();
    return out;
}
bool operator==(const Name &n1, const Name &n2){
    if(n1.GetName()==n2.GetName()){
        return true;
    }
    return false;
}
Name::Name(const Name &n):firstName_(n.firstName_),middleName_(n.middleName_),lastName_(n.lastName_){}