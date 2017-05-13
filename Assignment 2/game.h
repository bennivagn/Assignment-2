#ifndef GAME_H
#define GAME_H
#include <piece.h>
#include <vector>
#include <tuple>
#include <ostream>
#include <player.h>
#include <stack>


class Game
{
    public:
        //Constant

        /** \brief Max size of game board
        *
        */
        const int MAXSIZE = 9;

        //Constructor
        /** \brief Constructor for the base Game class
        *   @param int row size for the game board
            @param int col size for the game board
        */
        Game(int row,int cols);

        //Destructor
        /** \brief Destructor for the base Game class
        */
        virtual ~Game();

        //Pure virtual
        /** \brief A pure virtual function. Checks the board to see if a player has won.
            \return Player* is the player that won, returns nullptr if no one has won
        */
        virtual Player* checkWinner() = 0;

        /** \brief Finds all legal moves from the position of the current player
        *   \return <vector<string> legalmoves. Vector of legal moves
        */
        virtual std::vector<std::string> legal() = 0;

        /** \brief Retracts the last legal move that was made
        */
        virtual void retract() = 0;

        /** \brief This function moves the pieces
        *   @param int from_row row that is being moved from
        *   @param int from_col column that is being moved from
        *   @param int to_row row that is being moved to
        *   @param int to_col column that is being moved to
        */
        virtual bool move(int from_row,char from_col_char,int to_row,char to_col_char) = 0;

        /** \brief Checks whether a move is legal
        *   @param int from_row row that is being moved from
        *   @param int from_col column that is being moved from
        *   @param int to_row row that is being moved to
        *   @param int to_col column that is being moved to
        */
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col) = 0;

        //Virtual functions

        /** \brief This function moves the piece. The function is called in all derived move functions
        *   @param int from_row row that is being moved from
        *   @param int from_col column that is being moved from
        *   @param int to_row row that is being moved to
        *   @param int to_col column that is being moved to
        *   @param bool retract specifies whether the move is a retract or not
        */
        virtual void movePiece(int from_row,int from_col,int to_row,int to_col,bool retract = false);

        //getter
        /** \brief returns the number of rows in the board
        * \return const int
        */
        const int get_num_rows();

        /** \brief returns the number of columns in the board
        * \return const int
        */
        const int get_num_cols();

        /** \brief returns the value of the debug variable
        * \return bool
        */
        bool getDebug();

        /** \brief returns the piece at row and col location in the board
        * @param int row number
        * @param int col number
        * \return Piece& returns a reference to the piece the function found
        */
        Piece& at(int row, int col );

        /** \brief getter for player_0
        *   \return Player* returns a player pointer
        */
        Player* getPlayer_0();

        /** \brief getter for player_1
        *   \return Player* returns a player pointer
        */
        Player* getPlayer_1();

        /** \brief getter for current player
        *   \return Player* returns a player pointer
        */
        Player* getCurrentPlayer();

        //setter
        /** \brief sets the name of the game
        *   @param string name of the game
        */
        void setName(std::string name);

        /** \brief sets the debug value
        *   @param bool new value for debug
        */
        void setDebug(bool debug);

        /** \brief gets the name of the game
        *   \return string returns the name of the game
        */
        std::string getName();

        //bool functions
        /** \brief Finds out if the board at row and col is empty
        *   @param int row location
        *   @param int col location
        *   \return bool
        */
        bool isEmpty(int row,int col);

        /** \brief Finds out if the board at row and col is within the board boundries
        *   @param int row location
        *   @param int col location
        *   \return bool
        */
        bool onBoard(int row, int col);

        //Mappers
        /** \brief Converts a letter to column number
        *   \return int col number
        */
        int mapLetterToInt(char c);

         /** \brief Converts an int to a letter
        *   \return char letter
        */
        char mapIntToLetter(int num);

        /** \brief Overloaded operator for cout
        *   @param ostream& os is the output stream
        *   @param Game& g is the game the that is printed out
        *   \return ostream&
        */
        friend std::ostream& operator<< (std::ostream& os, Game& g);


        //Void functions
         /** \brief Initializes all variables and resets the board with empty pieces
        */
        virtual void init();


    protected:
        /** \brief Switches the currentplayer variable
        */
        void switchPlayer();

        /** \brief Returns the number of pieces on the board the player owns
        *   @param Player& player
        *   \return int number of remaining pieces
        */
        int remainingPieces(Player&  player);

        /** \brief Variable for player 0
        */
        Player player0_;

        /** \brief Variable for player 1
        */
        Player player1_;

        /** \brief This variable holds a pointer of the current player that should play
        */
        Player* currentPlayer_;

        /** \brief A stack of tuples that contain all moves that were made and were legal,
        */
        std::stack<std::tuple<int,int,int,int,Piece> > moves_;
        bool gameWon_;


    private:
        int rows_;
        int cols_;
        bool debug_;
        std::string name_;

        /** \brief The game board
        */
        std::vector<Piece*> board_;




};



#endif // GAME_H
