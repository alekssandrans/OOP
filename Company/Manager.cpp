#include "Manager.h"

#include<iostream>


Manager:: Manager(const char* name, unsigned yearsOfWork,unsigned programsCount,unsigned salesCount,const char* nickname,unsigned sharesCount)
    :Employee(name,yearsOfWork),
     Programmer(name,yearsOfWork,programsCount),
     Seller(name,yearsOfWork,salesCount),
     nickname(NULL),sharesCount(0)
{
    this->setNickName(nickname);
    this->setSharesCount(sharesCount);

}
Manager:: Manager(const Manager& other)
    :Employee(other),
     Programmer(other),
     Seller(other)
{
    this->setNickName(other.nickname);
    this->setSharesCount(other.sharesCount);
}
Manager& Manager:: operator=(const Manager& other)
{
    if(this!=&other)
    {
        Programmer:: operator=(other);
        Seller:: operator=(other);
        this->setNickName(other.nickname);
        this->setSharesCount(other.sharesCount);
    }
    return *this;
}
Manager:: ~Manager()
{
    delete [] this->nickname;
}

void Manager:: setNickName(const char* nickname)
{
    delete [] this->nickname;
    copy(this->nickname,nickname);
}
void Manager:: setSharesCount(unsigned sharesCount)
{
    if(sharesCount>=0)
        this->sharesCount=sharesCount;
}
