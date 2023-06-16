#include "course.h"

namespace PA4{

Course::Course() : code(0), name("") {
    students = nullptr;
    numberOfStudents = 0;
}

Course::Course(int courseCode, std::string courseName) : code(courseCode), name(courseName) {
    students = nullptr;
    numberOfStudents = 0;
}

Course::~Course() {
    delete[] students;
}

void Course::addStudent(Student* studentToBeAdded) {
    for(int i = 0; i < numberOfStudents; i++) {
        if(students[i]->getID() == studentToBeAdded->getID()) {
            return;
        }
    }

    Student** newList = new Student*[numberOfStudents + 1];

    for(int i = 0; i < numberOfStudents; i++) {
        newList[i] = students[i];
    }

    newList[numberOfStudents] = studentToBeAdded;

    delete[] students;

    students = newList;

    numberOfStudents++;
}

void Course::removeStudent(Student* studentToBeRemoved) {
    int check = -1;

    for(int i = 0; i < numberOfStudents; i++) {
        if(students[i]->getID() == studentToBeRemoved->getID()) {
            check++;
            break;
        }
    }

    if(check == -1) {
        return;
    }

    Student** newList = new Student*[numberOfStudents - 1];

    int j = 0;
    for(int i = 0; i < numberOfStudents; i++) {
        if (students[i]->getID() != studentToBeRemoved->getID()) {
            newList[j] = students[i];
            j++;    
        }
    }

    delete[] students;

    students = newList;

    numberOfStudents--;
}

std::string Course::getName() {
    return name;
}

int Course::getCode() {
    return code;
}

void Course::setName(string name){
    this->name = name;
}

void Course::setCode(int code){
    this->code = code;
}
}