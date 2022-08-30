#include "student.h" // so we can use to functions that have been declared

Student::Student() { // So that outside of the Student class we can use the student constructor function and sets it default valies.
  this->studentID = ""; // set to a empty string intially
  this->firstName = ""; // set to a empty string intially
  this->lastName = ""; // set to a empty string intially
  this->emailAddress = ""; // set to a empty string intially
  for (int i = 0; i < daysArraySize; i++) this ->days[i] = 0; // each part of array at index 0, 1, 2 is set to 0
  this->age = 0; // set age intially to 0
  this->degreeProgram = DegreeProgram::SECURITY; // SET DEGREE PROGRAM UNTIALLY TO UNDECIDED
}

Student::Student(string studentID, string firstName, string lastName,  string emailAddress, int age, int days[], DegreeProgram degreeProgram) {
  this->studentID = studentID;  // USE THIS TO TELL THE DIFFERENCE BETWEEN THE PARAMETER AND THE FIELD, use this to change object based on new parameter
  this->firstName = firstName;
  this->lastName = lastName;
  this->emailAddress = emailAddress;
  this->age = age;
  for(int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
  this->degreeProgram = degreeProgram;
}

Student::~Student() { // this is a destructor to deallocate memory after class object is destroyed

}

// WE WILL IMPLEMENT OUT GETTERS BELOW
string Student::getStudentId() {
  return this->studentID;
}

string Student::getFirstName() {
  return this->firstName;
}

string Student::getLastName() {
  return this->lastName;
}

string Student::getEmailAddress() {
  return this->emailAddress;
}
int Student::getAge() {
  return this->age;
}

int* Student::getDays() {
  return this->days;
}

DegreeProgram Student::getDegreeProgram() {
  return this->degreeProgram;
}

// WE WILL IMPLEMENT THE SETTERS BELOW
void Student::setStudentId(string newID) {
  this->studentID = newID;
}
void Student::setFirstName(string newFirstName) {
  this->firstName = newFirstName;
}
void Student::setLastName(string newLastName) {
  this->lastName = newLastName;
}
void Student::setEmailAddress(string newEmail) {
  this->emailAddress = newEmail;
}
void Student::setAge(int newAge) {
  this->age = newAge;
}
void Student::setDays(int days[]) {
  for(int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeTypes(DegreeProgram dp) {
  this->degreeProgram = dp;
}

// THIS IS A PRINT FUNCTION FOR HEADER TO BE PRINTED BEFORE OUR DATA
void Student::printHeaderTop() {
  cout << "Student Data Layout: STUDENT ID (LETTER#) || FIRST NAME || LAST NAME || EMAIL || AGE || DAYS (#, #, #) || DEGREE PROGRAM" << endl;
}

// THIS FUNCTION WILL PRINT THE STUDENT DATA TO THE SCREEN
void Student::printData() {
  cout << this->getStudentId() << "\t";
  cout << this->getFirstName() << "\t";
  cout << this->getLastName() <<  "\t";
  cout << this->getEmailAddress() << "\t";
  cout << this->getAge() << "\t";
  cout << this->getDays()[0] << ", "; // get days so we don't print pointer address
  cout << this->getDays()[1] << ", ";
  cout << this->getDays()[2] << "\t";
  cout << degreeProgramTypes[this->getDegreeProgram()] << "\n"; // print booktype string based on index
}
