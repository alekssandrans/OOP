#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED

#include "Ticket.h"
#include "Luggage.h"

class Passenger
{
    public:
        Passenger(const char* new_name="", const Luggage& new_personalLuggage=Luggage(), const Ticket& new_personalTicket=Ticket());
        Passenger(const Passenger& other);
        Passenger& operator=(const Passenger& other);
        ~Passenger();

        void setName(const char* new_name);
        void setPersonalLuggage(const Luggage& new_personalLuggage);
        void setPersonalTicket(const Ticket& new_personalTicket);

        const char* getName() const { return this->name; }
        Luggage getPersonalLuggage() const {return this->personalLuggage; }
        Ticket getPersonalTicket() const { return this->personalTicket; }
        static int getCurrentPassengersCount() { return passengersCount; }

        bool sameStartingPointAs(const Passenger& other);
        bool sameDestinationAs(const Passenger& other);

        void printPassenger() const;
    private:
        char* name;
        Luggage personalLuggage;
        Ticket personalTicket;

        static int passengersCount;
};
#endif // PASSENGER_H_INCLUDED
