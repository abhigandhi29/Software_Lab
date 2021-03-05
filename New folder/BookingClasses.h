#include <iostream>
using namespace std;

#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

class BookingClasses{
    private:
        const string &name_;
        const bool &isAC_;
        BookingClasses &operator=(const BookingClasses &);
    protected:
        BookingClasses(const string &,const bool &);
        BookingClasses(const BookingClasses &);
        virtual ~BookingClasses();
    public:
        virtual inline string GetName() const{
            return name_;
        }
        virtual inline bool IsAC() const{
            return isAC_;
        }
        virtual inline bool IsLuxury() const=0;
        virtual inline double LoadFactor() const =0;
        virtual inline bool IsSitting() const =0;
        virtual inline int GetNumberOfTires() const = 0;
        friend ostream &operator<<(ostream &, const BookingClasses &);

};

class BerthClass: public BookingClasses{
    protected:
        BerthClass(const string &, const bool &);
        ~BerthClass();
    public:
        inline bool IsSitting() const{
            return false;
        }
        
        
};

class SittingClass : public BookingClasses{
 
    protected:
        SittingClass(const string &, const bool &);
        ~SittingClass();
    public:
        inline bool IsSitting() const{
            return true;
        }
        inline int GetNumberOfTires() const{
            return 0;
        }
        virtual inline bool IsLuxury() const=0;
        virtual inline double LoadFactor() const =0;
};

class Tire2 : public BerthClass{
    protected:
        Tire2(const string &, const bool &);
        ~Tire2();
    public:
        inline int GetNumberOfTires() const{
            return 2;
        }

};

class Tire3 : public BerthClass{
    protected:
        Tire3(const string &, const bool &);
        ~Tire3();
    public:
        inline int GetNumberOfTires() const{
            return 3;
        }

};

class Tire1 : public BerthClass{
    protected:
        Tire1(const string &, const bool &);
        ~Tire1();
    public:
        inline int GetNumberOfTires() const{
            return 1;
        }
};

class Sleeper : public Tire3{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        Sleeper(const string &, const bool &);
        ~Sleeper();
    public:
        static const Sleeper &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }
        
};


class AC3Tire : public Tire3{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        AC3Tire(const string &, const bool &);
        ~AC3Tire();
    public:
        static const AC3Tire &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }
};


class AC2Tire : public Tire2{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        AC2Tire(const string &, const bool &);
        ~AC2Tire();
    public:
        static const AC2Tire &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }
};


class ACFirstClass : public Tire1{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        ACFirstClass(const string &, const bool &);
        ~ACFirstClass();
    public:
        static const ACFirstClass &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }
};

class FirstClass : public Tire2{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        FirstClass(const string &, const bool &);
        ~FirstClass();
    public:
        static const FirstClass &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }

};

class SecondSitting : public SittingClass{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        SecondSitting(const string &, const bool &);
        ~SecondSitting();
    public:
        static const SecondSitting &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }

};

class ACChairCar : public SittingClass{
    private:
        static const double &sLoadfactor;
        static const bool &sisLuxury;
    private:
        ACChairCar(const string &, const bool &);
        ~ACChairCar();
    public:
        static const ACChairCar &Type();
        inline bool IsLuxury() const{
            return sisLuxury;
        }
        inline double LoadFactor() const{
            return sLoadfactor;
        }
};


#endif