cmake_minimum_required(VERSION 3.13)

project(Assignment3 CXX)

set(src
    Booking.cpp
    BookingClasses.cpp
    Application.cpp
    Passenger.cpp
    Railways.cpp
    Station.cpp
    Passenger.cpp
    Date.cpp
)

add_executable(Application
${src}
)