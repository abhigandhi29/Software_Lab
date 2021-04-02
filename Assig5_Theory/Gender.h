//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "Station.h"
using namespace std;

#ifndef _GENDER_H
#define _GENDER_H

template<typename T>
class GenderType;

class Gender{
    struct MaleType{};
    struct FemaleType{};
protected:
    Gender();
    virtual ~Gender();
public:
    typedef GenderType<MaleType> Male;
    typedef GenderType<FemaleType> Female;
    virtual double GetSeniorCitizenCon() const = 0;
    virtual  int getConcessionAge() const = 0;
};

template<typename T>
class GenderType : public Gender{
    static double sSeniorCitizenConsessionFactor;
    static int sConcessionAge;
    static string sTitle;
    GenderType(){}
    ~GenderType(){}
public:
    inline double getSeniorCitizenCon() const{
        return sSeniorCitizenConsessionFactor;
    }
    inline double getConcessionAge()  const{
        return sConcessionAge;
    }
    inline string GetTitle() const{
        return sTitle;
    }
    static const GenderType<T>& Type(){
        static const GenderType<T> obj;
        return obj;
    }

};

#endif