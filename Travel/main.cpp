#include <iostream>
#include<cstring>

#include "Ticket.h"
#include "Luggage.h"
#include "Passenger.h"
#include "TravelGroup.h"

using namespace std;


int main()
{
    Ticket PlovdivToSofia("Plovdiv", "Sofia", 14, bus);
    Ticket VarnaToSofia("Varna", "Sofia", 30, airplane);
    Luggage Luggage1(20, 30, 15);
    Luggage Luggage2(20,32,16);
    Passenger Ivan("Ivan",Luggage1,PlovdivToSofia);
    Passenger Maria("Maria", Luggage2,VarnaToSofia);

    Ivan.printPassenger();
    Maria.printPassenger();

    cout<<"Maria and Ivan are traveling from the same stop:"<<endl;
    cout<<boolalpha<<Maria.sameStartingPointAs(Ivan)<<endl;
    cout<<"Maria and Ivan are traveling to the same stop:"<<endl;
    cout<<boolalpha<<Maria.sameDestinationAs(Ivan)<<endl;


    Passenger test[3];
    test[0]=Ivan;
    test[1]=Maria;
    Ticket SofiaToBurgas("Sofia","Burgas",10,train);
    Luggage Luggage3(20,28,14);
    test[2].setName("Georgi"); test[2].setPersonalLuggage(Luggage3); test[2].setPersonalTicket(SofiaToBurgas);
    TravelGroup TEST(3,test);

    cout<<endl;
    cout<<"The Travel Group:"<<endl;
    TEST.printTravelGroup();

    TEST.sortByLuggageWeight();
    cout<<"After sorting:"<<endl;
    TEST.printTravelGroup();

    cout<<"Passengers traveling From Varna:"<<endl;
    TEST.PassengersTravelingFrom("Varna");
    cout<<"Passengers traveling From Sofia:"<<endl;
    TEST.PassengersTravelingFrom("Sofia");
    cout<<"Passengers traveling From Plovdiv:"<<endl;
    TEST.PassengersTravelingFrom("Plovdiv");

    cout<<"Passengers traveling to Burgas:"<<endl;
    TEST.PassengersTravelingTo("Burgas");
    cout<<"Passengers traveling to Sofia:"<<endl;
    TEST.PassengersTravelingTo("Sofia");



    return 0;
}
