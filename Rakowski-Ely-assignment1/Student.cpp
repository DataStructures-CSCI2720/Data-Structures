#include <iostream>
#include "Student.h"
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

/**
 * @brief Student.cpp class stores a student object with a unique username,
 * password, full name, project grade, quiz grade, midterm grade, and 
 * final grade.
 */

/**
 * @brief Login to Student account with correct username and password as 
 * specified in "students.txt" file. 
 * 
 * @param username student's username
 * @param password student's password
 * @return true when successfully logged in
 * @return false otherwise
 */
bool Student::login(string username, string password) {
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
        } // if
    } // while
    return false;
} // login

/**
 * @brief Gets the full name of the student object.
 * 
 * @return string of student's full name
 */
string Student::getStudentName() {
    return this -> fullName;
} // getStudentName

/**
 * @brief Gets the project grade of the student.
 * 
 * @return int value of project grade
 */
int Student::getProjectGrade() {
    return this -> projectGrade;
} // getProjectGrade

/**
 * @brief Gets the quiz grade of the student.
 * 
 * @return int value of quiz grade
 */
int Student::getQuizGrade() {
    return this -> quizGrade;
} // getQuizGrade

/**
 * @brief Gets the midterm grade of the student.
 * 
 * @return int value of midterm grade
 */
int Student::getMidtermGrade() {
    return this -> midtermGrade;
} // getMidtermGrade

/**
 * @brief Gets the final grade of the student.
 * 
 * @return int value of midterm grade
 */
int Student::getFinalGrade() {
    return this -> finalGrade;
} // getFinalGrade

/**
 * @brief Gets overall grade of the student.
 * 
 * @return double value of overall grade
 */
double Student::getOverallGrade() {
    return getProjectGrade()*0.3 + getQuizGrade()*0.1 
        + getMidtermGrade()*0.2 + getFinalGrade()*0.4;
} // getOverallGrade

/**
 * @brief Gets string of student username.
 * 
 * @return string of student's username
 */
string Student::getUsername() {
    return this -> username;
} // getUsername

/**
 * @brief Gets string of student password.
 * 
 * @return string of student's password
 */
string Student::getPassword() {
    return this -> password;
} // getPassword

/**
 * @brief Sets the full name of the student.
 * 
 * @param fullName string of student's name
 */
void Student::setStudentName(string fullName) {
    this -> fullName = fullName;
} // setStudentName

/**
 * @brief Sets the project grade of the student.
 * 
 * @param grade int value of student's project grade
 */
void Student::setProjectGrade(int grade) {
    this -> projectGrade = grade;
} // setProjectGrade

/**
 * @brief Sets the quiz grade of the student.
 * 
 * @param grade int value of student's quiz grade
 */
void Student::setQuizGrade(int grade) {
    this -> quizGrade = grade;
} // setQuizGrade

/**
 * @brief Sets the midterm grade of the student.
 * 
 * @param grade int value of midterm grade
 */
void Student::setMidtermGrade(int grade) {
    this -> midtermGrade = grade;
} // setMidtermGrade

/**
 * @brief Sets the final grade of the student.
 * 
 * @param grade int value of final grade
 */
void Student::setFinalGrade(int grade) {
    this -> finalGrade = grade;
} // setFinalGrade

/**
 * @brief Sets the username of the student.
 * 
 * @param username string of student's username
 */
void Student::setUsername(string username) {
    this -> username = username;
} // setUsername

/**
 * @brief Sets the password of the student.
 * 
 * @param password string of student's password
 */
void Student::setPassword(string password) {
    this -> password = password;
} // setPassword