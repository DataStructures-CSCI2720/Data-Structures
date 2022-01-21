#include <iostream>
#include "Student.h"
#include "Array.h"
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

bool Student :: login(string username, string password) {
    string user, pass, n, l;
    int p, q, m, f;
    ifstream students("students.txt");
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
        if ((user == username)&&(pass == password)) {
            setUsername(user);
            setPassword(pass);
            setStudentName(n + " " + l);
            setProjectGrade(p);
            setQuizGrade(q);
            setMidtermGrade(m);
            setFinalGrade(f);
            return true;
        }
    }
    return false;
} // login

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

double Student::getOverallGrade() {
    return getProjectGrade()*0.3 + getQuizGrade()*0.1 + getMidtermGrade()*0.2 + getFinalGrade()*0.4;
}

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