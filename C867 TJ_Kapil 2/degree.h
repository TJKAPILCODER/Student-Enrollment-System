#ifndef degree_h
#define degree_h
#pragma once // causes current source file to be included only once in a single
             // compilation.
#include <string>    // used for variable that have a string data type
using namespace std; // so we don't need to use std::
// Define an enumerated data type DegreeProgram for the degree programs
// containing the data type values SECURITY, NETWORK, and SOFTWARE. This
// DegreeProgram enumerator is used as an index, starting from 0 up till 2.
// These are like lables for the different integers indexes. This would be for
// the programmers benefit.
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };
// for each Degreeprogram type number/index you have a string that comes out,
// using the degreeProgramStrings Array data type.
// static determines visibility outside a function. const means we declared a
// constant variale that can not be modifield after it has been intialized.
static const string degreeProgramTypes[] = {
    "SECURITY", "NETWORK", "SOFTWARE"}; // index {0, 1, 2} // instead of numbers we can put in the
                  // enum types to get a string type.
// for example: degreeProgramTypes[SOFTWARE] would give us "SOFTWARe" the
// string.
#endif
