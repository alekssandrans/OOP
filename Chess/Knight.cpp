#include "Knight.h"



ChessPosition* Knight:: allowedMoves()
{
    ChessPosition allowedMoves[maxAllowedMovesKnight];

    int count=0;
    char x=this->getPosition().getX();
    char y=this->getPosition().getY();

    x=x+2;
    y=y+1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    x=x+2;
    y=y-1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    x=x-2;
    y=y+1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    x=x-2;
    y=y-1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    y=y+2;
    x=x+1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    y=y+2;
    x=x-1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    y=y-2;
    x=x+1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }
    x=this->getPosition().getX();
    y=this->getPosition().getY();

    y=y-2;
    x=x-1;
    if(x>='A' && x<='H' && y>='1' && y<='8')
    {
        allowedMoves[count]=ChessPosition(x,y);
        //cout<<allowedMoves[count].getX()<<allowedMoves[count].getY()<<endl;
        count++;
    }

    this->allowedMovesCount=count;

    return allowedMoves;


}
int Knight:: getSizeOfAllowedMoves()
{
    this->allowedMoves();
    return this->allowedMovesCount;
}

