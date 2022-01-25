#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Instructor.cpp class stores an instructor object with a unique
 * username, password, and full name.
 */

/**
 * @brief Login to Instructor account with correct username and password as
 * specified in "instructors.txt" file.
 * 
 * @param username instructor's username
 * @param password instructor's password
 * @return true when successfully logged in
 * @return false otherwise
 */
bool Instructor::login(string username, string password) {
    string user, pass, n, l;
    ifstream instructors("instructors.txt");
    while (instructors >> user >> pass >> n >> l) {
        if ((user == username)&&(pass == password)) {
            setUsername(user);
            setPassword(pass);
            setInstructorName(n + " " + l);
            return true;
        } // if
    } // while
    return false;
} // login

/**
 * @brief Gets the full name of the instructor object.
 * 
 * @return string of instructor's full name
 */
string Instructor::getInstructorName() {
    return this -> fullName;
} // getInstructorName

/**
 * @brief Gets string of instructor username.
 * 
 * @return string of instructor's username
 */
string Instructor::getUsername() {
    return this -> username;
} // getUsername

/**
 * @brief Gets string of instructor password
 * 
 * @return string of instructor's password
 */
string Instructor::getPassword() {
    return this -> password;
} // getPassword

/**
 * @brief Gets student from "students.txt" file as specified
 * from the username and attempts to login.
 * 
 * @param username of student
 * @return Student object as specified from file
 */
Student Instructor::getStudent(string username) {
    string user, pass, n, l;
    int p, q, m, f;
    ifstream students("students.txt");;
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
        if(user == username) {
            Student student;
            student.login(user, pass);
            return student;
        } // if
    } // while
} // getStudent

/**
 * @brief Gets the Student with the lowest score of the assignment
 * specified by gradeType.
 * 
 * @param gradeType (1-5) depending on which type of grade
 * @return Student object with lowest score of the assignment
 */
Student Instructor::getMinStudent(int gradeType) {
    Student s[20];
    string user, pass, n, l;
    int p, q, m, f, i = 0;
    ifstream students("students.txt");
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
            s[i].setUsername(user);
            s[i].setPassword(pass);
            s[i].setStudentName(n + " " + l);
            s[i].setProjectGrade(p);
            s[i].setQuizGrade(q);
            s[i].setMidtermGrade(m);
            s[i].setFinalGrade(f);
            i++;
    } // while
    Student min = s[0];
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                if (s[i].getProjectGrade() < min.getProjectGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                if (s[i].getQuizGrade() < min.getQuizGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                if (s[i].getMidtermGrade() < min.getMidtermGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                if (s[i].getFinalGrade() < min.getFinalGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                if (s[i].getOverallGrade() < min.getOverallGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        default:
            cout << "Invalid option. Please enter a valid option.";
    } // switch
    return min;
} // getMinStudent

/**
 * @brief Gets the Student with the highest score of the assignment
 * specified by gradeType.
 * 
 * @param gradeType (1-5) depending on which type of grade
 * @return Student object with highest score of the assignment
 */
Student Instructor::getMaxStudent(int gradeType) {
    Student s[20];
    string user, pass, n, l;
    int p, q, m, f, i = 0;
    ifstream students("students.txt");
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
            s[i].setUsername(user);
            s[i].setPassword(pass);
            s[i].setStudentName(n + " " + l);
            s[i].setProjectGrade(p);
            s[i].setQuizGrade(q);
            s[i].setMidtermGrade(m);
            s[i].setFinalGrade(f);
            i++;
    } // while
    Student min = s[0];
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                if (s[i].getProjectGrade() > min.getProjectGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                if (s[i].getQuizGrade() > min.getQuizGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                if (s[i].getMidtermGrade() > min.getMidtermGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                if (s[i].getFinalGrade() > min.getFinalGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                if (s[i].getOverallGrade() > min.getOverallGrade()) {
                    min = s[i];
                } // if
            } // for
            break;
        default:
            cout << "Invalid option. Please enter a valid option.";
    } // switch
    return min;
} // getMaxStudent

/**
 * @brief Gets the average score of the assignment as specified
 * by gradeType.
 * 
 * @param gradeType (1-5) depending on which type of grade
 * @return double object with average score of the assignment
 */
double Instructor::getAvg(int gradeType) {
    Student s[20];
    string user, pass, n, l;
    int p, q, m, f, i = 0;
    ifstream students("students.txt");
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
            s[i].setUsername(user);
            s[i].setPassword(pass);
            s[i].setStudentName(n + " " + l);
            s[i].setProjectGrade(p);
            s[i].setQuizGrade(q);
            s[i].setMidtermGrade(m);
            s[i].setFinalGrade(f);
            i++;
    } // while
    double average = 0;
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                average += s[i].getProjectGrade();
            } // for
            average /= 20;
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                average += s[i].getQuizGrade();
            } // for
            average /= 20;
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                average += s[i].getMidtermGrade();
            } // for
            average /= 20;
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                average += s[i].getFinalGrade();
            } // for
            average /= 20;
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                average += s[i].getOverallGrade();
            } // for
            average /= 20;
            break;
        default:
            cout << "Invalid option. Please enter a valid option.";
    } // switch
    return average;
} // getAvg

/**
 * @brief Sets the full name of the Instructor.
 * 
 * @param fullName of the instructor
 */
void Instructor::setInstructorName(string fullName) {
    this -> fullName = fullName;
} // setInstructorName

/**
 * @brief Sets the username of the Instructor.
 * 
 * @param username of the instructor
 */
void Instructor::setUsername(string username) {
    this -> username = username;
} // setUsername

/**
 * @brief Sets the password of the Instructor.
 * 
 * @param password of the instructor
 */
void Instructor::setPassword(string password) {
    this -> password = password;
} // setPassword