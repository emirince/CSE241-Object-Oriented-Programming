#include <iostream>
#include <string>
#include "SchoolManagementSystem.h"

using namespace std;

namespace PA4{

class Student;
class Course;

SchoolManagementSystem::SchoolManagementSystem()
    : students(nullptr), courses(nullptr), numberOfStudents(0), numberOfCourses(0) {}

void SchoolManagementSystem::runMainMenu(){
   
    int menuChoice;
    do{
        cout << "Main_menu" << endl;
        cout << "0 exit" << endl;
        cout << "1 student" << endl;
        cout << "2 course" << endl;
        cout << "3 list_all_students" << endl;
        cout << "4 list_all_courses" << endl;
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0: 
            exit(1);
            break;
        case 1:
            runStudentMenu();
            break;
        case 2:
            runCourseMenu();
            break;
        case 3: 
            listAllStudents();
            break;
        case 4:
            listAllCourses();
            break;
        default:
            runMainMenu();
            break;
        }
    }while(menuChoice!=0);
}

void SchoolManagementSystem::runStudentMenu(){
int menuChoice;

    do{
        cout << "0 up" << endl;
        cout << "1 add_student" << endl;
        cout << "2 select_student" << endl;
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0:
            runMainMenu();
            break;
        case 1:
            addStudent();
            break;
        case 2:
            selectStudent();
            break;
        default:
            runStudentMenu();
            break;
        }
    }while(menuChoice!=0);

}

void SchoolManagementSystem::runCourseMenu(){
 int menuChoice;

    do{    
        cout << "0 up" << endl;
        cout << "1 add_course" << endl;
        cout << "2 select_course" << endl;
        cin >> menuChoice;

        switch (menuChoice) 
        {
        case 0:
            runMainMenu();
            break;
        case 1:
            addCourse();
            break;       
        case 2:
            selectCourse();
            break;
        default:
            runCourseMenu();
            break;
        }
    }while(menuChoice==0);
}

void SchoolManagementSystem::listAllStudents(){
    for(int i = 0; i < numberOfStudents; i++){
        cout << students[i]->getName() << " - " << students[i]->getID() << endl;
    }
}

void SchoolManagementSystem::listAllCourses(){
    for(int i = 0; i < numberOfCourses; i++){
        cout << courses[i]->getName() << " - " << courses[i]->getCode() << endl;
    }
        
}

void SchoolManagementSystem::addCourse(){
    string name;
    int code;
    
    cout << "Enter course code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter course name: ";
    getline(cin,name);

    for(int i = 0; i < numberOfCourses; i++){
        if(courses[i]->getCode()==code){
            cout << "Course already exits" << endl;
            runCourseMenu();
        }
    }
    
    Course** newList = new Course*[numberOfCourses+1];
    
    for (int i = 0; i < numberOfCourses; i++){
        newList[i] = courses[i];
    }

    Course * newCourse = new Course(code,name);

    newList[numberOfCourses] = newCourse;

    delete[] courses;

    courses = newList;

    numberOfCourses++; 

    cout << "Number of Courses: " << numberOfCourses << endl;
}

void SchoolManagementSystem::addStudent(){
    string name;
    int id;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin,name);

    for(int i = 0; i < numberOfStudents; i++){
        if(students[i]->getID()==id){
            cout << "Students already exists" << endl;
            return;
        }
    }

    Student** newList = new Student*[numberOfStudents+1];

    for(int i = 0 ; i < numberOfStudents ; i++){
        newList[i] = students[i];
    }

    Student* newStudent = new Student(id,name);

    newList[numberOfStudents] = newStudent; 

    delete[] students;

    students = newList;

    numberOfStudents++;
}

void SchoolManagementSystem::selectStudent(){
    string name;
    int id;
    cout << "Enter the ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter the name: ";
    getline(cin,name);

    Student* selectedStudent = nullptr;
    for(int i = 0; i < numberOfStudents; i++){
        if(students[i]->getName() == name && students[i]->getID() == id){
            selectedStudent = students[i];
            break;
        }
    }
    
    selectStudentMenu(selectedStudent);
}


void SchoolManagementSystem::selectStudentMenu(Student* student){
   
    int menuChoice;
    Student** newList = new Student*[numberOfStudents - 1];
    int a = 1;
    int index[10];
    int subChoice;
    int postNumberOfStudents = numberOfStudents;

    do
    {
        cout << "0 up" << endl;
        cout << "1 delete_student" << endl;
        cout << "2 add_selected_student_to_a_course" << endl;
        cin >> menuChoice;

        int j = 0;

        switch (menuChoice)
        {
        case 0: 
            runStudentMenu();
            break;
        case 1:
            for(int i = 0; i < numberOfStudents; i++){
                if(students[i]->getID() == student->getID()){
                    postNumberOfStudents--;
                    break;
                }
            }
            for(int i = 0; i < numberOfStudents; i++) {
                if(students[i]->getID() != student->getID()){
                    newList[j] = students[i];
                    j++;    
                }
            }
            delete[] students;

            students = newList;

            numberOfStudents = postNumberOfStudents;
            
            runStudentMenu();

            break;
        
        case 2:                
            if(numberOfCourses==0){
                cout << "There is no course you can enroll" << endl;
            }
            
            else{

                if(student->numberOfCourses > 0 ){
                for(int i = 0; i < numberOfCourses; i++)
                {
                    for(int j = 0; i < student->numberOfCourses; j++){
                        if(courses[i]->getCode()!=student->courses[j]->getCode()){
                            cout << a << ". " << courses[i]->getCode() <<  " " << courses[i]->getName() << endl;
                            index[a-1]=i;
                        }
                    }
                    
                }
                cin >> subChoice;
                courses[index[subChoice-1]]->addStudent(student);
                }

                else{
                    for(int i = 0; i < numberOfCourses; i++){
                        cout << i+1 << ". " << courses[i]->getCode() << " " << courses[i]->getName() << endl;
                    }
                    cin >> subChoice;
                    courses[subChoice-1]->addStudent(student);
                }
            }
            break;
        case 3: 

            for(int i = 0; i < student->numberOfCourses; i++){
                cout << i+1 << " " << student[i].getName() <<  " " << student[i].getName() << endl;
            }

            cin >> subChoice;
            courses[subChoice-1]->removeStudent(student);

        default:
            selectStudentMenu(student);
            break;
        }
    } while(menuChoice!=0);
    
}

void SchoolManagementSystem::selectCourse(){
    string name;
    int code;
    cout << "Enter the code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter the name: ";
    getline(cin,name);

    Course* selectedCourse = nullptr;

    for(int i = 0; i < numberOfCourses; i++){
        if(courses[i]->getName() == name && courses[i]->getCode() == code) {
            selectedCourse = courses[i];
            break;
        }
    }
    
    if(selectedCourse == nullptr){
        cout << "Course not found" << endl;
        selectCourse();
    }
    else{
        cout << selectedCourse->getName() << " is selected" << endl;
        selectCourseMenu(selectedCourse);
    }
}

void SchoolManagementSystem::selectCourseMenu(Course* course){
    int menuChoice;
    int check = -1;
    int j = 0;
    Course** newList = new Course*[numberOfCourses - 1];
    do
    {
        cout << "0 up" << endl;
        cout << "1 delete_course" << endl;
        cout << "2 list_students_registered_to_the_selected_course" << endl;
        cin >> menuChoice;

        switch(menuChoice)
        {

        case 0:
            runCourseMenu();
            break;
        case 1:
            for(int i = 0; i < numberOfCourses ; i++) {
                if(courses[i]->getCode() == course->getCode()) {
                    check++;
                    break;
                }
            }
            if(check==-1) return;

            for(int i = 0; i < numberOfCourses; i++) {
                if(courses[i]->getCode() != course->getCode()) {
                    newList[j] = courses[i];
                    j++;    
                }
            }
            delete[] courses;

            courses = newList;

            numberOfCourses--;
            
            runCourseMenu();

            break;
        
        case 2:    
            
            if(course->numberOfStudents==0){
                cout << "There is no student registered to this course" << endl;
            }
            else{
                for (int i = 0; i < course->numberOfStudents  ; i++){
                    cout << i+1 << " " << course->students[i]->getID() << " " << course->students[i]->getName() << endl; 
                }
            }
        default:
            selectCourseMenu(course);
            break;
        }
    } while(menuChoice!=0);
}

SchoolManagementSystem::~SchoolManagementSystem(){
    delete[] courses;
    delete[] students;
}

}