#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "course.h"
#include "SchoolManagementSystem.h"

namespace PA4{

class Course; // forward declaration

class SchoolManagementSystem;   // forward declaration

class Student{

private:
    int ID;
    std::string name;
public:
    Course** courses;
    int numberOfCourses;
    Student();
    Student(int studentID, std::string studentName);
    std::string getName();      //getter
    int getID();    //getter
    void setName(std::string name);     //setter
    void setID(int ID);     //setter
    void addCourse(Course* courseToBeAdded);    
    void removeCourse(Course* courseToBeDeleted);   
    ~Student();     //Destructor
};
}
#endif // STUDENT_H