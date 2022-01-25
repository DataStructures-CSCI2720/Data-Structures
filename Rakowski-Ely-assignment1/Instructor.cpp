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

/*void Instructor::printInstructor() {
    cout << getInstructorName() << " (" << getUsername() << ", " << getPassword() << ") \n\n";
}*/

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
    ifstream students("students.txt");;
    while (students >> user >> pass >> n >> l >> p >> q >> m >> f) {
        if(user == username) {
            Student student;
            student.login(user, pass);
            return student;
        }
    }
} // get student

Student Instructor :: getMinStudent(int gradeType) {
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
    }
    Student min = s[0];
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                if (s[i].getProjectGrade() < min.getProjectGrade()) {
                    min = s[i];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                if (s[i].getQuizGrade() < min.getQuizGrade()) {
                    min = s[i];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                if (s[i].getMidtermGrade() < min.getMidtermGrade()) {
                    min = s[i];
                }
            }
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                if (s[i].getFinalGrade() < min.getFinalGrade()) {
                    min = s[i];
                }
            }
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                if (s[i].getOverallGrade() < min.getOverallGrade()) {
                    min = s[i];
                }
            }
            break;
        default:
            cout << "Invalid option. Please enter a valid option.";
    }
    return min;
} // getMinStudent

Student Instructor :: getMaxStudent(int gradeType) {
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
    }
    Student min = s[0];
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                if (s[i].getProjectGrade() > min.getProjectGrade()) {
                    min = s[i];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                if (s[i].getQuizGrade() > min.getQuizGrade()) {
                    min = s[i];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                if (s[i].getMidtermGrade() > min.getMidtermGrade()) {
                    min = s[i];
                }
            }
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                if (s[i].getFinalGrade() > min.getFinalGrade()) {
                    min = s[i];
                }
            }
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                if (s[i].getOverallGrade() > min.getOverallGrade()) {
                    min = s[i];
                }
            }
            break;
        default:
            cout << "Invalid option. Please enter a valid option.";
    }
    return min;
} //getMaxStudent

double Instructor :: getAvg(int gradeType) {
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
    }
    double average = 0;
    switch(gradeType) {
        case 1:
            for (int i = 0; i < 20; i++) {
                average += s[i].getProjectGrade();
            }
            average /= 20;
            break;
        case 2:
            for (int i = 0; i < 20; i++) {
                average += s[i].getQuizGrade();
            }
            average /= 20;
            break;
        case 3:
            for (int i = 0; i < 20; i++) {
                average += s[i].getMidtermGrade();
            }
            average /= 20;
            break;
        case 4:
            for (int i = 0; i < 20; i++) {
                average += s[i].getFinalGrade();
            }
            average /= 20;
            break;
        case 5:
            for (int i = 0; i < 20; i++) {
                average += s[i].getOverallGrade();
            }
            average /= 20;
            break;
        default:
            
            cout << "Invalid option. Please enter a valid option.";
    }
    return average;
} // getAvg



void Instructor :: setInstructorName(string fullName) {
    this -> fullName = fullName;
}

void Instructor :: setUsername(string username) {
    this -> username = username;
}

void Instructor :: setPassword(string password) {
    this -> password = password;
}
