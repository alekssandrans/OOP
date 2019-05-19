#ifndef DEAN_H_INCLUDED
#define DEAN_H_INCLUDED

#include "Professor.h"
#include "Employee.h"

class Dean :public Professor,public Employee
{
    public:

        Dean(const char* new_name, const char* new_dateOfBirth,
             const char* new_major, const Student* new_students, int new_studentsCount,
             const char* new_position,double new_salary)
             :Person(new_name,new_dateOfBirth),
              Professor(new_name,new_dateOfBirth,new_major,new_students,new_studentsCount),
              Employee(new_name,new_dateOfBirth,new_position,new_salary)
        {}

        void print()
        {
            Person:: print();
            Professor:: printOwn();
            Employee:: printOwn();
        }

};
#endif // DEAN_H_INCLUDED
