#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"

class Student :public Person
{
    public:
        Student(const char* new_name="name", const char* new_dateOfBirth="yyyymmdd", long long new_facultyNumber=1, double new_GPA=2.0);

        void setFacultyNumber(long long new_facultyNumber);
        void setGPA(double new_GPA);

        long long getFacultyNumber() const {return this->facultyNumber;}
        double getGPA() const { return this->GPA;}

        void print() const;

    private:
        long long facultyNumber;
        double GPA;


};
#endif
