#ifndef SCHOOL_MANAGEMENT_SYSTEM_H
#define SCHOOL_MANAGEMENT_SYSTEM_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
using namespace std;

namespace PA4{

class Student;  // forward declaration

class Course;   // forward declaration

class SchoolManagementSystem {  

private:
    int numberOfStudents;
    int numberOfCourses;
    Student** students;
    Course** courses;

public:
    SchoolManagementSystem();

    void runMainMenu();         //runs main menu

    void runStudentMenu();      //runs student menu

    void runCourseMenu();       //runs course menu

    void listAllStudents();     //lists all students 

    void listAllCourses();      //lists all courses

    void selectStudentMenu(Student* student);      //runs selecet student menu

    void selectCourseMenu(Course* course);      //runs selecet course menu

    void addStudent();      //runs add student menu

    void addCourse();       //runs all course menu

    void selectStudent();      

    void selectCourse();

    ~SchoolManagementSystem();
};
}
#endif
