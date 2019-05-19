#include <iostream>
#include<cstring>

#include "Dean.h"

using namespace std;

Student findMaxGPAStudent(const Professor& professor)
{
    Student maxGPAStudent=professor.students[0];
    for(int i=1;i<professor.studentsCount;i++)
    {
        if(professor.students[i].getGPA()>maxGPAStudent.getGPA())
            maxGPAStudent=professor.students[i];
    }
    return maxGPAStudent;
}
bool findDean(const Professor* professors,int professorsCount, const Dean& dean)
{
    bool answer=false;
    for(int i=0;i<professorsCount&&(!answer);i++)
    {
        if(strcmp(professors[i].getName(),dean.getName())==0)
            answer=true;
    }
    return answer;
}
int main()
{
    Student students[3];
    students[0].setName("Ivan");
    students[0].setDateOfBirth("19970305");
    students[0].setFacultyNumber(20357);
    students[0].setGPA(5.4);
    students[1].setName("Maria");
    students[1].setDateOfBirth("19980612");
    students[1].setFacultyNumber(20358);
    students[1].setGPA(5.6);
    students[2].setName("Georgi");
    students[2].setDateOfBirth("19980111");
    students[2].setFacultyNumber(20359);
    students[2].setGPA(4.8);

    Professor test("Test","12345678","Math",students,3);

    cout<<"Professor Test:"<<endl;
    test.print();

    Student best=findMaxGPAStudent(test);

    cout<<endl<<"Highest GPA from the group:"<<endl;
    best.print();
    cout<<endl;

    Professor professors[2];
    professors[0].setName("First");
    professors[0].setDateOfBirth("12345678");
    professors[0].setMajor("Math");
    professors[0].setStudents(students,3);
    professors[1].setName("Second");
    professors[1].setDateOfBirth("12345678");
    professors[1].setMajor("Math");
    professors[1].setStudents(students,3);


    Dean dean("Second","12345678","Math",students,3,"dean",2500);

    cout<<"Is the dean among the professors:"<<endl;
    cout<<"---------------------------------"<<endl;
    professors[0].print();
    cout<<"---------------------------------"<<endl;
    professors[1].print();
    cout<<"---------------------------------"<<endl;

    cout<<endl;
    cout<<"Answer:"<<boolalpha<<findDean(professors,2,dean)<<endl;



    return 0;
}
