#include "Person.h"

#include<iostream>
#include<cstring>

using namespace std;

Person:: Person(const char* new_name, const char* new_dateOfBirth)
    :name(NULL)
{
    this->setName(new_name);
    this->setDateOfBirth(new_dateOfBirth);

}
Person:: Person(const Person& other)
    :Person(other.name,other.dateOfBirth)
{

}
Person& Person:: operator=(const Person& other)
{
    if(this!=&other)
    {
        this->setName(other.name);
        this->setDateOfBirth(other.dateOfBirth);
    }
    return *this;
}
Person:: ~Person()
{
    delete [] this->name;

}

void Person:: setName(const char* new_name)
{
    int length=strlen(new_name);
    if(!new_name || !length)
        throw "Name cannot be empty";
    delete [] this->name;
    this->name=new char[length+1];
    strncpy(this->name,new_name,length+1);
}
void Person:: setDateOfBirth(const char* new_dateOfBirth)
{
    if(this->isValidDate(new_dateOfBirth))
        strcpy(this->dateOfBirth,new_dateOfBirth);
    else throw "Invalid Date";
}

void Person:: print() const
{
    cout<<"Name:"<<this->name<<endl;
    cout<<"Date of Birth:"<<this->dateOfBirth<<endl;
}

bool Person:: isValidDate(const char* date)
{
    if (strlen(date)!=8) return false;

    return true;
}
