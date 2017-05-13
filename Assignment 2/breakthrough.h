#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include <game.h>

class Breakthrough : public Game
{
    public:

        /** \brief Default constructor for the Breakthrough class
        */
        Breakthrough();

        /** \brief Default destructor for the Breakthrough class
        */
        virtual ~Breakthrough();

        /** \brief initializes all variables and sets the right player pieces on the board for the game to work
        */
        virtual void init();

        /** \brief This function moves the pieces
        *   @param int from_row row that is being moved from
        *   @param int from_col column that is being moved from
        *   @param int to_row row that is being moved to
        *   @param int to_col column that is being moved to
        */
        virtual bool move(int from_row,char from_col_char,int to_row,char to_col_char);

        /** \brief Checks the board to see if a player has won.
            \return Player* is the player that won, returns nullptr if no one has won
        */
        virtual Player* checkWinner();

        /** \brief Finds all legal moves from the position of the current player
        *   \return <vector<string> legalmoves. Vector of legal moves
        */
        virtual std::vector<std::string> legal();

        /** \brief Retracts the last legal move that was made
        */
        virtual void retract();


    protected:

    private:
        /** \brief Checks whether a move is legal
        *   @param int from_row row that is being moved from
        *   @param int from_col column that is being moved from
        *   @param int to_row row that is being moved to
        *   @param int to_col column that is being moved to
        */
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col);

};

#endif // BREAKTHROUGH_H
