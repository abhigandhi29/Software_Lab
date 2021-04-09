#include "Name.h"


Name::Name(string firstName, string middleName,string lastName):firstName_(firstName),lastName_(lastName),middleName_(middleName){}
Name::~Name(){}
Name Name::GetInstance(string firstName, string middleName,string lastName){
    Bad_Passenger t;
    if(firstName=="")
        throw t;
    if(lastName=="")
        throw t;
    return Name(firstName,middleName,lastName);
}
string Name::GetName() const { return firstName_+middleName_+lastName_;}


ostream &operator<<(ostream &out, const Name &n){
    out<<n.GetName();
    return out;
}
Name::Name(const Name &n):firstName_(n.firstName_),middleName_(n.middleName_),lastName_(n.lastName_){}