#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Person.h"

class Employee: virtual public Person
{
    public:
        Employee(const char* new_name="name", const char* new_dateOfBirth="yyyymmdd" ,const char* new_position="position",double new_salary=0);
        Employee(const Employee& other);
        Employee& operator=(const Employee& other);
        ~Employee();

        void setPosition(const char* new_position);
        void setSalary(double salary);

        const char* getPosition() {return this->position;}
        double getSalary() {return this->salary;}

        void print() const;

    protected:
        void printOwn() const;

    private:
        char* position;
        double salary;


};
#endif // EMPLOYEE_H_INCLUDED
