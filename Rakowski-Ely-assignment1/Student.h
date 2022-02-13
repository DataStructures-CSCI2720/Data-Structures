#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {

private:
    string fullName;                                    // Student full name
    string username;                                    // Student username
    string password;                                    // Student password
    int projectGrade;                                   // Student project grade
    int quizGrade;                                      // Student quiz grade
    int midtermGrade;                                   // Student midterm grade
    int finalGrade;                                     // Student final grade

public:
    bool login(string username, string password);       // login to student account
    
    string getStudentName();                            // gets student full name
    string getUsername();                               // gets username
    string getPassword();                               // gets password
    int getProjectGrade();                              // gets project grade
    int getQuizGrade();                                 // gets quiz grade
    int getMidtermGrade();                              // gets midterm grade
    int getFinalGrade();                                // gets final grade
    double getOverallGrade();                           // gets overall grade

    void setStudentName(string fullName);               // sets student full name
    void setProjectGrade(int grade);                    // sets project grade
    void setQuizGrade(int grade);                       // sets quiz grade
    void setMidtermGrade(int grade);                    // sets midterm grade
    void setFinalGrade(int grade);                      // sets final grade
    void setUsername(string username);                  // sets username
    void setPassword(string password);                  // sets password
};

#endif



