#ifndef CHESSPIECE_H_INCLUDED
#define CHESSPIECE_H_INCLUDED

#include "ChessPosition.h"


class ChessPiece
{
    public:
        ChessPiece(ChessPosition position=ChessPosition())
        {
            this->setPosition(position.getX(),position.getY());
        }
        virtual ~ChessPiece()
        {
        }

        void setPosition(char x, char y)
        {
            this->position.setX(x);
            this->position.setY(y);
        }
        ChessPosition getPosition() const {return this->position;}

        virtual ChessPosition* allowedMoves() =0;

        bool captures(ChessPosition pos)
        {
            for(int i=0;i<this->getSizeOfAllowedMoves();i++)
            {
                if(pos==this->allowedMoves()[i])
                    return true;
            }
            return false;
        }

        virtual int getSizeOfAllowedMoves()=0;

        virtual const char* getType() const =0;



    private:
        ChessPosition position;


};
#endif // CHESSPIECES_H_INCLUDED
