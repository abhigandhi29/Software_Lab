//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "BookingClasses.h"
using namespace std;

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
    virtual double GetConcessionFactor(const BookingClasses &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::ACFirstClass &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::ACChairCar &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::AC2Tier &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::AC3Tier &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::SecondSitting &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::Sleeper &) const =0;
    //virtual double GetConcessionFactor(const BookingClasses::ExecutiveChairCar &) const =0;
    
};

template<typename T>
class DivyaangType{
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
    inline double GetConcessionFactor(const BookingClasses::FirstClass &) const{
        return sFirstClassConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::ACFirstClass &) const{
        return sACFirstClassConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::ACChairCar &) const{
        return sACChairCarConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::AC2Tier &) const{
        return sAC2TierConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::AC3Tier &) const{
        return sAC3TierConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::SecondSitting &) const{
        return sSecondSittingConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::Sleeper &) const{
        return sSleeperConcession;
    }
    inline double GetConcessionFactor(const BookingClasses::ExecutiveChairCar &) const{
        return sExecutiveChairCarConcession;
    }  
    static const DivyaangType<T>& Type(){
        static const DivyaangType<T> obj;
        return obj;
    }
};

#endif