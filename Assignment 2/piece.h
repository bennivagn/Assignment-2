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
        bool isLegal(std::tuple<int,int> move);
        void setLegalMoves(std::set<std::tuple<int,int> >& moves);
        std::tuple<int,int> getLocation();
        void setLocation(std::tuple<int,int> newlocation);
        char getType();
        void setType(char type);
        char getOwner();
        void setOwner(char owner);

        friend std::ostream& operator<< (std::ostream& os, Piece& p) {

            os << p.getType();
            return os;
        }

    protected:

    private:
        std::set<std::tuple<int,int> > legalmoves_;
        std::tuple <int,int> location_;
        char type_;
        char ownedBy_;

};

#endif // PIECE_H
