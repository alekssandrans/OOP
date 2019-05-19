#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "ChessPiece.h"

const int maxAllowedMovesKnight=8;

class Knight :public ChessPiece
{
    public:
        Knight(ChessPosition position=ChessPosition())
            :ChessPiece(position),allowedMovesCount(0)
        {
        }
        virtual ChessPosition* allowedMoves() ;

        virtual int getSizeOfAllowedMoves() ;

        virtual const char* getType() const {return "Knight"; }


    private:
        int allowedMovesCount;


};
#endif // KNIGHT_H_INCLUDED
