//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "BookingClasses.h"
#include "Passenger.h"
#include "Divyaang.h"
#include "Exception.h"
using namespace std;
#ifndef _CONCESSION_H
#define _CONCESSION_H

class Concession{
protected:
    Concession();
public:
    ~Concession();
    string type;
    friend ostream &operator<<(ostream &, const Concession &);
    virtual inline double GetConcessionFactor() const{
        return 0;
    }
};

class DivyaangConcession : public Concession{
    DivyaangConcession();
public:
    ~DivyaangConcession();
    double GetConcessionFactor(Passenger &p,BookingClasses &b) const;
    static const DivyaangConcession &Type();
};
class LadiesConcession : public Concession{
    LadiesConcession();
    static double sConcessioFactor;
public:
    ~LadiesConcession();
    double GetConcessionFactor(Passenger &p) const;
    static const LadiesConcession &Type();
};

class SeniorCitizenConcession : public Concession{
    SeniorCitizenConcession();
public:
    ~SeniorCitizenConcession();
    double GetConcessionFactor(Passenger &p) const;
    static const SeniorCitizenConcession &Type();
};

class GeneralConcession : public Concession{
    GeneralConcession();
public:
    ~GeneralConcession();
    static const GeneralConcession &Type();

};

#endif