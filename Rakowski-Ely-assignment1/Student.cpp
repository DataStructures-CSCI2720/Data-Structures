#include <iostream>
#include "Student.h"
#include "Array.h"

using namespace std;

bool Student :: login(string username, string password) {
    // need to add stuff
} // login

// void Student :: printStudent(Student s) {} // print student
/* getters */
string Student :: getStudentName() {
    return this -> fullName;
}

int Student :: getProjectGrade() {
    return this -> projectGrade;
}

int Student :: getQuizGrade() {
    return this -> quizGrade;
}

int Student :: getMidtermGrade() {
    return this -> midtermGrade;
}

int Student :: getFinalGrade() {
    return this -> finalGrade;
}

// getOverall grade

string Student :: getUsername() {
    return this -> username;
}

string Student :: getPassword() {
    return this -> password;
}

/* setters */
void Student :: setStudentName(string fullName) {
    this -> fullName = fullName;
}

void Student :: setProjectName(int grade) {
    this -> projectGrade = grade;
}

void Student :: setQuizGrade(int grade) {
    this -> quizGrade = grade;
}

void Student :: setMidtermGrade(int grade) {
    this -> midtermGrade = grade;
}

void Student :: setFinalGrade(int grade) {
    this -> finalGrade = grade;
}

void Student :: setUsername(string username) {
    this -> username = username;
}

void Student :: setPassword(string password) {
    this -> password = password;
}
