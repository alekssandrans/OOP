#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include "ChessPiece.h"

const int MaxAllowedMovesRook=14;

class Rook : public ChessPiece
{
    public:
        Rook(ChessPosition position=ChessPosition())
            :ChessPiece(position)
        {
        }

        virtual ChessPosition* allowedMoves() ;

        virtual int getSizeOfAllowedMoves() ;

        virtual const char* getType() const {return "Rook" ;}


};
#endif // ROOK_H_INCLUDED
