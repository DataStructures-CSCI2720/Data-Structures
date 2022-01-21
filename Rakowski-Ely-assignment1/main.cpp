#include "Instructor.h"
#include "Student.h"
#include "Array.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void verifyArgs(int argc, char *argv[]);
//void getStudents();
//void getInstructors();
int getOp();
void studentPath();
void instructorPath();

int main(int argc, char *argv[]) {
    verifyArgs(argc, argv); // verifies text arguments
    int o = getOp();
    if (o == 3) {
        exit(0);
    } else if (o == 2) {
        studentPath();
    } else if (o == 1) {
        instructorPath();
    }
    // needs to loop back to login
    return 0;
} // main

void studentPath() {
    Student s;
    string user, pass;
    cout << "Enter credentials to login,\n\t" << "Enter username:  ";
    cin >> user;
    cout << "Enter password:  ";
    cin >> pass;
    if (s.login(user, pass)) {
        cout << "You are now logged in as student " << s.getStudentName() << ".\n";
    } else {
        cout << "Login as student failed.\n";
        exit(0);
    }
    string ans;
    cout << "Do you want to view grades (y/n)?  ";
    cin >> ans;
    if (ans == "y") {
        cout << "Student name: " << s.getStudentName() << endl;
        cout << "\tProject\t" << s.getProjectGrade() << "%\n\t";
        cout << "Quiz\t" << s.getQuizGrade() << "%\n\t";
        cout << "Midterm\t" << s.getMidtermGrade() << "%\n\t";
        cout << "Final\t" << s.getFinalGrade() << "%\n\t";
        cout << "Overall\t" << s.getOverallGrade() << "%\n\n";
    }
    cout << "Exiting...\n";
    //MAKE IT LOOP BACK TO LOGIN
}

void instructorPath() { // need to add instructor viewing student work
    Instructor I;
    string user, pass;
    cout << "Enter credentials to login,\n\t" << "Enter username:  ";
    cin >> user;
    cout << "Enter password:  ";
    cin >> pass;
    if (I.login(user, pass)) {
        cout << "You are now logged in as instructor " << I.getInstructorName() << ".\n";
        cout << "Exiting...\n";
        exit(0);
    } else {
        cout << "Login as student failed.\n";
        exit(0);
    }
}

int getOp() {
    int num = 4;
    while (num > 3) {
        cout << "User types,\n\t" << "1 - Instructor\n\t" << "2 - Student\n" << "Select a login user type or enter 3 to exit:  ";
        cin >> num;
        if (num > 3) {
            cout << "Invalid option. Please enter a valid option.\n" << endl;
        }
    }
    return num;
}

/*void getStudents() { // probably gonna delete this block later
    ifstream students("students.txt");
    string u;
    string p;
    string n;
    string l;
    int s1;
    int s2;
    int s3;
    int s4;
    int i = 0;
    while (students >> u >> p >> n >> l >> s1 >> s2 >> s3 >> s4) {
        s[i].setUsername(u);
        s[i].setPassword(p);
        s[i].setStudentName(n + " " + l);
        s[i].setProjectGrade(s1);
        s[i].setQuizGrade(s2);
        s[i].setMidtermGrade(s3);
        s[i].setFinalGrade(s4);
        i++;
    }
}

void getInstructors() {
    ifstream instructors("instructors.txt");
    string u;
    string p;
    string n;
    string l;
    int j = 0;
    while (instructors >> u >> p >> n >> l) {
        i[j].setUsername(u);
        i[j].setPassword(p);
        i[j].setInstructorName(n + " " + l);
        j++;
    }
}*/

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

/*string selectLogin(Array arr); // main screen
void instructorLogin(Array arr); // is what is is
void studentLogin(Array arr);
void instructorQuery(Array arr); // once login in instructor screen
void studentQuery(Array arr); // once logged in student screen

string selectLogin(Array arr) {
    keyboard = "";
    cout << "User types,\n    1 - Instructor\n    2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit:" << endl; 
    cin >> keyboard;
    if (keyboard == "1") {
        instructorLogin(arr); // go to instructor user interface
    } else if (keyboard == "2") {
        studentLogin(arr); // go to student user interface
    } else if (keyboard == "3") {
        cout << "Exiting . . ." << endl; // exit
        exit(0);
    } else {
        cout << "Invalid option. Please enter a valid option.\n" << endl;
        selectLogin(arr); // restarts on main screen
    } // else

} // select login / type */

/*void instructorLogin(Array arr) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (instructor.login(username, password)) {
    instructor = arr.getInstructor(username, password);
    cout << "You are now logged in as instructor " << instructor.getInstructorName() << "." << endl;
    instructorQuery(arr); // goes to instructor interface
  } else {
    cout << "Login as instructor failed.\n" << endl;
    selectLogin(arr); // restarts to main screen
  }
} /* instructorLogin */

/*void studentLogin(Array arr) {
  cout << "Enter credentials to login,\n\tEnter username:" << endl;
  cin >> username;
  cout << "\tEnter password:" << endl;
  cin >> password;
  if (student.login(username, password)) {
    student = arr.getStudent(username, password);
    cout << "You are now logged in as student " << student.getStudentName() << "." << endl;
    studentQuery(arr); // goes to student interface
  } else {
    cout << "Login as student failed.\n" << endl;
    selectLogin(arr); // restarts to main screen
  }
} /* studentLogin */

/*void instructorQuery(Array arr) {
    cout << "\nQuery options,\n\t1 - view grades of a student"
         << "\n\t2 - view stats"
         << "\nEnter option number: " << endl;
    string option;
    cin >> option;
    if (option == '1') {
        // not implemented yet
    } else if (option == '2') {
        // not implemented yet -- might need a helper method here
    } else {
        cout << "\nInvalid option. Please enter a valid option." << endl;
        instructorQuery(arr);
    } // else

} // instrctor query */

/*void studentQuery(Array arr) {
    cout << "\nDo you want to view grades (y/n)? " << endl;
    string yesorno;
    cin >> yesorno;
    if (yesorno == 'y') {
        // not implemented yet, but need to call a helper method
    } else if (yesorno == 'n') {
        selectLogin(arr); // returns to start
    } else { // might want to ask how he wants to handle this
        // doesnt say we need this option but i implemented anyway like instructorquery
        cout << "\Invalid option. Please enter a valid option. (y/n)" << endl;
        studentQuery(arr);
        // selectType(arr); this is another option
    }
} // student query */

//void viewStats???
