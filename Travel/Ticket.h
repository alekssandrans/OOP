#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

enum VEHICLE {train, airplane, bus, car, ship};

class Ticket
{
   public:
      Ticket(const char* new_startingPoint="", const char* new_destination="", double new_price=0.0, VEHICLE new_transportation=(VEHICLE)0 );
      Ticket(const Ticket& other);
      Ticket& operator=(const Ticket& other);
      ~Ticket();

      void setStartingPoint(const char* new_startingPoint);
      void setDestination(const char* new_destination);
      void setPrice(double new_price);
      void setTransportation(VEHICLE new_transportation);

      const char* getStartingPoint() const { return this->startingPoint; }
      const char* getDestination() const { return this->destination; }
      double getPrice() const { return this->price; }
      VEHICLE getTransportation() const{ return this->transportation; }

      void printTicket() const;


    private:
        char* startingPoint;
        char* destination;
        double price;
        VEHICLE transportation;
};
#endif // TICKET_H_INCLUDED
