#include <iostream>

#include "Company.h"

using namespace std;

int main()
{
    Employee A("A",0);
    Seller B("B",1,500);
    Programmer C("C",4,1000);
    Manager D("D",9,10000,15000,"DD",20);


    Company myCompany(2);
    myCompany.addEmployee(A);
    myCompany.addEmployee(B);
    myCompany.addEmployee(C);
    myCompany.addEmployee(D);

    cout<<A.getSalary()<<endl;
    cout<<B.getSalary()<<endl;
    cout<<C.getSalary()<<endl;
    cout<<D.getSalary()<<endl;

    myCompany.removeEmployee(400);
    cout<<myCompany.getSize()<<endl;

    cout<<myCompany.getEmployees()[0]->getName()<<endl;
    cout<<myCompany.getEmployees()[1]->getName()<<endl;
    cout<<myCompany.getEmployees()[2]->getName()<<endl;


    return 0;
}
