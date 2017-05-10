#include "piece.h"

using namespace std;
Piece::Piece()
{
    ownedBy_ = 'b';
    type_ = '.';
}

Piece::~Piece()
{

}

bool Piece::isLegal(tuple<int, int>move)
{
    //TODO
    return true;
}

void Piece::setLegalMoves(set<tuple<int, int>>& moves)
{
    //TODO
}

tuple<int,int> Piece::getLocation()
{
    return location_;
}

void Piece::setLocation(tuple<int, int>newlocation)
{
    location_ = newlocation;
}


char Piece::getType()
{
    return type_;
}

char Piece::getOwner()
{
    return ownedBy_;
}
void Piece::setType(char type)
{
    type_ = type;
}

void Piece::setOwner(char owner)
{
    ownedBy_ = owner;
}


