#ifndef FOXANDHOUNDS_H
#define FOXANDHOUNDS_H
#include <game.h>

class FoxandHounds : public Game
{
    public:
        FoxandHounds();
        virtual ~FoxandHounds();
        virtual bool move(int from_row,char from_col_char,int to_row,char to_col_char);
        virtual int checkWinner();
        virtual void init();

    protected:


    private:
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col);
        int foxlocrow_;
        int foxloccol_;

};

#endif // FOXANDHOUNDS_H
