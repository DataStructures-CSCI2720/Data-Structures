#include "Instructor.h"
#include "Student.h"
#include "Array.h"
#include <iostream>
#include <fstream>

using namespace std;

Instructor instructor;
Student student;
string keyboard;
string password;
string username;

string selectLogin(Array a); // select type
void instructorLogin(Array a);
void studentLogin(Array a);
void instructorQuery(Array a);
void studentQuery(Array a);
//void viewStats(Array a); prints everything maybe?

string selectLogin(Array a) {
    keyboard = "";
    cout << "User types,\n    1 - Instructor\n    2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit:" << end; // endl??
    cin << keyboard;
    if (keyboard == "1") {
        instructorLogin(a);
    } else if (keyboard == "2") {
        studentLogin(a);
    } else if (keyboard == "3") {
        cout << "Exiting . . ." << endl;
        exit(0);
    } else {
        cout << "Invalid option. Please enter a valid option.\n" << endl;
        selectType(a);
    } // else

} // select login / type

void instructorLogin(Array a) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (instructor.login(username, password)) {
    instructor = a.getInstructor(username, password);
    cout << "You are now logged in as instructor " << instructor.getInstructorName() << "." << endl;
    instructorQuery(a);
  } else {
    cout << "Login as instructor failed.\n" << endl;
    selectType(a);
  }
} /* instructorLogin */

void studentLogin(Array a) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (student.login(username, password)) {
    student = a.getStudent(username, password);
    cout << "You are now logged in as student " << student.getStudentName() << "." << endl;
    studentQuery(a);
  } else {
    cout << "Login as student failed.\n" << endl;
    selectType(a);
  }
} /* studentLogin */

void instructorQuery(Array a) {

} // instrctor query

void studentQuery(Array a) {

} // student query

//void viewStats???

int main(int argc, char *argv[]) {
    // needs code
} // main
