#ifndef PIECE_H
#define PIECE_H

#include <set>
#include <tuple>
#include <iostream>

class Piece
{
    public:
        Piece();
        virtual ~Piece();
        char getType();
        void setType(char type);
        char getOwner();
        void setOwner(char owner);
        void init();

        Piece& operator=(const Piece& rhs);

        friend std::ostream& operator<< (std::ostream& os, Piece& p) {

            os << p.getType();
            return os;
        }

    protected:

    private:
        char type_;
        char ownedBy_;

};

#endif // PIECE_H
