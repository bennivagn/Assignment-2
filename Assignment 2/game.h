#ifndef GAME_H
#define GAME_H
#include <piece.h>
#include <vector>
#include <tuple>
#include <ostream>


class Game
{
    public:
        const int MAXSIZE = 9;

        Game(int row,int cols);
        virtual void play() = 0;
        virtual void move(int from_row,char from_col_char,int to_row,char to_col_char) = 0;
        int mapLetterToInt(char c);
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col) = 0;
        virtual void movePiece(int from_row,int from_col,int to_row,int to_col);
        virtual ~Game();
        const int get_num_rows();
        const int get_num_cols();
        friend std::ostream& operator<< (std::ostream& os, Game& g) {
            int count = g.get_num_rows();
            std::string characters = "abcdefghijklmnopqrstuv";
            for ( int row = g.get_num_rows()-1 ; row >= 0; --row )
            {
                os << count << " ";
                count--;
                for ( int col = 0; col < g.get_num_cols() ; ++col )
                {
                    os << g.at(row,col);
                }
                os << std::endl;
            }

            os << "  ";
            for(int i = 0; i < g.get_num_cols(); i++)
            {
                os << characters.at(i);
            }

            return os;
        }

        Piece& at(int row, int col ) {
            if(row <= rows_ && row >= 0 && col <= cols_ && col >= 0)
            {
                return *board_[row * cols_ + col];
            }
            else
            {
                throw new std::out_of_range("Out of range");
            }

        }

    protected:
        std::vector<Piece*> board_;
        virtual void init();
    private:
        int rows_;
        int cols_;

};



#endif // GAME_H
