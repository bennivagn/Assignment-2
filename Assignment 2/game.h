#ifndef GAME_H
#define GAME_H
#include <piece.h>
#include <vector>
#include <ostream>


class Game
{
    public:
        Game(int row,int cols);
        virtual void play();
        virtual ~Game();
        const int MAXSIZE = 9;

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
            return *board_[row * cols_ + col];
        }

    protected:
        std::vector<Piece*> board_;
    private:
        int rows_;
        int cols_;

};



#endif // GAME_H
