#ifndef CHESSPOSITION_H_INCLUDED
#define CHESSPOSITION_H_INCLUDED

#include<iostream>

using namespace std;

class ChessPosition
{
    public:
        ChessPosition(char x='A',char y='1')
        {
            this->setX(x);
            this->setY(y);
        }

        void setX(char x)
        {
            if(x<'A' || x>'H')
                throw "Invalid coordinate";
            this->x=x;
        }
        void setY(char y)
        {
            if(y<'1' || y>'8')
                throw "Invalid coordinate";
            this->y=y;
        }

        char getX()const {return this->x;}
        char getY() const {return this->y;}

        bool operator==(const ChessPosition& left) const
        {
            return this->x==left.x && this->y == left.y;
        }

        void print() const
        {
            cout<<this->x<<this->y;
        }


    private:
        char x;
        char y;

};



#endif // CHESSPOSITION_H_INCLUDED
