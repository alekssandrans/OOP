#include "Professor.h"

#include<iostream>
#include<cstring>

using namespace std;

Professor:: Professor()
    :Person(),students(NULL),studentsCount(0)
{
    this->setMajor("major");
}
Professor:: Professor(const char* new_name, const char* new_dateOfBirth, const char* new_major, const Student* new_students, int new_studentsCount)
    :Person(new_name,new_dateOfBirth), major(NULL), students(NULL)
{
    this->setMajor(new_major);
    this->setStudents(new_students,new_studentsCount);
}
Professor:: Professor(const Professor& other)
    :Person(other),major(NULL)
{
    this->setMajor(other.major);
    this->setStudents(other.students,other.studentsCount);
}
Professor& Professor:: operator=(const Professor& other)
{
    if(this!=&other)
    {
        Person:: operator=(other);
        this->setMajor(other.major);
        this->setStudents(other.students,other.studentsCount);
    }
    return *this;
}
Professor:: ~Professor()
{
    delete [] this->major;
    delete [] this->students;
}

void Professor:: setMajor(const char* new_major)
{
    int length=strlen(new_major);
    if(!length || !new_major)
        throw "Major cannot be empty";
    delete [] this->major;
    this->major=new char[length+1];
    strncpy(this->major,new_major,length+1);
}
void Professor:: setStudents(const Student* new_students,int new_studentsCount)
{
    delete [] this->students;
    this->studentsCount=new_studentsCount;
    this->students=new Student[new_studentsCount];
    for(int i=0;i<new_studentsCount;i++)
    {
        this->students[i]=new_students[i];
    }
}

void Professor:: print() const
{
    Person:: print();
    this->printOwn();

}
void Professor:: printOwn() const
{
    cout<<"Major:"<<this->major<<endl;
    cout<<"Students:"<<endl;
    for(int i=0;i<this->studentsCount;i++)
    {
        students[i]. Student:: print();
    }
}
