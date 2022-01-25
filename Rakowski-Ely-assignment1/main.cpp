#include "Instructor.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

/* Declarations */
void verifyArgs(int argc, char *argv[]);                // verifies the two files passed in the argument
void selectLogin();                                     // select to login as student or instructor
void instructorLogin();                                 // instructor login prompt
void studentLogin();                                    // student login prompt
void instructorQuery(Instructor instructObj);           // instructor viewing options
void studentQuery(Student studentObj);                  // student viewing options
void viewStats(Student studentObj);                     // prints all of student's grades
void instructOptionOne(Instructor instructObj);         // instructor view student grades
void instructOptionTwo(Instructor instructObj);         // instructor view min,max,avg
void viewGradeTypes();                                  // instructor prompt to view student grades

/**
 * @brief Main method initializes the database and allows the user to login as
 * a student or instructor and view individual or min,max,avg grades.
 *
 * @param argc number of file args
 * @param argv file names
 * @return int status
 */
int main(int argc, char *argv[]) {
    verifyArgs(argc, argv); // verifies file arguments
    selectLogin(); // begins login screen for user
    return 0;
} // main

/**
 * @brief Verifies the file arguments passed when executed.
 *
 * @param argc number of args passed from main
 * @param argv file names passed from main
 */
void verifyArgs(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Please put in the correct amount of files.\n./main [instructors.txt] [students.txt]" << endl;
        exit(0); // exit if incorrect args
    } // if
    if (strcmp(argv[1],"instructors.txt") != 0) {
        cout << "Error: cannot parse instructors information from file" <<
            "\nnot_a_file_name" << endl;
        exit(0); // exit if incorrect args
    } else if (strcmp(argv[2],"students.txt") != 0) {
        cout << "Error: cannot parse students information from file" <<
            "\nnot_a_file_name" << endl;
        exit(0); // exit if incorrect args
    } else {
        cout << "Parsing instructors and students information success.\n. . .\n" << endl;
    } // if
} // verifyArgs

/**
 * @brief Prompts the user to sign in as an instructor or student and verifies choice.
 *
 */
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
        cout << "\nInvalid option. Please enter a valid option.\n" << endl;
        selectLogin(); // restarts on main screen
    } // else
} // selectLogin

/**
 * @brief Prompts user to sign in as an instructor and verifies username
 * and password.
 *
 */
void instructorLogin() {
    Instructor instructObject;
    string username, password;
    cout << "\nEnter credentials to login,\n\tEnter username:  ";
    cin >> username;
    cout << "\tEnter password:  ";
    cin >> password;
    if (instructObject.login(username, password)) {
        cout << "\nYou are now logged in as instructor " << instructObject.getInstructorName() << "." << endl;
        instructorQuery(instructObject); // goes to instructor interface
    } else {
        cout << "\nLogin as instructor failed.\n" << endl;
        selectLogin(); // restarts to main screen
    }
} // instructorLogin

/**
 * @brief Prompts user to sign in as a student and verifies username and password.
 *
 */
void studentLogin() {
    Student studentObject;
    string username, password;
    cout << "\nEnter credentials to login,\n\tEnter username:  ";
    cin >> username;
    cout << "\tEnter password:  ";
    cin >> password;
    if (studentObject.login(username, password)) {
        cout << "\nYou are now logged in as student " << studentObject.getStudentName() << "." << endl;
        studentQuery(studentObject); // goes to student interface
    } else {
        cout << "\nLogin as student failed.\n" << endl;
        selectLogin(); // restarts to main screen
    } // if
} // studentLogin

/**
 * @brief Prompts the signed in instructor to view either a single
 * student's grades or the min,max,avg grades of the group of
 * students.
 *
 * @param instructObject instructor signed in
 */
void instructorQuery(Instructor instructObject) {
    cout << "\nQuery options,\n\t1 - view grades of a student"
         << "\n\t2 - view stats"
         << "\nEnter option number:  ";
    char option;
    cin >> option;
    if (option == '1') {
        instructOptionOne(instructObject); // goes to first instructor option
    } else if (option == '2') {
        instructOptionTwo(instructObject); // goes to second instructor option
    } else {
        cout << "\nInvalid option. Please enter a valid option." << endl;
        instructorQuery(instructObject); // goes back to beginning of instructor query
    } // if
} // instrctorQuery

/**
 * @brief Prompts signed in student to view their grades.
 *
 * @param studentObj student signed in
 */
void studentQuery(Student studentObj) {
    cout << "\nDo you want to view grades (y/n)?  ";
    char opt;
    cin >> opt;
    if (opt == 'y') {
        viewStats(studentObj); // prints student grades
        selectLogin(); // returns back to login screen
    } else if (opt == 'n') {
        cout << " " << endl;
        selectLogin(); // returns to start
    } else {
        cout << "\nInvalid option. Please enter a valid option. (y/n)" << endl;
        studentQuery(studentObj); // goes back to beginning of student query
    } // if
} // studentQuery

/**
 * @brief Prints student's information from the file.
 *
 * @param studentObj student signed in
 */
void viewStats(Student studentObj) {
    cout << "\nStudent name: " << studentObj.getStudentName() << endl;
    cout << "\tProject\t" << studentObj.getProjectGrade() << "%\n\t";
    cout << "Quiz\t" << studentObj.getQuizGrade() << "%\n\t";
    cout << "Midterm\t" << studentObj.getMidtermGrade() << "%\n\t";
    cout << "Final\t" << studentObj.getFinalGrade() << "%\n\t";
    cout << "Overall\t" << studentObj.getOverallGrade() << "%\n\n";
} // viewStats

/**
 * @brief Prompts signed in instructor to provide the name of the student
 * in which their grades they want to view.
 *
 * @param instructObj signed in instructor
 */
void instructOptionOne(Instructor instructObj) { // ******
    string username;
    cout << "\nEnter student username to view grades:  ";
    cin >> username;
    Student studentView = instructObj.getStudent(username);
    if (studentView.getStudentName() == "default") {
        cout << "\nStudent username is not valid.\n";
        instructOptionOne(instructObj);
    } else {
        viewStats(studentView); // prints student's grades
        selectLogin(); // returns back to login screen
    } // if
} // instructOptionOne

/**
 * @brief Prompts signed in instructor to provide which students' grade
 * they want to view Minimum, Maximum, and Average scores of.
 *
 * @param instructObj signed in instructor
 */
void instructOptionTwo(Instructor instructObj) {
    viewGradeTypes(); // prints types of student grades
    int op;
    cin >> op;
    if ((op > 5)||(op < 1)) {
        cout << "\nInvalid option. Please enter a valid option.\n";
        instructOptionTwo(instructObj); // returns to beginning of prompt
    } else {
        Student l = instructObj.getMinStudent(op);
        Student h = instructObj.getMaxStudent(op);
        double avg = instructObj.getAvg(op);
        switch(op) {
            case 1: // project grades
                cout << "\nProject grade stats,\n" << "\tmin  " << l.getProjectGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getProjectGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 2: // quiz grades
                cout << "\nQuiz grade stats,\n" << "\tmin  " << l.getQuizGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getQuizGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 3: // midterm grades
                cout << "\nMidterm grade stats,\n" << "\tmin  " << l.getMidtermGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getMidtermGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 4: // final grades
                cout << "\nFinal grade stats,\n" << "\tmin  " << l.getFinalGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getFinalGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            case 5: // overall grades
                cout << "\nOverall grade stats,\n" << "\tmin  " << l.getOverallGrade() << "%";
                cout << "  (" << l.getStudentName() << ")\n";
                cout << "\tmax  " << h.getOverallGrade() << "%";
                cout << "  (" << h.getStudentName() << ")\n";
                cout << "\tavg  " << avg << "%" << endl;
                break;
            default:
                cout << "Invalid\n";
        } // switch
        cout << "\n";
        selectLogin(); // return back to login screen
    } // if
} // instructOptionTwo

/**
 * @brief Prints the students' grade options that can be viewed by
 * the instructor as specified by 1-5.
 *
 */
void viewGradeTypes() {
    cout << "\nGrade Types," << endl;
    cout << "\t1 - Project grade" << endl;
    cout << "\t2 - Quiz grade" << endl;
    cout << "\t3 - Midterm grade" << endl;
    cout << "\t4 - Final grade" << endl;
    cout << "\t5 - Overall grade" << endl;
    cout << "Select a grade type to view stats:  ";
} // viewGradeTypes
