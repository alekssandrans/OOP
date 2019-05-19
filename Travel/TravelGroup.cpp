#include "TravelGroup.h"

#include<iostream>
#include<cstring>

using namespace std;

TravelGroup:: TravelGroup()
    :passengers(NULL), passengersCount(0)
{
}
TravelGroup:: TravelGroup(int new_passengersCount, const Passenger* new_passengers)
    :passengers(NULL)
{
    this->passengersCount=new_passengersCount;
    this->passengers=new Passenger[passengersCount];
    for(int i=0;i<passengersCount;i++)
    {
        this->passengers[i]=new_passengers[i];
    }
}
TravelGroup:: TravelGroup(const TravelGroup& other)
    :TravelGroup(other.passengersCount,other.passengers)
{
}
TravelGroup& TravelGroup:: operator=(const TravelGroup& other)
{
    if(this!=&other)
    {
        this->setPassengers(other.passengersCount,other.passengers);
    }
    return *this;
}
TravelGroup:: ~TravelGroup()
{
    delete[] passengers;
}
void TravelGroup:: setPassengers(int new_passengersCount, const Passenger* new_passengers)
{
    delete[] this->passengers;
    this->passengersCount=new_passengersCount;
    this->passengers=new Passenger[passengersCount];
    for(int i=0;i<passengersCount;i++)
    {
        this->passengers[i]=new_passengers[i];
    }
}

void TravelGroup:: swap(Passenger& first, Passenger& second)
{
    Passenger temp=first;
    first=second;
    second=temp;
}
void TravelGroup:: sortByLuggageWeight()
{
    int i,j, min_index;
    for(i=0;i<passengersCount-1;i++)
    {
        min_index=i;
        for(j=i+1;j<passengersCount;j++)
        {
            if(passengers[j].getPersonalLuggage().getWeight()<passengers[min_index].getPersonalLuggage().getWeight())
                min_index=j;
        }
        if(min_index!=i)
        {
            swap(passengers[i],passengers[min_index]);
        }
    }
}
void TravelGroup:: PassengersTravelingFrom(const char* string) const
{
    for(int i=0;i<passengersCount;i++)
    {
        if(strcmp(passengers[i].getPersonalTicket().getStartingPoint(),string)==0)
            cout<<passengers[i].getName()<<endl;
    }
    cout<<endl;
}
void TravelGroup:: PassengersTravelingTo(const char* string) const
{
    for(int i=0;i<passengersCount;i++)
    {
         if(strcmp(passengers[i].getPersonalTicket().getDestination(),string)==0)
            cout<<passengers[i].getName()<<endl;
    }
    cout<<endl;

}
void TravelGroup:: printTravelGroup() const
{
    for(int i=0;i<this->passengersCount;i++)
    {
        this->passengers[i].printPassenger();
    }
}
