#include <iostream>
#include "Student.h"
#include "Array.h"

using namespace std;

/*Student::Student(string user, string pass, string name, int p, int q, int m, int f) {
    username = user;
    password = pass;
    fullName = name;
    projectGrade = p;
    quizGrade = q;
    midtermGrade = m;
    finalGrade = f;
}

Student::Student() {
    username = "";
    password = "";
    fullName = "";
    projectGrade = 0;
    quizGrade = 0;
    midtermGrade = 0;
    finalGrade = 0;
}*/


/*bool Student :: login(string username, string password) {
    // need to add stuff
} // login*/

void Student::printStudent() {
    cout << getStudentName() << " (" << getUsername() << ", " << getPassword() << ") " << endl;
    cout << "Project Score: " << getProjectGrade() << "  Quiz Score: " << getQuizGrade() << endl;
    cout << "Midterm Score: " << getMidtermGrade() << "  Final Score: " << getFinalGrade() << "\n\n";
} // print student


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

void Student :: setProjectGrade(int grade) {
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
