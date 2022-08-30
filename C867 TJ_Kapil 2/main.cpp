#include "roster.h" // to include methods from roster
using namespace std;
#include <iostream>

int main() {
  cout << "Course Title: C867\n"
       << "Language: C++\n"
       << "ID: 010102369\n"
       << "Name: TJ Kapil" << endl;
  cout << endl;
  // DATS TO BE PARSED
  const string studentData[] =

      {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,TJ,Kapil,kkapil@wgu.edu,24,19,50,58,SOFTWARE"};

  const int numStudents = 5; // create array with size 5
  Roster classRoster; // Create roster using default parameter less constructor,
                      // instance is classRoster
  // loop through number students
  for (int i = 0; i < numStudents; i++)
    classRoster.parse(studentData[i]); // parse the student data at index i as
                                       // we move thought for loop
  cout << "Displaying available student roster data: " << endl;
  classRoster.printAll(); // use the print all function to print all data of
                          // student roster from the parse method
  cout << endl;           // start a new line

  cout << "Displaying students in Software Program: " << endl;
  classRoster.printByDegreeProgram(SOFTWARE);
  cout << endl;
  // cast the integer to a Student Degree stype to
  // print strings of degree type

  cout << "Displaying emails that are invalid" << endl;
  classRoster.printInvalidEmails(); // call print invalid emails method on
                                    // classRoster object
  cout << endl;                     // start a new line

  // display average number of days to take courses
  // cout << "Displaying average days in course: " << endl;
  // classRoster.printAverageDaysInCourse(); // this is by student ID (ERROR)
  cout << "Display average days in course:" << endl;
  for (int i = 0; i < numStudents; i++) {
    classRoster.printAverageDaysInCourse(
        classRoster.classRosterArray[i]->getStudentId());
  }
  cout << endl;

  cout << "Removing student with ID A3" << endl;
  classRoster.remove("A3");
  cout << endl;

  cout << "Removing student with ID A3" << endl;
  classRoster.remove("A3");
  cout << endl;

  system("pause"); // holds the window up

  return 0;
};
