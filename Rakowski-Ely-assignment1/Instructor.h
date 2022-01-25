#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Student.h"
#include <string>

using namespace std;

class Instructor {

private:
    string fullName;                                    // Instructor full name
    string username;                                    // Instructor username
    string password;                                    // Instructor password

public:
    bool login(string username, string password);       // login to instructor account

    string getUsername();                               // gets username
    string getPassword();                               // gets password
    string getInstructorName();                         // gets instructor full name
    Student getStudent(string username);                // gets student from list
    Student getMinStudent(int gradeType);               // gets lowest score from student
    Student getMaxStudent(int gradeType);               // gets highest score from student
    double getAvg(int gradeType);                       // gets average score from students

    void setInstructorName(string fullName);            // sets the instructor's name
    void setUsername(string username);                  // sets username
    void setPassword(string password);                  // sets password
};

#endif
