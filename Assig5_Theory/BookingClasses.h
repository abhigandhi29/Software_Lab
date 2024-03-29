///Abhishek Gandhi
//19CS10031
#include <iostream>
#include "Exception.h"
using namespace std;
#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H
#include "Divyaang.h"

//class Divyaang;

template<typename T>
class BookingClassesTypes;

class BookingClasses{
    private:
        struct ACFirstClassType{};
        struct ExecutiveChairCarType{};
        struct AC2TireType{};
        struct SleeperType{};
        struct SecondSittingType{};
        struct FirstClassType{};
        struct AC3TireType{};
        struct ACChairCarType{};
        
    protected:
        BookingClasses &operator=(const BookingClasses &);
        BookingClasses();
        BookingClasses(const BookingClasses &);
        virtual ~BookingClasses();
    public:
        virtual string GetName() const = 0;
        virtual bool IsAC() const = 0;
        virtual bool IsLuxury() const = 0;
        virtual double LoadFactor() const = 0;
        virtual bool IsSitting() const = 0;
        virtual int GetNumberOfTires() const = 0;
        virtual double MinTatkaalDistance() const = 0;
        virtual double MinTatkaalChange() const = 0;
        virtual double MaxTatkaalCharge() const = 0;
        virtual double TatkaalLoadFactor() const = 0;
        virtual double ReservationCharge() const = 0;
        friend ostream &operator<<(ostream &, const BookingClasses &);
        typedef BookingClassesTypes<ACFirstClassType> ACFirstClass; 
        typedef BookingClassesTypes<ExecutiveChairCarType> ExecutiveChairCar;
        typedef BookingClassesTypes<AC2TireType> AC2Tier;
        typedef BookingClassesTypes<SleeperType> Sleeper;
        typedef BookingClassesTypes<AC3TireType> AC3Tier;
        typedef BookingClassesTypes<ACChairCarType> ACChairCar;
        typedef BookingClassesTypes<SecondSittingType> SecondSitting;
        typedef BookingClassesTypes<FirstClassType> FirstClass;
        //template<> virtual const BookingClassesTypes<> &GetType() = 0;
        //virtual double getConcessionDivyaang(Divyaang &c) const = 0;
        //template<typename T> 
        //BookingClassesTypes<T> temp; 
        virtual double GetDivyaangConcession(Divyaang &) const = 0;
};

template<typename T>
class BookingClassesTypes : public BookingClasses{
    BookingClassesTypes(){}
    static const string sName;
    static const bool sIsAC;
    static const int sNumberOfTires;
    static bool sIsLuxury;
    static double sLoadFactor;
    static double sTatkalLoadFactor;
    static double sMinTatkaalCharge;
    static double sMaxTatkaalCharge;
    static double sMinTatkaalDistance;
    static const bool sIsSitting;
    static double sReservationCharge;
public:
    ~BookingClassesTypes(){}
    double GetDivyaangConcession(Divyaang &) const;
    static const BookingClassesTypes &Type(){
        static const BookingClassesTypes obj;
        return obj;
    }
    //const BookingClassesTypes &GetType(){
    //    return Type();
    //}
    //double GetConcessionDivyaang(Divyaang &c) const{
    //    return c.GetConcessionFactor(*this);
    //}
    inline string GetName() const{
        return sName;
    }
    inline bool IsAC() const{
        return sIsAC;
    }
    inline bool IsLuxury() const{
        return sIsLuxury;
    }
    inline double LoadFactor() const{
        return sLoadFactor;
    }
    inline bool IsSitting() const{
        return sIsSitting;
    }
    inline int GetNumberOfTires() const{
        return sNumberOfTires;
    }
    inline double MinTatkaalDistance() const{
        return sMinTatkaalDistance;
    }
    inline double MinTatkaalChange() const{
        return sMinTatkaalCharge;
    }
    inline double MaxTatkaalCharge() const{
        return sMaxTatkaalCharge;
    }
    inline double TatkaalLoadFactor() const{
        return sTatkalLoadFactor;
    }
    inline double ReservationCharge() const{
        return sReservationCharge;
    }
};


#endif