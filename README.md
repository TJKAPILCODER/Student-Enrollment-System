
Student Roster Management System:

Overview

This project is a C++ Student Roster Management System developed as part of a Computer Science course project. The system was designed to help a university transition from its existing student management platform to a new solution. The application is responsible for reading, manipulating, and displaying student data, adhering to specific requirements outlined in the project brief.

The system demonstrates expertise in C++ programming, object-oriented design, and working with dynamically allocated memory. It implements robust functionality for managing student information, including adding, removing, and querying student records.

Purpose:
The primary goal of this project is to build a functional student roster management application that:

- Reads and parses student data.
- Allows CRUD operations (create, read, update, delete) on student records.
- Validates student information (e.g., email format).
- Supports querying and filtering by degree programs.
- This system offers a streamlined approach for managing student data, ensuring data integrity and providing a user-friendly experience.
  
Features:
Core Functionalities:

Add Students:
- Dynamically adds students to the roster with their details.
  
Remove Students:
- Removes students by their unique ID. If the ID is not found, an error message is displayed.
  
Print All Students:
- Prints a complete list of all student data in a tab-separated format.
  
Average Days Calculation:
- Calculates and displays the average number of days a student spends in their courses.
  
Email Validation:
- Verifies the validity of student email addresses and lists any invalid emails.
  
Filter by Degree Program:
- Displays student information based on their degree program.

Technologies Used:
- C++: Core programming language.
- Object-Oriented Programming (OOP): Classes, inheritance, and encapsulation used to implement the system.
- Dynamic Memory Management: Use of pointers and destructors for memory allocation and deallocation.

Class Structure:
Key Classes:

DegreeProgram (degree.h):
- Enumerated type representing degree programs: SECURITY, NETWORK, and SOFTWARE.
  
  Student (student.h & student.cpp):
- Represents individual student records.
  
Attributes:
- studentID, firstName, lastName, emailAddress, age, daysInCourse (array), and degreeProgram.
  
Methods:
- Getters and setters for all attributes.
- print() function to display student information.
  
Roster (roster.h & roster.cpp):
- Manages the student roster as an array of pointers.
  
Responsibilities:
- Add, remove, and query students.
- Print all students or filter by degree program.
- Validate and display invalid emails.
- Calculate average days in courses for students.

How It Works:
Main Functionality:

- The main.cpp file initializes the roster and demonstrates key functionality.
- Displays project details, including course name, programming language, and author information.
  
Roster Operations:
- Adds student data to the roster dynamically.
- Calls functions to print all students, validate emails, and calculate averages.
- Demonstrates adding, removing, and querying student data.
  
Dynamic Memory:
- Students are stored in an array of pointers, and a destructor ensures proper memory cleanup.

Benefits:

- Streamlined Management: Efficiently add, remove, and query student records.
- Validation: Ensures email integrity and logical correctness of data.
- Scalability: Object-oriented design allows for easy expansion.
- Automation: Reduces manual management of student data.

Key Learning Outcomes:
Object-Oriented Programming:
- Designed modular and reusable code using classes.
  
Dynamic Memory Management:
- Mastered allocation, use, and cleanup of dynamic memory.
  
Algorithm Implementation:
- Parsed and manipulated student data efficiently.
  
Error Handling:
- Implemented checks for invalid operations (e.g., removing non-existent students).
  
C++ Syntax and Best Practices:
- Applied clean, efficient, and maintainable coding standards.

Installation and Usage:
Prerequisites:

- C++ Compiler: Ensure you have a C++ compiler (e.g., GCC, Clang).
- IDE: Recommended IDEs include Visual Studio, Code::Blocks, or CLion.
  
Steps to Run:

Clone the repository:
- git clone https://github.com/yourusername/Student-Roster-Management.git


Open the project in your IDE.
Ensure the following files are present:

- degree.h
- student.h, student.cpp
- roster.h, roster.cpp
- main.cpp
- Compile and run the program.

Example Outputs
Printing All Students:

A1	First Name: John	Last Name: Smith	Age: 20	daysInCourse: {35, 40, 55}	Degree Program: SECURITY
A2	First Name: Jane	Last Name: Doe	Age: 22	daysInCourse: {50, 30, 40}	Degree Program: SOFTWARE

Invalid Emails

Invalid email: johnsmith@invalid..com
Invalid email: janedoe @example.com

Average Days in Course:

Student A1 average days in course: 43.33
Student A2 average days in course: 40.00


Future Improvements
- Add support for additional degree programs.
- Implement a graphical user interface (GUI) for better usability.
- Include database integration for persistent storage.
