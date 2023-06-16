#include "student.h"

namespace PA4{

Student::Student(): ID(0), name(" "), courses(nullptr), numberOfCourses(0) {}

Student::Student(int studentID, std::string studentName): ID(studentID), name(studentName), courses(nullptr), numberOfCourses(0) {}

std::string Student::getName(){
    return name;
}

int Student::getID(){
    return ID;
}

void Student::setName(string name){
    this->name = name;
}

void Student::setID(int ID){
    this->ID = ID;
}


void Student::addCourse(Course* courseToBeAdded){
    
    for(int i = 0; i < numberOfCourses; i++){
        if(courses[i]->getCode() == courseToBeAdded->getCode())
            cout << "Student already takes this course" << endl;
            return;
    }

    Course** newList = new Course*[numberOfCourses + 1];

    for(int i = 0; i < numberOfCourses; i++){
        newList[i] = courses[i];
    }
    
    newList[numberOfCourses] = courseToBeAdded;

    delete[] courses;

    courses = newList;  
    
    numberOfCourses++;
}

void Student::removeCourse(Course* courseToBeDeleted){
    int check = -1;

    for(int i = 0; i < numberOfCourses; i++){
        if(courses[i]->getCode()==courseToBeDeleted->getCode()){
            check++;
            break;
        }
    }

    if(check==-1)
        return;

    Course** newList = new Course*[numberOfCourses - 1];

    int j = 0;

    for(int i = 0; i < numberOfCourses; i++){
        if(courses[i]->getCode() != courseToBeDeleted->getCode()){
            newList[j] = courses[i];
            j++;
        }
    }

    delete[] courses;
    courses = newList;

    numberOfCourses--;
}

Student::~Student(){
    delete[] courses;
}

}