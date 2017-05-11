#ifndef FOXANDHOUNDS_H
#define FOXANDHOUNDS_H
#include <game.h>

class FoxandHounds : public Game
{
    public:
        FoxandHounds();
        virtual ~FoxandHounds();
        virtual void play();
        virtual bool isLegal(const int from_row, const int from_col, const int to_row, const int to_col);
        virtual void move(int from_row,char from_col_char,int to_row,char to_col_char);

    protected:
        virtual void init();

    private:
};

#endif // FOXANDHOUNDS_H
