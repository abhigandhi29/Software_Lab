#include <iostream>
#include <exception>
using namespace std;

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

class Bad_Date : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Invalid Date Provided\n";  
        }  
};  

class Bad_Railways : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Invalid Input for railway class\n";  
        }  
};  

class Bad_Passenger : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Invalid Data Provided\n";  
        }  
};  

class Bad_Booking : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Invalid Category! Error in booking\n";  
        }  
};  

class Bad_Station : public exception{  
    public:  
        const char * what() const throw()  
        {  
            return "Invalid Station Name!\n";  
        }  
};  


#endif