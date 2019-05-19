#ifndef PROGRAMMER_H_INCLUDED
#define PROGRAMMER_H_INCLUDED

#include "Employee.h"

class Programmer: virtual public Employee
{
    public:
        Programmer(const char* name="name",unsigned yearsOfWork=0,unsigned programsCount=0)
            :Employee(name,yearsOfWork),programsCount(0)
        {
            this->setProgramsCount(programsCount);
        }
        virtual ~Programmer()
        {

        }

        void setProgramsCount(unsigned programsCount)
        {
            if(programsCount>=0)
                this->programsCount=programsCount;
        }

        unsigned getProgramsCount() const {return this->programsCount;}

        virtual unsigned getSalary() const { return this->programsCount+200;}

        virtual Employee* clone() const { return new Programmer(*this);}


    private:
        unsigned programsCount;

};
#endif // PROGRAMMER_H_INCLUDED
