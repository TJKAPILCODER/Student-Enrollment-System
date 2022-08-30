#pragma once // used on header files
#include "student.h"
#ifndef roster_h
#define roster_h // to use functions declared
// Array of pointers to hold the data provded in the studentData Table.
class Roster {
  public:
    int endIndex = -1; // in an array the last index would be -1, next would be -2 and so on
    const static int numStudents = 5; // in total there are 5 students, last student is me.
    Student* classRosterArray[numStudents]; // array using pointer with memory allocated for 5 students

  public:
    void parse(string line); // parse fuction for the first row of the student data table, which is a long string seprated by commas.
    // after data has been taken out by parse function, it will be passed into the add function, which will create a student object

    void add(string studentID, // sets the instance variables from student class and updates the roster and creates student objects
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeprogram);

    void remove(string studentID); // removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

    void printAll(); // prints a complete tab-separated list of student data // DONE

    void printAverageDaysInCourse(string studentID); // prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    // A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    void printInvalidEmails(); // verifies student email addresses and displays all invalid email addresses to the user. // DONE

    void printByDegreeProgram(DegreeProgram degreeProgram); // prints out student information for a degree program specified by an enumerated type. // DONE

    // Destructor to deallocate memory
    ~Roster();
};

#endif
