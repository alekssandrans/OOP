#ifndef SELLER_H_INCLUDED
#define SELLER_H_INCLUDED

#include "Employee.h"

class Seller : virtual public Employee
{
    public:
        Seller(const char* name="name", unsigned yearsOfWork=0, unsigned salesCount=0)
            :Employee(name,yearsOfWork),salesCount(0)
        {
            this->setSalesCount(salesCount);
        }
        virtual ~Seller()
        {

        }
        void setSalesCount(unsigned salesCount)
        {
            if(salesCount>=0)
                this->salesCount=salesCount;
        }

        unsigned getSalesCount() const {return this->salesCount;}

        virtual unsigned getSalary() const { return this->salesCount*3+100; }

        virtual Employee* clone() const { return new Seller(*this);}

    private:
        unsigned salesCount;


};
#endif // SELLER_H_INCLUDED
