#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include "Person.h"
#include "Student.h"

class Professor :virtual public Person
{
    public:
        Professor();
        Professor(const char* new_name, const char* new_dateOfBirth, const char* new_major, const Student* new_students, int new_studentsCount);
        Professor(const Professor& other);
        Professor& operator=(const Professor& other);
        ~Professor();

        void setMajor(const char* new_major);
        void setStudents(const Student* new_students,int new_studentsCount);

        const char* getMajor() const {return this->major;}
        const Student* getStudents() const {return this->students;}

        int getStudentsCount() const {return this->studentsCount;}

        void print() const;

        friend Student findMaxGPAStudent(const Professor& professor);

    protected:
        void printOwn() const;

    private:
        char* major;
        Student* students;
        int studentsCount;


};
#endif // PROFESSOR_H_INCLUDED
