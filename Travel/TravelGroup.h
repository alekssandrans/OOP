#ifndef TRAVELGROUP_H_INCLUDED
#define TRAELGROUP_H_INCLUDED

#include "Ticket.h"
#include "Luggage.h"
#include "Passenger.h"

typedef void (*pointerToFunction) (int, Passenger*);

class TravelGroup
{

    public:
        TravelGroup();
        TravelGroup(int new_passengersCount, const Passenger* new_passengers);
        TravelGroup(const TravelGroup& other);
        TravelGroup& operator=(const TravelGroup& other);
        ~TravelGroup();


        void setPassengers(int new_passengersCount, const Passenger* new_passengers);
        int getPassengersCount() const { return this->passengersCount; }

        void sortByLuggageWeight() ;

        void PassengersTravelingFrom(const char* string) const;
        void PassengersTravelingTo(const char* string) const;

        void setP(pointerToFunction new_p) { this->p=new_p;}
        pointerToFunction getP() const {return this->p; }
        void executeP() { p(this->passengersCount, this->passengers);}

        void printTravelGroup() const;

        private:
            int passengersCount;
            Passenger* passengers;

            void swap(Passenger& first, Passenger& second);

            pointerToFunction p;

};

#endif // TRAVELGROUP_H_INCLUDED
