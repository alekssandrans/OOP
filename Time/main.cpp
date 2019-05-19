#include <iostream>
#include<iomanip>
const unsigned short MAX_COUNT=3;
using namespace std;


class Time
{
private:
    unsigned short seconds, minutes, hours;
public:
    Time();
    Time(unsigned short, unsigned short, unsigned short);
    bool isValidTime (unsigned short, unsigned short, unsigned short) const;
    void read();
    void print();
    void setSec(unsigned short);
    void setMin(unsigned short);
    void setHrs(unsigned short);
    unsigned getSec() const;
    unsigned getMin() const;
    unsigned getHrs() const;
    bool compareTime(Time& ) const;
    bool isSmaller(Time& ) const;
    friend class Test;
    friend void anotherTest();


};
void anotherTest()
{
    Time t;
    cout<<t.minutes;

}
class Test
{
public:
    void aTest()
    {
        Time t;
        cout<<t.minutes;
    }
    private:
        int test1;
};


Time:: Time()
{
    seconds=0;
    minutes=0;
    hours=0;
}
Time:: Time (unsigned short sec, unsigned short min, unsigned short hrs)
{
    seconds=sec;
    minutes=min;
    hours=hrs;
}
bool Time:: isValidTime (unsigned short sec, unsigned short min, unsigned short hrs) const
{
    return sec>=0 && sec<=60 && min>=0 && min<=60 && hrs>=0 && hrs<=24;
}

void Time:: read()
{
    do
    {
        cout<<"Time [hrs/min/sec]:"<<endl;
        cin>>hours>>minutes>>seconds;
    }
    while(!(isValidTime(seconds, minutes, hours)));
}
void Time:: print()
{
    if (hours==24) hours=0;
    cout<<setw(2)<<setfill('0')<<hours<<":"<<setw(2)<<setfill('0')<<minutes<<":"<<setw(2)<<setfill('0')<<seconds<<endl;
}
void Time:: setSec(unsigned short sec)
{
    if (isValidTime(sec, minutes, hours)) seconds=sec;
}
void Time:: setMin(unsigned short min)
{
    if (isValidTime(seconds, min, hours)) minutes=min;
}
void Time:: setHrs(unsigned short hrs)
{
    if (isValidTime(seconds, minutes, hrs)) hours=hrs;
}
unsigned Time:: getSec() const
{
    return seconds;
}
unsigned Time:: getMin() const
{
    return minutes;
}
unsigned Time:: getHrs() const
{
    return hours;
}
bool Time:: compareTime(Time& other) const
{
    return seconds==other.seconds && minutes==other.minutes && hours==other.hours;
}
bool Time:: isSmaller(Time& t) const
{

    if(hours<t.hours) return true;
    if(hours==t.hours)
    {
        if(minutes<t.minutes) return true;
        if(minutes==t.minutes)
        {
            if(seconds<t.seconds) return true;
        }
    }
    return false;
}
void sortTime(Time* t, int n)
{

    for(int i=0;i<n-1;i++)
    {
        Time minT=t[i];
        unsigned short minIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(t[j].isSmaller(minT))
            {
                minT=t[j];
                minIndex=j;
            }
        }
        Time swap=t[i];
        t[i]=t[minIndex];
        t[minIndex]=swap;
    }

}

Time* removeTheSmallest(Time* t, int n)
{
    sortTime(t,n);
    for(int i=0;i<n-1;i++)
    {
        t[i]=t[i+1];
    }
    n--;
    return t;
}
/* void removeTheSmallest(Time* t, int n)
{
    sortTime(t,n);
    for(int i=0;i<n-1;i++)
    {
        t[i]=t[i+1];
    }
    n--;
} */
int main()

{
   Time t[MAX_COUNT];
   for(int i=0;i<MAX_COUNT;i++)
   {
       t[i].read();
   }

    sortTime(t, MAX_COUNT);

    for(int i=0;i<MAX_COUNT;i++)
    {
       t[i].print();
    }
    for(int i=0;i<MAX_COUNT-1;i++)
    {

        removeTheSmallest(t,MAX_COUNT)[i].print();
    }


    return 0;
}
