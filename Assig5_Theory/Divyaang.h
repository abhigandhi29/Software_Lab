//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "Exception.h"
//#include "BookingClasses.h"
using namespace std;

//class BookingClasses;

#ifndef _DIVYAANG_H
#define _DIVYAANG_H

template<typename T>
class DivyaangType;

class Divyaang{
    struct BlindType{};
    struct OrthopaedicallyHandicappedType{};
    struct CancerPatientsType{};
    struct TBPatientsType{};
protected:
    Divyaang();
    virtual ~Divyaang();
public:
    typedef DivyaangType<BlindType> Blind;
    typedef DivyaangType<OrthopaedicallyHandicappedType> OrthopaedicallyHandicapped;
    typedef DivyaangType<CancerPatientsType> CancerPatients;
    typedef DivyaangType<TBPatientsType> TBPatients;
    //virtual double GetConcessionFactor(const BookingClasses &) const =0;
    virtual double GetConcessionFactorACFirstClass() const =0;
    virtual double GetConcessionFactorFirstClass() const = 0;
    virtual double GetConcessionFactorSecondSitting() const = 0;
    virtual double GetConcessionFactorSleeper() const = 0;
    virtual double GetConcessionFactorACChairCar() const = 0;
    virtual double GetConcessionFactorAC2Tire() const = 0;
    virtual double GetConcessionFactorAC3Tier() const = 0;
    virtual double GetConcessionFactorExecutiveChairCar() const = 0;
    
};

template<typename T>
class DivyaangType : public Divyaang{
    static const string sName;
    static double sACFirstClassConcession;
    static double sExecutiveChairCarConcession;
    static double sAC2TierConcession;
    static double sAC3TierConcession;
    static double sACChairCarConcession;
    static double sSleeperConcession;
    static double sSecondSittingConcession;
    static double sFirstClassConcession;
    DivyaangType(){}
    ~DivyaangType(){}
public:
    inline double GetConcessionFactorFirstClass() const{
        return sFirstClassConcession;
    }
    inline double GetConcessionFactorACFirstClass() const{
        return sACFirstClassConcession;
    }
    inline double GetConcessionFactorACChairCar() const{
        return sACChairCarConcession;
    }
    inline double GetConcessionFactorAC2Tire() const{
        return sAC2TierConcession;
    }
    inline double GetConcessionFactorAC3Tier() const{
        return sAC3TierConcession;
    }
    inline double GetConcessionFactorSecondSitting() const{
        return sSecondSittingConcession;
    }
    inline double GetConcessionFactorSleeper() const{
        return sSleeperConcession;
    }
    inline double GetConcessionFactorExecutiveChairCar() const{
        return sExecutiveChairCarConcession;
    }  
    static const DivyaangType& Type(){
        static const DivyaangType obj;
        return obj;
    }
};

#endif