#include "Student.h"

#include<iostream>

using namespace std;

Student:: Student(const char* new_name, const char* new_dateOfBirth, long long new_facultyNumber, double new_GPA)
    :Person(new_name,new_dateOfBirth)
{
    this->setFacultyNumber(new_facultyNumber);
    this->setGPA(new_GPA);
}

void Student:: setFacultyNumber(long long new_facultyNumber)
{
    if(new_facultyNumber>0)
        this->facultyNumber=new_facultyNumber;
    else throw "Invalid Faculty number";
}
void Student:: setGPA(double new_GPA)
{
    if(new_GPA>=2 && new_GPA<=6)
        this->GPA=new_GPA;
    else throw "GPA must be between 2 and 6";
}

void Student:: print() const
{
    Person:: print();
    cout<<"Faculty number:"<<this->facultyNumber<<endl;
    cout<<"GPA:"<<this->GPA<<endl;
}


