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

string selectLogin(Array arr); // main screen
void instructorLogin(Array arr); // is what is is
void studentLogin(Array arr);
void instructorQuery(Array arr); // once login in instructor screen
void studentQuery(Array arr); // once logged in student screen

string selectLogin(Array arr) {
    keyboard = "";
    cout << "User types,\n    1 - Instructor\n    2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit:" << end; // endl??
    cin << keyboard;
    if (keyboard == "1") {
        instructorLogin(arr); // go to instructor user interface
    } else if (keyboard == "2") {
        studentLogin(arr); // go to student user interface
    } else if (keyboard == "3") {
        cout << "Exiting . . ." << endl; // exit
        exit(0);
    } else {
        cout << "Invalid option. Please enter a valid option.\n" << endl;
        selectLogin(arr); // restarts on main screen
    } // else

} // select login / type

void instructorLogin(Array arr) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (instructor.login(username, password)) {
    instructor = arr.getInstructor(username, password);
    cout << "You are now logged in as instructor " << instructor.getInstructorName() << "." << endl;
    instructorQuery(arr); // goes to instructor interface
  } else {
    cout << "Login as instructor failed.\n" << endl;
    selectLogin(arr); // restarts to main screen
  }
} /* instructorLogin */

void studentLogin(Array arr) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (student.login(username, password)) {
    student = arr.getStudent(username, password);
    cout << "You are now logged in as student " << student.getStudentName() << "." << endl;
    studentQuery(arr); // goes to student interface
  } else {
    cout << "Login as student failed.\n" << endl;
    selectLogin(arr); // restarts to main screen
  }
} /* studentLogin */

void instructorQuery(Array arr) {
    cout << "\nQuery options,\n\t1 - view grades of a student"
         << "\n\t2 - view stats"
         << "\nEnter option number: " << endl;
    string option;
    cin >> option;
    if (option == '1') {
        // not implemented yet
    } else if (option == '2') {
        // not implemented yet -- might need a helper method here
    } else {
        cout << "\nInvalid option. Please enter a valid option." << endl;
        instructorQuery(arr);
    } // else

} // instrctor query

void studentQuery(Array arr) {
    cout << "\nDo you want to view grades (y/n)? " << endl;
    string yesorno;
    cin >> yesorno;
    if (yesorno == 'y') {
        // not implemented yet, but need to call a helper method
    } else if (yesorno == 'n') {
        selectLogin(arr); // returns to start
    } else { // might want to ask how he wants to handle this
        // doesnt say we need this option but i implemented anyway like instructorquery
        cout << "\Invalid option. Please enter a valid option. (y/n)" << endl;
        studentQuery(arr);
        // selectType(arr); this is another option
    }
} // student query

//void viewStats???

int main(int argc, char *argv[]) {
    // the array should be passed in here ./main instructors.txt student.txt
    if (argc != 3) {
        cout << "Please put in the correct amount of files.\n./main [instructors.txt] [student.txt]"
             << endl;
        return 0; // exit program
    } else {
        string instructorsText = argv[1];
        string studentText = argv[2];
    }
    if (studentText != "student.txt") {
        cout << "\nError: cannot parse students information from file" <<
            "\nnot_a_file_name" << endl;
        return 0;
    } else if (instructorsText != "instructors.txt") {
        cout << "\nError: cannot parse instructors information from file" <<
            "\nnot_a_file_name" << endl;
    } else {
        cout << "Parsing instructors and students information success.\n. . .\n" << endl;
        // also i think this is where we pass the two text files to array to be parsed (not done)
        selectLogin(arr); // starts the instructor student interface function
    } // else
    return 0;
} // main
