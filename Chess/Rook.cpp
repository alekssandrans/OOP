#include "Rook.h"

ChessPosition* Rook:: allowedMoves()
{
    ChessPosition allowedMoves[MaxAllowedMovesRook];
    int count=0;
    char x=this->getPosition().getX();
    char y=this->getPosition().getY();

    //cout<<"x- rightwards"<<endl;
    while(x!='H')
    {
        x=(char)(x+1);
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();

    //cout<<"x- leftwards"<<endl;
    while(x!='A')
    {
        x=(char)(x-1);
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();

    //cout<<"y-upwards"<<endl;
    while(y!='8')
    {
        y=char(y+1);
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    y=this->getPosition().getY();

    //cout<<"y-downwards"<<endl;
    while(y!='1')
    {
        y=char(y-1);
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }

    return allowedMoves;

}
int Rook:: getSizeOfAllowedMoves()
{
    return MaxAllowedMovesRook;
}

