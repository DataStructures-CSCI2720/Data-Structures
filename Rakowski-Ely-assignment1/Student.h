#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {

private:

    string fullName;
    // string fullName;
    string username;
    // string username
    string password;
    // string password
    int projectGrade;
    int quizGrade;
    int midtermGrade;
    int finalGrade;

public:

    bool login(string username, string password);
    // void printStudent(Student s);

    /* getters */
    string getStudentName();
    string getUsername();
    string getPassword();
    int getProjectGrade();
    int getQuizGrade();
    int getMidtermGrade();
    int getFinalGrade();
    double getOverallGrade();

    /* Setters */
    void setStudentName(string fullName); //std::string fullName
    void setProjectGrade(int grade);
    void setQuizGrade(int grade);
    void setMidtermGrade(int grade);
    void setFinalGrade(int grade);
    // void setUsername(string username);
    // void setPassword(string password);


};

#endif
