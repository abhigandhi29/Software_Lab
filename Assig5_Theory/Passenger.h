//Abhishek Gandhi
//19CS10031
#include<iostream>
#include "Date.h"
using namespace std;

#ifndef _PASSENGER_H
#define _PASSENGER_H

class Passenger{
    private:
        const string name_,aadhar_,gender_,number_;
        const Date dob_;
        Passenger(const Passenger &); 
    public:
        Passenger(string name, string aadhar, string gender, Date dob, string number="");
        ~Passenger();
        friend ostream &operator<<(ostream &, const Passenger &);
        inline string GetName() const{
            return name_;
        }
        inline string GetGender() const{
            return gender_;
        }
        inline string GetNumber() const{
            return number_;
        }
        virtual inline string GetCategory() const = 0;
        inline Date GetBOD() const{
            return dob_;
        }

};
class General : public Passenger{
    private:
        static const string sCategory;
    public:
        General(string name, string aadhar, string gender, Date dob, string number="");
        ~General();
        inline string GetCategory() const{
            return sCategory;
        }

};
class Ladies: public Passenger{
    private:
        static const string sCategory;
    public:
        Ladies(string name, string aadhar, string gender, Date dob, string number="");
        ~Ladies();
        inline string GetCategory() const{
            return sCategory;
        }
};
class Senior_Citizen: public Passenger{
    private:
        static const string sCategory;
    public:
        Senior_Citizen(string name, string aadhar, string gender, Date dob, string number="");
        ~Senior_Citizen();
        inline string GetCategory() const{
            return sCategory;
        }
};
class Divyaang: public Passenger{
    private:
        static const string sCategory;
    public:
        Divyaang(string name, string aadhar, string gender, Date dob, string number="");
        ~Divyaang();
        inline string GetCategory() const{
            return sCategory;
        }
};
class Tatkal: public Passenger{
    private:
        static const string sCategory;
    public:
        Tatkal(string name, string aadhar, string gender, Date dob, string number="");
        ~Tatkal();
        inline string GetCategory() const{
            return sCategory;
        }
};
class Premium_Tatkal: public Passenger{
    private:
        static const string sCategory;
    public:
        Premium_Tatkal(string name, string aadhar, string gender, Date dob, string number="");
        ~Premium_Tatkal();
        inline string GetCategory() const{
            return sCategory;
        }
};

#endif