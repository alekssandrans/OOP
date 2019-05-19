#ifndef LUGGAGE_H_INCLUDED
#define LUGGAGE_H_INCLUDED


class Luggage
{
    public:
        Luggage(double new_capacity=0, int new_objectsCount=0, double new_weight=0 );

        void setCapacity(double new_capacity);
        void setObjectsCount(int new_objectsCount);
        void setWeight(double new_weight);

        double getCapacity() const { return this->capacity; }
        int getObjectsCount() const { return this->objectsCount; }
        double getWeight() const { return this->weight; }
        int getID() const { return this->ID; }

        void printLuggage() const;

    private:
        double capacity;
        int objectsCount;
        double weight;
        int ID;

        static int generateID;
};
#endif // LUGGAGE_H_INCLUDED
