#include "piece.h"

using namespace std;
Piece::Piece()
{
    init();
}

Piece::~Piece()
{

}

Piece& Piece::operator=(const Piece& rhs)
{
    this->type_= rhs.type_;
    this->ownedBy_ = rhs.ownedBy_;

    return *this;
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

void Piece::init()
{
    ownedBy_ = 'b';
    type_ = '.';
}


