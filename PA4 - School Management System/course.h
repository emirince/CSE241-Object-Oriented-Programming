#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"
#include "SchoolManagementSystem.h"

namespace PA4{

class SchoolManagementSystem;   // forward declaration

class Student;  // forward declaration

class Course {
private:
    int code;
    std::string name;

public:
    int numberOfStudents;
    Student** students;
    Course();    //constructor
    Course(int courseCode, std::string courseName);     //constructor
    ~Course();      //Destructor
    void addStudent(Student* studentToBeAdded);         // adds student
    void removeStudent(Student* studentToBeRemoved);        //removes student
    std::string getName();      //getter
    int getCode();      //getter
    void setName(std::string name);     //setter
    void setCode(int code);     //setter
};
}
#endif
