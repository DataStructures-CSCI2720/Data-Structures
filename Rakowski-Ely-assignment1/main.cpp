#include "Instructor.h"
#include "Student.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void verifyArgs(int argc, char *argv[]);
int getOp();
void selectLogin();
void instructorLogin();
void studentLogin();
void instructorQuery(Instructor instructObj);
void studentQuery(Student studentObj);
void instructOptionOne(Instructor instructObj);
void instructOptionTwo(Instructor instructObj);
void viewStats(Student studentObj);
void viewGradeTypes();

int main(int argc, char *argv[]) {
    verifyArgs(argc, argv); // verifies text arguments
    selectLogin();
} // main

void verifyArgs(int argc, char *argv[]) {
    // the array should be passed in here ./main instructors.txt student.txt
    if (argc != 3) {
        cout << "Please put in the correct amount of files.\n./main [instructors.txt] [students.txt]"
             << endl;
        exit(0); // exit program
    } // if
    if (strcmp(argv[1],"instructors.txt") != 0) {
        cout << "\nError: cannot parse instructors information from file" <<
            "\nnot_a_file_name" << endl;
        exit(0);
    } else if (strcmp(argv[2],"students.txt") != 0) {
        cout << "\nError: cannot parse students information from file" <<
            "\nnot_a_file_name" << endl;
        exit(0);
    } else {
        cout << "Parsing instructors and students information success.\n. . .\n" << endl;
    } // else
}

void selectLogin() {
    string keyboard = "";
    cout << "User types,\n    1 - Instructor\n    2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit:  ";
    cin >> keyboard;
    if (keyboard == "1") {
        instructorLogin(); // go to instructor user interface
    } else if (keyboard == "2") {
        studentLogin(); // go to student user interface
    } else if (keyboard == "3") {
        cout << "Exiting . . ." << endl; // exit
        exit(0);
    } else {
        cout << "Invalid option. Please enter a valid option.\n" << endl;
        selectLogin(); // restarts on main screen
    } // else
} // select login

void instructorLogin() {
    Instructor instructObject;
    string username, password;
    cout << "Enter credentials to login,\n\tEnter username:  ";
    cin >> username;
    cout << "\tEnter password:  ";
    cin >> password;
    if (instructObject.login(username, password)) {
        cout << "You are now logged in as instructor " << instructObject.getInstructorName() << "." << endl;
        instructorQuery(instructObject); // goes to instructor interface
    } else {
        cout << "Login as instructor failed.\n" << endl;
        selectLogin(); // restarts to main screen
    }
} /* instructorLogin */

void studentLogin() {
    Student studentObject;
    string username, password;
    cout << "Enter credentials to login,\n\tEnter username:  ";
    cin >> username;
    cout << "\tEnter password:  ";
    cin >> password;
    if (studentObject.login(username, password)) {
        cout << "You are now logged in as student " << studentObject.getStudentName() << "." << endl;
        studentQuery(studentObject); // goes to student interface
    } else {
        cout << "Login as student failed.\n" << endl;
        selectLogin(); // restarts to main screen
    }
} /* studentLogin */

void instructorQuery(Instructor instructObject) {
    cout << "\nQuery options,\n\t1 - view grades of a student"
         << "\n\t2 - view stats"
         << "\nEnter option number:  ";
    char option;
    cin >> option;
    if (option == '1') {
        instructOptionOne(instructObject);
    } else if (option == '2') {
        instructOptionTwo(instructObject);
    } else {
        cout << "\nInvalid option. Please enter a valid option." << endl;
        instructorQuery(instructObject);
    } // else

} // instrctor query */

void studentQuery(Student studentObj) {
    cout << "\nDo you want to view grades (y/n)?  ";
    char opt;
    cin >> opt;
    if (opt == 'y') {
        viewStats(studentObj);
        selectLogin();
    } else if (opt == 'n') {
        selectLogin(); // returns to start
    } else {
        cout << "\nInvalid option. Please enter a valid option. (y/n)" << endl;
        studentQuery(studentObj);
    }
} // student query */

void viewStats(Student studentObj) {
    cout << "Student name: " << studentObj.getStudentName() << endl;
    cout << "\tProject\t" << studentObj.getProjectGrade() << "%\n\t";
    cout << "Quiz\t" << studentObj.getQuizGrade() << "%\n\t";
    cout << "Midterm\t" << studentObj.getMidtermGrade() << "%\n\t";
    cout << "Final\t" << studentObj.getFinalGrade() << "%\n\t";
    cout << "Overall\t" << studentObj.getOverallGrade() << "%\n\n";
} // view stats

void instructOptionOne(Instructor instructObj) {
    string username;
    cout << "Enter student username to view grades:  ";
    cin >> username;
    Student studentView = instructObj.getStudent(username); // needs to go back to query if wrong name
    viewStats(studentView);
    selectLogin();
} // instructoptionone

void instructOptionTwo(Instructor instructObj) {
    viewGradeTypes();
    int op;
    cin >> op;
    if ((op > 5)||(op < 1)) {
        cout << "Invalid option. Please enter a valid option.\n";
        instructOptionTwo(instructObj);
    } else {
        Student l = instructObj.getMinStudent(op);
        Student h = instructObj.getMaxStudent(op);
        double avg = instructObj.getAvg(op);
        switch(op) {
            case 1:
                cout << "\tProject grade stats,\n" << "\tmin  " << l.getProjectGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getProjectGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 2:
                cout << "\tQuiz grade stats,\n" << "\tmin  " << l.getQuizGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getQuizGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 3:
                cout << "\tMidterm grade stats,\n" << "\tmin  " << l.getMidtermGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getMidtermGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 4:
                cout << "\tFinal grade stats,\n" << "\tmin  " << l.getFinalGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getFinalGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 5:
                cout << "\tOverall grade stats,\n" << "\tmin  " << l.getOverallGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getOverallGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            default:
                cout << "Invalid\n";
        }
        cout << "\n";
        selectLogin();
    }
    
} // instructoptiontwo

void viewGradeTypes() {
    cout << "Grade Types," << endl;
    cout << "\n\t1 - Project grade" << endl;
    cout << "\n\t2 - Quiz grade" << endl;
    cout << "\n\t3 - Midterm grade" << endl;
    cout << "\n\t4 - Final grade" << endl;
    cout << "\n\t5 - Overall grade" << endl;
    cout << "\nSelect a grade type to view stats:  ";
}
