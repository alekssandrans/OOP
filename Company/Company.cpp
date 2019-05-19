#include "Company.h"

#include<iostream>


void Company:: deleteEmployees()
{
    for(int i=0;i<this->size;i++)
    {
        delete this->employees[i];
    }
    delete [] this->employees;
}
void Company:: copyEmployees(const Company& other)
{
    this->employees=new Employee*[other.capacity];
    for(int i=0;i<other.size;i++)
    {
        this->employees[i]=other.employees[i]->clone();
    }
    this->capacity=other.capacity;
    this->size=other.size;

}
Company:: Company(unsigned capacity)
    :size(0),capacity(capacity)
{
    this->employees =new Employee*[capacity]{NULL};
}
Company:: Company(const Company& other)
{
    this->copyEmployees(other);
}
Company& Company:: operator=(const Company& other)
{
    if(this!=&other)
    {
        this->deleteEmployees();
        this->copyEmployees(other);
    }
    return *this;
}
Company:: ~Company()
{
    this->deleteEmployees();
}
void Company:: resize()
{
    unsigned newCapacity = (this->capacity>0) ? this->capacity * 2 : 1;
    Employee** buffer = new Employee*[newCapacity]{NULL};
    for(int i=0;i<this->size;i++)
    {
        buffer[i]=this->employees[i]->clone();
    }
    this->deleteEmployees();
    this->employees=buffer;
    this->capacity=newCapacity;

}
void Company:: addEmployee(const Employee& employee)
{
    if(size==capacity)
        resize();
    this->employees[size]=employee.clone();
    this->size++;
}
void Company:: removeSales(int salary)
{
    for(int i=0;i<this->size;i++)
    {
        Seller* seller=dynamic_cast<Seller*>(employees[i]);
        if(seller!=NULL)
        {
            if(seller->getSalary()>salary)
            {
                delete seller;
                for(int j=i;j<this->size-1;j++)
                {
                    employees[j]=employees[j+1];
                }
                employees[this->size-1]=NULL;
                --this->size;
            }
        }
    }

}
void Company:: removeProgrammer(int salary)
{
    for(int i=0;i<this->size;i++)
    {
        Programmer* programmer=dynamic_cast<Programmer*>(employees[i]);
        if(programmer!=NULL)
        {
            if(programmer->getSalary()>salary)
            {
                delete programmer;
                for(int j=i;j<this->size-1;j++)
                {
                    employees[j]=employees[j+1];
                }
                employees[this->size-1]=NULL;
                --this->size;
            }
        }
    }
}
void Company::removeManager(int salary)
{
    for(int i=0;i<this->size;i++)
    {
        Manager* manager=dynamic_cast<Manager*>(employees[i]);
        if(manager!=NULL)
        {
            if(manager->getSalary()>salary)
            {
                delete manager;
                for(int j=i;j<this->size-1;j++)
                {
                    employees[j]=employees[j+1];
                }
                employees[this->size-1]=NULL;
                --this->size;
            }
        }
    }
}
void Company:: removeEmployee(int salary)
{
    for(int i=0;i<this->size;i++)
    {
        Seller* seller=dynamic_cast<Seller*>(employees[i]);
        Programmer* programmer=dynamic_cast<Programmer*>(employees[i]);
        Manager* manager=dynamic_cast<Manager*>(employees[i]);
        if(seller==NULL && programmer==NULL && manager==NULL)
        {
            if(employees[i]->getSalary()>salary)
            {
                delete seller;
                delete programmer;
                delete manager;
                for(int j=i;j<this->size-1;j++)
                {
                    employees[j]=employees[j+1];
                }
                employees[this->size-1]=NULL;
                --this->size;
            }
        }
    }
}
