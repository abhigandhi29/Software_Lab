#include <iostream>
#include <exception>
using namespace std;

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

class BadDate : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Date Provided\n";  
        }  
};  

class BadRailwaysDuplicate : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Reapeating station name!\n";  
        }  
};
class BadRailwaysDistance : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Distance Matrix!\n";  
        }  
};    

class BadPassengerDate : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Bod Provided! Birth date must be less than Todays date\n";  
        }  
};  
class BadPassengerName : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Name provided! Both surname and firstname cannot be empty\n";  
        }  
};  

//class BadPassenger : public exception{  
//    public:  
//        const char * what() const throw()  {  
//            return "Invalid Data Provided\n";  
//        }  
//};  

class BadPassengerAddhar : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Aadhar number!\n";  
        }  
};  

class BadPassengerMobile : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Mobile Number Provided!\n";  
        }  
};  

class BadPassengerDisabilityID : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Disability ID Provided!\n";  
        }  
};  

class BadStation : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Station Name!\n";  
        }  
};  

class BadBookingStation : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid station name or Distance not found!\n";  
        }  
};  

class BadBookingReservation : public exception{   
    public:  
        const char * what() const throw()  {  
            return "Invalid Reservation Date!\n";  
        }  
};  

class BadBookingCategory : public exception{  
    public:  
        const char * what() const throw()  {  
            return "Invalid Category provided! Choose a valid category\n";  
        }  
};
 






#endif