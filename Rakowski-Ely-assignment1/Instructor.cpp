#include "Instructor.h"
#include "Array.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Instructor :: login(string username, string password) {
    // needs to add stuff

} // login

string Instructor :: getInstructorName() {
    return this -> fullName;
} // get Instructor Name

string Instructor :: getUsername() {
    return this -> username;
} // get username

string Instructor :: getPassword() {
    return this -> password;
} // get password

Student Instructor :: getStudent(string username) { //student instructor
    // needs to add stuff
} // get student

Student Instructor :: getMinStudent(int gradeType) {
    // needs to add stuff
} // getMinStudent

Student Instructor :: getMaxStudent(int gradeType) {
    // needs to add stuff
} //getMaxStudent

double Instructor :: getAvg(int gradeType) {
    // needs to add stuff
} // getAvg

/*

void Instructor :: setInstructorName(string fullName) {
    this -> fullName = fullName;
}

void Instructor :: setUsername(string username) {
    this -> username = username;
}

void Instructor :: setPassword(string password) {
    this -> password = password;
}

*/
