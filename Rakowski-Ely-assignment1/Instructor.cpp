#include "Instructor.h"
#include "Array.h"
#include "Student.h"
#include <iostream>
#include <fstream>


using namespace std;

bool Instructor::login(string username, string password) {
    string user, pass, n, l;
    ifstream instructors("instructors.txt");
    while (instructors >> user >> pass >> n >> l) {
        if ((user == username)&&(pass == password)) {
            setUsername(user);
            setPassword(pass);
            setInstructorName(n + " " + l);
            return true;
        }
    }
    return false;
} // login

void Instructor::printInstructor() {
    cout << getInstructorName() << " (" << getUsername() << ", " << getPassword() << ") \n\n";
}

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
    string user, pass, n, l;
    int p, q, m, f;
    ifstream students("students.txt");

    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
        if(user == username) {
            Student student;
            student.login(user, pass);
            return student;
        }
    }
} // get student
/*
Student Instructor :: getMinStudent(int gradeType) {
    // needs to add stuff
} // getMinStudent

Student Instructor :: getMaxStudent(int gradeType) {
    // needs to add stuff
} //getMaxStudent

double Instructor :: getAvg(int gradeType) {
    // needs to add stuff
} // getAvg*/



void Instructor :: setInstructorName(string fullName) {
    this -> fullName = fullName;
}

void Instructor :: setUsername(string username) {
    this -> username = username;
}

void Instructor :: setPassword(string password) {
    this -> password = password;
}
