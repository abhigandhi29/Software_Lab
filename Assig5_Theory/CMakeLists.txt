cmake_minimum_required(VERSION 3.13)

project(Assignment3 CXX)

set(src
    Booking.cpp
    BookingClasses.cpp
    Application.cpp
    Passenger.cpp
    Railway.cpp
    Station.cpp
    Passenger.cpp
    Date.cpp
    Concession.cpp
    Date.cpp
    Gender.cpp
    Divyaang.cpp
    Name.cpp
    Exception.cpp
)

add_executable(Application
${src}
)