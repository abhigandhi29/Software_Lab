#include "Gender.h"

Gender::Gender(){}
Gender::~Gender(){}

template<> double Gender::Male::sSeniorCitizenConsessionFactor =  0.4;
template<> double Gender::Female::sSeniorCitizenConsessionFactor =  0.5;

template<> int Gender::Male::sConcessionAge = 60;
template<> int Gender::Female::sConcessionAge = 58;

template<> string Gender::Male::sTitle = "Mr";
template<> string Gender::Female::sTitle = "Mrs";
