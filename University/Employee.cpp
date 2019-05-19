#include "Employee.h"

#include<iostream>
#include<cstring>

using namespace std;

Employee:: Employee(const char* new_name, const char* new_dateOfBirth,const char* new_position,double new_salary)
    :Person(new_name,new_dateOfBirth),position(NULL)
{
    this->setPosition(new_position);
    this->setSalary(new_salary);
}
Employee:: Employee(const Employee& other)
    :Person(other),position(NULL)
{
    this->setPosition(other.position);
    this->setSalary(other.salary);
}
Employee& Employee:: operator=(const Employee& other)
{
    if(this!=&other)
    {
        Person:: operator=(other);
        this->setPosition(other.position);
        this->setSalary(other.salary);
    }
    return *this;
}
Employee:: ~Employee()
{
    delete [] this->position;
}

void Employee:: setPosition(const char* new_position)
{
    int length=strlen(new_position);
    if(!length || !new_position)
        throw "Position cannot be empty";
    delete [] this->position;
    this->position=new char[length+1];
    strncpy(this->position,new_position,length+1);
}
void Employee:: setSalary(double salary)
{
    if(salary<0)
        throw "Salary cannot be a negative number";
    this->salary=salary;
}

void Employee:: print() const
{
    Person:: print();
    this->printOwn();

}
void Employee:: printOwn() const
{
    cout<<"Position:"<<this->position<<endl;
    cout<<"Salary:"<<this->salary<<endl;
}

