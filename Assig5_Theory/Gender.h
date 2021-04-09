//Abhishek Gandhi
//19CS10031
#include<iostream>
#include <cstddef>
#include <iostream> 
#include <iterator> 
#include <unordered_map> 
#include <vector>
#include "Exception.h"
//#include "Station.h"
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
    virtual int GetConcessionAge() const = 0;
    virtual string GetTitle() const = 0;
    virtual string GetType() const = 0;
    //virtual string sTitle = 0;
    //virtual string Typename = 0;
    friend ostream &operator<<(ostream &, const Gender &);
    friend bool operator==(const Gender &, const Gender &);
};

template<typename T>
class GenderType : public Gender{
    static double sSeniorCitizenConsessionFactor;
    static int sConcessionAge;
    static string sTitle;
    static string Typename;
    GenderType(){}
    
public:
    ~GenderType(){}
    inline double GetSeniorCitizenCon() const{
        return sSeniorCitizenConsessionFactor;
    }
    inline int GetConcessionAge()  const{
        return sConcessionAge;
    }
    inline string GetTitle() const{
        return sTitle;
    }
    inline string GetType() const{
        return Typename;
    }
    static const GenderType& Type(){
        static const GenderType obj;
        return obj;
    }
    

};

#endif