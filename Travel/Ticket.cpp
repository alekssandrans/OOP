#include "Ticket.h"

#include<iostream>
#include<cstring>

using namespace std;


Ticket:: Ticket(const char* new_startingPoint, const char* new_destination, double new_price, VEHICLE new_transportation)
    :startingPoint(NULL), destination(NULL), price(0.0)
{
    this->setStartingPoint(new_startingPoint);
    this->setDestination(new_destination);
    this->setPrice(new_price);
    this->setTransportation(new_transportation);
}
Ticket:: Ticket(const Ticket& other)
    :Ticket(other.startingPoint,other.destination,other.price,other.transportation)
{
}
Ticket&  Ticket:: operator=(const Ticket& other)
{
    if(this!=&other)
    {
        this->setStartingPoint(other.startingPoint);
        this->setDestination(other.destination);
        this->setPrice(other.price);
        this->setTransportation(other.transportation);
    }
    return *this;
}
Ticket:: ~Ticket()
{
    delete[] this->startingPoint;
    delete[] this->destination;
}

void Ticket:: setStartingPoint(const char* new_startingPoint)
{
    if(!new_startingPoint) new_startingPoint="";
    delete [] this->startingPoint;
    this->startingPoint= new char[strlen(new_startingPoint)+1];
    strcpy(this->startingPoint,new_startingPoint);
}
void Ticket:: setDestination(const char* new_destination)
{
    if(!new_destination) new_destination="";
    delete [] this->destination;
    this->destination= new char[strlen(new_destination)+1];
    strcpy(this->destination,new_destination);
}
void Ticket:: setPrice(double new_price)
{
    if(new_price>0)
        this->price=new_price;
}
void Ticket:: setTransportation(VEHICLE new_transportation)
{
    this->transportation=new_transportation;
}
void Ticket:: printTicket() const
{

    cout<<"Traveling From:"<<this->startingPoint<<endl;
    cout<<"Destination:"<<this->destination<<endl;
    cout<<"Price:"<<this->price<<endl;
    cout<<"Transportation type:";
    switch(this->transportation)
    {
        case train: cout<<"train"; break;
        case airplane: cout<<"airplane"; break;
        case bus: cout<<"bus"; break;
        case car: cout<<"car"; break;
        case ship: cout<<"ship"; break;
    }
    cout<<endl;

}
