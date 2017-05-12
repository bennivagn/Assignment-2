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
        const int MAXSIZE = 9;

        //Constructor
        Game(int row,int cols);

        //Destructor
        virtual ~Game();

        //Pure virtual
        virtual Player* checkWinner() = 0;
        virtual void legal() = 0;
        virtual void retract() = 0;
        virtual bool move(int from_row,char from_col_char,int to_row,char to_col_char) = 0;

        //Virtual functions
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col) = 0;
        virtual void movePiece(int from_row,int from_col,int to_row,int to_col,bool retract = false);

        //getter
        const int get_num_rows();
        const int get_num_cols();
        bool getDebug();
        Piece& at(int row, int col );
        Player* getPlayer_0();
        Player* getPlayer_1();

        //setter
        void setName(std::string name);
        void setDebug(bool debug);
        std::string getName();

        //bool functions
        bool isEmpty(int row,int col);
        bool onBoard(int row, int col);

        //Mappers
        int mapLetterToInt(char c);
        char mapIntToLetter(int num);


        friend std::ostream& operator<< (std::ostream& os, Game& g);

        virtual void init();


    protected:
        Player player0_;
        Player player1_;
        void switchPlayer();
        Player* currentPlayer_;
        std::stack<std::tuple<int,int,int,int> > moves_;


    private:
        int rows_;
        int cols_;
        bool debug_;
        std::string name_;
        std::vector<Piece*> board_;




};



#endif // GAME_H
