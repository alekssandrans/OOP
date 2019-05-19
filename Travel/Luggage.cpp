#include "Luggage.h"

#include<iostream>
#include<cstring>

using namespace std;

int Luggage:: generateID=0;


Luggage:: Luggage(double new_capacity, int new_objectsCount, double new_weight )
    :capacity(0),objectsCount(0),weight(0)
{
    generateID++;
    ID=generateID;

    this->setCapacity(new_capacity);
    this->setObjectsCount(new_objectsCount);
    this->setWeight(new_weight);

}

void Luggage:: setCapacity(double new_capacity)
{
    if (new_capacity>0)
        this->capacity=new_capacity;

}
void Luggage:: setObjectsCount(int new_objectsCount)
{
    if(new_objectsCount>0)
        this->objectsCount=new_objectsCount;
}
void Luggage:: setWeight(double new_weight)
{
    if(new_weight>0)
        this->weight=new_weight;
}
void Luggage:: printLuggage() const
{
    cout<<"Luggage ID:"<<this->ID<<endl;
    cout<<"Capacity:"<<this->capacity<<endl;
    cout<<"Objects:"<<this->objectsCount<<endl;
    cout<<"Weight:"<<this->weight<<endl;
}
