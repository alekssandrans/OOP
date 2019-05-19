#include <iostream>

#include "Rook.h"
#include "Knight.h"

using namespace std;

void allMoves(ChessPiece** pieces, int count)
{
    cout<<pieces[0]->getType()<<endl;
    for(int i=0;i<pieces[0]->getSizeOfAllowedMoves();i++)
    {
        pieces[0]->getPosition().print(); cout<<"->"; pieces[0]->allowedMoves()[i].print(); cout<<endl;

    }
    cout<<endl;

    for(int i=1;i<count;i++)
    {
        ChessPiece* previous=pieces[i-1];

        cout<<pieces[i]->getType()<<endl;
        for(int j=0;j<pieces[i]->getSizeOfAllowedMoves();j++)
        {
            if(!previous->captures(pieces[i]->allowedMoves()[j]))
            {
                pieces[i]->getPosition().print(); cout<<"->"; pieces[i]->allowedMoves()[j].print(); cout<<endl;
            }
        }
        cout<<endl;
    }


}


int main()
{

    ChessPosition A1('A', '1');
    ChessPosition D2('D', '2');
    ChessPosition C1('C', '1');
    ChessPosition G3('G','3');

    Rook R1(A1);
    Rook R2(D2);
    Knight K1(C1);
    Knight K2(G3);

    cout<<"---"<<endl;
    cout<<"R1:"<<endl;
    cout<<"---"<<endl;
    cout<<"Type: "<<R1.getType()<<endl;
    cout<<"Position: "; R1.getPosition().print(); cout<<endl;
    cout<<"Allowed moves:"<<endl;
    for(int i=0;i<R1.getSizeOfAllowedMoves();i++)
    {
        R1.allowedMoves()[i].print(); cout<<endl;
    }
    cout<<"Total: "<<R1.getSizeOfAllowedMoves()<<endl;

    cout<<"---"<<endl;
    cout<<"R2:"<<endl;
    cout<<"---"<<endl;
    cout<<"Type: "<<R2.getType()<<endl;
    cout<<"Position: "; R2.getPosition().print(); cout<<endl;
    cout<<"Allowed moves:"<<endl;
    for(int i=0;i<R2.getSizeOfAllowedMoves();i++)
    {
        R2.allowedMoves()[i].print(); cout<<endl;
    }
    cout<<"Total: "<<K1.getSizeOfAllowedMoves()<<endl;

    cout<<"---"<<endl;
    cout<<"K1:"<<endl;
    cout<<"---"<<endl;
    cout<<"Type: "<<K1.getType()<<endl;
    cout<<"Position: "; K1.getPosition().print(); cout<<endl;
    cout<<"Allowed moves:"<<endl;
    for(int i=0;i<K1.getSizeOfAllowedMoves();i++)
    {
        K1.allowedMoves()[i].print(); cout<<endl;
    }
    cout<<"Total: "<<K1.getSizeOfAllowedMoves()<<endl;

    cout<<"---"<<endl;
    cout<<"K2:"<<endl;
    cout<<"---"<<endl;
    cout<<"Type: "<<K2.getType()<<endl;
    cout<<"Position: "; K2.getPosition().print(); cout<<endl;
    cout<<"Allowed moves:"<<endl;
    for(int i=0;i<K2.getSizeOfAllowedMoves();i++)
    {
        K2.allowedMoves()[i].print(); cout<<endl;
    }
    cout<<"Total: "<<K2.getSizeOfAllowedMoves()<<endl;



    ChessPiece* pieces[4];
    pieces[0]=&R1;
    pieces[1]=&R2;
    pieces[2]=&K1;
    pieces[3]=&K2;

    cout<<endl<<"All moves:"<<endl;

    cout<<endl;
    allMoves(pieces,4);







    return 0;
}
