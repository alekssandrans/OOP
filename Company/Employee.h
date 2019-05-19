#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

class Employee
{
    public:
        Employee(const char* name="name", unsigned yearsOfWork=0);
        Employee(const Employee& other);
        Employee& operator=(const Employee& other);
        virtual ~Employee();

        void setName(const char* name);
        void setYearsOfWork(unsigned yearsOfWork);

        const char* getName() const {return this->name;}
        unsigned getYearsOfWork() const {return this->yearsOfWork;}

        virtual unsigned getSalary() const {return 2*this->yearsOfWork+500;}

        virtual Employee* clone() const { return new Employee(*this);}

    protected:
        void copy(char*& dest, const char* src );

    private:
        char* name;
        unsigned yearsOfWork;


};
#endif // EMPLOYEE_H_INCLUDED
