#include "Manager.h"

class Company
{
    public:
        Company(unsigned capacity=1);
        Company(const Company& other);
        Company& operator=(const Company& other);
        ~Company();

        unsigned getSize() const { return this->size; }
        unsigned getCapacity() const { return this->capacity; }
        Employee** getEmployees() const { return this->employees;}

        void addEmployee(const Employee& employee);
        void removeSales(int salary);
        void removeProgrammer(int salary);
        void removeManager(int salary);
        void removeEmployee(int salary);

    protected:
        void resize();
        void deleteEmployees();
        void copyEmployees(const Company& other);

    private:
        Employee** employees;
        unsigned size;
        unsigned capacity;

};
