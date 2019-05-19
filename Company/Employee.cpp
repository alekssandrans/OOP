#include "Employee.h"

#include<iostream>
#include<cstring>
#include<cassert>


void Employee:: copy(char*& dest, const char* src)
{
    int length=strlen(src);

    if(!src || !length)
        throw "Invalid data";

    dest= new char[length+1];
    assert(dest);
    strncpy(dest,src,length+1);
}
void Employee:: setName(const char* name)
{
    delete [] this->name;
    copy(this->name,name);
}
void Employee:: setYearsOfWork(unsigned yearsOfWork)
{
    if(yearsOfWork>=0)
        this->yearsOfWork=yearsOfWork;
}
Employee:: Employee(const char* name, unsigned yearsOfWork)
    :name(NULL), yearsOfWork(0)
{
    this->setName(name);
    this->setYearsOfWork(yearsOfWork);

}
Employee:: Employee(const Employee& other)
    :Employee(other.name,other.yearsOfWork)
{
}
Employee& Employee:: operator=(const Employee& other)
{
    if(this!=&other)
    {
        this->setName(other.name);
        this->setYearsOfWork(other.yearsOfWork);
    }
    return *this;
}
Employee:: ~Employee()
{
    delete [] this->name;
}
