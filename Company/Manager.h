#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "Programmer.h"
#include "Seller.h"

class Manager : public Programmer, public Seller
{
   public:
       Manager(const char* name="name", unsigned yearsOfWork=0,unsigned programsCount=0,unsigned salesCount=0,const char* nickname="nickname",unsigned sharesCount=0);
       Manager(const Manager& other);
       Manager& operator=(const Manager& other);
       virtual ~Manager();

       void setNickName(const char* nickname);
       void setSharesCount(unsigned sharesCount);

       const char* getNickname() const { return this->nickname; }
       unsigned getSharesCount() const { return this->sharesCount; }

       virtual unsigned getSalary() const { return this->sharesCount*3+1000; }

       virtual Employee* clone() const { return new Manager(*this);}


    private:
        char* nickname;
        unsigned sharesCount;



};



#endif // MANAGER_H_INCLUDED
