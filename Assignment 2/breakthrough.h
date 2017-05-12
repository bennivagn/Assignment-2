#ifndef BREAKTHROUGH_H
#define BREAKTHROUGH_H
#include <game.h>

class Breakthrough : public Game
{
    public:
        Breakthrough();
        virtual ~Breakthrough();
        virtual void init();
        virtual bool move(int from_row,char from_col_char,int to_row,char to_col_char);
        virtual Player* checkWinner();
        virtual void legal();
        virtual void retract();


    protected:

    private:
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col);

};

#endif // BREAKTHROUGH_H
