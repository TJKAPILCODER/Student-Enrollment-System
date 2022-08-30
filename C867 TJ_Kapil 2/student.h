#ifndef student_h
#define student_h
#pragma once // causes current source file to be included only once in a single compilation.
#include <iostream>
#include <iomanip> // library which helps in manipulating the output
#include "degree.h" // to use degree program enumerator and strings that correlate with enumerators. (local file in project)
using namespace std;
 // to use cout without std::

//  class student
class Student {
  // variable for array size
  public:
    const static int daysArraySize = 3;
  private: // nothing can touch it except the object itself
    string studentID; // variable for student id
    string firstName; // variable for firstname
    string lastName; // variable for last name
    string emailAddress; // variable for email address
    int days[daysArraySize]; // array days variable with number of days
    int age; // variable for age
    DegreeProgram degreeProgram; // variable for degree programs, give type names capital letters in front.
  public: // public section to contain methods
    Student(); // parameterless constructor - this will set the default values, I should always have this in programs.
    Student(string studentID, string firstName, string lastName,  string emailAddress, int age, int days[], DegreeProgram degreeProgram); // Constructor (all input parameters from table)
    ~Student(); // Destructor to destroy allocated memory also known as deallocation

    // GETTERS ARE ALSO KNOWN AS ACCESSOR for all instance variables declared above. // GETTERS
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays(); // array name is a pointer that is constant, it can not be changed.
    DegreeProgram getDegreeProgram();

    // SETTERS for all instance variables declared above. // SETTERS
    void setStudentId(string newID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setEmailAddress(string newEmail);
    void setAge(int newAge);
    void setDays(int days[]);
    void setDegreeTypes(DegreeProgram dp);

    static void printHeaderTop(); // This is so when the data is printed, it is clear where it starts, which would be after the header

    void printData(); // This function is to display/print specific student data.

};

#endif
