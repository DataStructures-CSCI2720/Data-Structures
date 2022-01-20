#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "Student.h"
#include <string>

using namespace std;

class Instructor {

private:
    string fullName;
    string username;
    string password;

public:
    bool login(string username, string password);

    /* getters */
    // string getUsername();
    // string getPassword();
    string getInstructorName();
    Student getStudent(string username);
    Student getMinStudent(int gradeType);
    Student getMaxStudent(int gradeType);
    double getAvg(int gradeType);

    /* setters */
    /*
      void setInstructorName(string fullName);
      void setUsername(string username);
      void setPassword(string password);
     */

};

#endif
