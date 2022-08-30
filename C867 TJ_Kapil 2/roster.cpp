#include "roster.h"

void Roster::parse(
    string studentData) { // Call parse function from roster.h, this will take
                          // in studentData string row as paramter
  // DegreeProgram degreeprogram = UNDECIDED; // this will set the default value
  // of the degree program to undecided
  /* STUDENT ID */
  // First we will find the location of the first comma in the studentData
  // string and store the index in comma searcher variable
  int rhs = studentData.find(",");
  // We will use the index to extract the subtract from 0 till the one before
  // the comma.
  string sID = studentData.substr(0, rhs); // store student id
  // We will then move past the first comma by adding to the commaSearcher
  // variable which stores index.
  /* FIRST NAME */
  int lhs = rhs + 1;
  // look for second comma starting startting from the new index where
  // commaSearcher 2 is.
  rhs = studentData.find(",", lhs);
  // extract the substring between the two commas, comma searcher and
  // commasearcher 2
  string sFirstName = studentData.substr(lhs, rhs - lhs); // store first name
  /* LAST NAME */
  // then we move on to the next comma in the string row
  lhs = rhs + 1; // move 1 forward
  rhs = studentData.find(",", lhs);
  string sLastName = studentData.substr(lhs, rhs - lhs); // store last name
  /* EMAIL */
  lhs = rhs + 1; // move forward by 1
  rhs = studentData.find(",", lhs);
  string sEmail = studentData.substr(lhs, rhs - lhs); // store email
                                                      /* AGE */
  lhs = rhs + 1;                                      // move forward by 1
  rhs = studentData.find(",", lhs);
  int sAge = stoi(studentData.substr(lhs, rhs - lhs)); // store age
  /* sDIC1 */
  lhs = rhs + 1; // move forward by 1
  rhs = studentData.find(",", lhs);
  int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs)); // store sDIC1
  /* sDIC2 */
  lhs = rhs + 1; // move forward by 1
  rhs = studentData.find(",", lhs);
  int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs)); // store sDIC2
  /* sDIC3 */
  lhs = rhs + 1; // move forward by 1
  rhs = studentData.find(",", lhs);
  int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs)); // store sDIC3
  lhs = rhs + 1;
  rhs = studentData.find(",", lhs);
  /* DEGREE PROGRAM */
  DegreeProgram dp;

  if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E')
    dp = SECURITY;
  else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O')
    dp = SOFTWARE;
  else if (studentData.at(lhs) == 'N')
    dp = NETWORK; // store DEGREE PROGRAM
  // sets the instance variables from student class and updates the roster and
  // creates student objects
  add(sID, sFirstName, sLastName, sEmail, sAge, daysInCourse1, daysInCourse2, daysInCourse3, dp);
};

// NOW THAT WE HAVE OUT DIFFERENT SUBSTRING IN VARIABLES WE NEED TO CONVERT THEM
// INTO OBJECTS
void Roster::add(
    string studentID, // sets the instance variables from student class and
                      // updates the roster and creates student objects
    string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3,
    DegreeProgram degreeprogram) {

  // array to store the days in coure
  int darr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

  // Now we will make the Student repository using the Student constructor
  // the student onformation will start at -1 and go till it hits 0 on the left,
  // so from right to left
  classRosterArray[++endIndex] = new Student(
      studentID, firstName, lastName, emailAddress, age, darr, degreeprogram);
};
// // prints a complete tab-separated list of student data
void Roster::printAll() {
  Student::printHeaderTop(); // This will print a header on top to keep things
                             // organized
  for (int i = 0; i <= Roster::endIndex; i++) Roster::classRosterArray[i]->printData();
}
// print degree program based on what is passed into paramter
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
  Student::printHeaderTop(); // print head on top, to organize
  for (int i = 0; i <= Roster::endIndex;
       i++) { // go through roster array print that which matches with degree
              // program written in paramter
    if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
      classRosterArray[i]
          ->printData(); // use printdata method from Student Class
  }
  cout << endl; // start a new line at end of for loop
};

// Each Student email must contain an "@" symbol and an "." It must not caintain
// any spaces " "
void Roster::printInvalidEmails() { // print emails not written with correct
                                    // format boolean set to false at first if
                                    // invalid email then it becomes true
  bool invalidEmail = false;        // assume no invalid emails at the start
  for (int i = 0; i < Roster::endIndex; i++) {
    string sEmail = (classRosterArray[i]
                         ->getEmailAddress()); // get email using getter method
                                               // and store in sEmail variable
    // if we get all the way to string::npos that means we did not find an '@'
    // in it.
    if (sEmail.find('@') == string::npos || sEmail.find('.') == string::npos ||
        sEmail.find(' ') != string::npos) {
      invalidEmail = true;
      cout << "Email"
           << ": " << classRosterArray[i]->getEmailAddress()
           << endl; // if we find an invalid email, print this
    }
  }
  if (!invalidEmail)
    cout << "NONE" << endl; // if no invalid emails find, then print NONE
};

void Roster::printAverageDaysInCourse(
    string studentID) { // student identified by studentID paramater
  for (int i = 0; i <= Roster::endIndex; i++) {
    if (classRosterArray[i]->getStudentId() == studentID) {
      cout << studentID << ":";
      cout << (classRosterArray[i]->getDays()[0] +
                  classRosterArray[i]->getDays()[1] +
                  classRosterArray[i]->getDays()[2]) / 3
           << endl; // add them up and divide by 3 for average
    }
  }
};

void Roster::remove(
    string studentID) { // remove student from roster by student id, if student
                        // doesn't exit, pritn error student not found
  bool done = false;    // assume student is not there in beginning
  for (int i = 0; i <= Roster::endIndex; i++) {
    if (classRosterArray[i]->getStudentId() == studentID) {
      // if there
      done = true;               // STUDENT WAS FOUND IN ROSTER
      if (i < numStudents - 1) { // if we are not less than then there only 1
                                 // student, less than indicates we did not make
                                 // it to the end and found student
        Student *tempStudent =
            classRosterArray[i]; // hold that student in temp variable // to
                                 // swap with last student
        classRosterArray[i] =
            classRosterArray[numStudents - 1]; // swap it with last book
        classRosterArray[numStudents - 1] =
            tempStudent; // in the last student place store the student, that we
                         // want to remove
      }
      Roster::endIndex--; // this will make the student that we swappted to the
                          // end to be not visible
    }
  }
  if (done) {
    cout << "student " << studentID << " removed from student roster." << endl
         << endl; // if done was true, then we removed the student print message
    this->printAll(); // this would print all of the students in the roster
                      // except for the one that was removed from the roster
  } else {
    cout << "Error: Student " << studentID << " not found in roster." << endl
         << endl; // not found print error
  }
};

Roster::~Roster() { // STUDENTS ARE DYNAMICALLY ALLOCATED IN PROGRAM, NOW MUST
                    // BE REMOVED
  cout << "Destructor called to deallocate memory taken up by student roster"
       << endl;
  // loop through all of the roster elements
  for (int i = 0; i < numStudents; i++) {
    cout << "Student # " << i + 1 << " destroyed!" << endl;
    delete classRosterArray[i]; // we delete the memory at classrosterarray[i]
    classRosterArray[i] =
        nullptr; // we make that memory point to nothing no address
  }
};
