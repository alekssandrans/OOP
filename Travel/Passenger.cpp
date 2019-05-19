#include "Passenger.h"

#include<iostream>
#include<cstring>

using namespace std;

int Passenger:: passengersCount=0;


Passenger:: Passenger(const char* new_name, const Luggage& new_personalLuggage, const Ticket& new_personalTicket)
    :name(NULL),personalLuggage(new_personalLuggage), personalTicket(new_personalTicket)
{
    this->setName(new_name);

    passengersCount++;

}
Passenger:: Passenger(const Passenger& other)
    :Passenger(other.name,other.personalLuggage,other.personalTicket)
{
}
Passenger& Passenger:: operator=(const Passenger& other)
{
    if(this!=&other)
    {
        this->setName(other.name);
        this->setPersonalLuggage(other.personalLuggage);
        this->setPersonalTicket(other.personalTicket);
    }
    return *this;
}
Passenger:: ~Passenger()
{
    delete[] this->name;

    passengersCount--;
}

void Passenger:: setName(const char* new_name)
{
    if(!new_name) new_name="";
    delete [] this->name;
    this->name=new char[strlen(new_name)+1];
    strcpy(this->name,new_name);
}
void Passenger:: setPersonalLuggage(const Luggage& new_personalLuggage)
{
    this->personalLuggage=new_personalLuggage;
}
void Passenger:: setPersonalTicket(const Ticket& new_personalTicket)
{
    this->personalTicket=new_personalTicket;
}
bool Passenger:: sameStartingPointAs(const Passenger& other)
{
    if(strcmp(this->getPersonalTicket().getStartingPoint(),other.getPersonalTicket().getStartingPoint())==0)
        return true;
    else return false;
}
bool Passenger:: sameDestinationAs(const Passenger& other)
{
    if(strcmp(this->getPersonalTicket().getDestination(),other.getPersonalTicket().getDestination())==0)
        return true;
    else return false;
}
void Passenger:: printPassenger() const
{
    cout<<"--------------------------"<<endl;
    cout<<"Name:"<<this->name<<endl;
    this->personalLuggage.printLuggage();
    this->personalTicket.printTicket();
    cout<<"--------------------------"<<endl;
}
