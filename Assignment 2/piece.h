#ifndef PIECE_H
#define PIECE_H

#include <set>
#include <tuple>
#include <iostream>
#include <player.h>

class Piece
{
    public:

        /** \brief Default constructor for the Piece class
        */
        Piece();

        /** \brief Default destructor for the Piece class
        */
        virtual ~Piece();

        /** \brief Returns the type of piece
            \return char
        */
        char getType();

        /** \brief Sets the type of piece
            @param char type, new type
        */
        void setType(char type);

        /** \brief Returns a pointer that points to the player that owns this piece
            \return Player*
        */
        Player* getOwner();

        /** \brief Sets the owner variable with a pointer to the new owner
            @param Player* owner, new owner of the piece
        */
        void setOwner(Player* owner);

       /** \brief initializes all variables to default values and a default type '.'
        */
        void init();

        /** \brief Overload the assignment operator
        */
        Piece& operator=(const Piece& rhs);

        /** \brief Overload the << operator to write out the type of piece
        *   @param ostream& os is the output stream
        *   @param Piece& p is the piece that is printed out
        *   \return ostream&
        */

        friend std::ostream& operator<< (std::ostream& os, Piece& p) {
            os << p.getType();
            return os;
        }

    protected:

    private:
        /** \brief char variable that stores the type of piece
        */
        char type_;

        /** \brief Player pointer that points to the owner of the piece
        */
        Player* ownedBy_;

};

#endif // PIECE_H
