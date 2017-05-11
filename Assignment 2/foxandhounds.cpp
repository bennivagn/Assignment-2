#include "foxandhounds.h"

FoxandHounds::FoxandHounds() : Game(8,8)
{
    init();
}

FoxandHounds::~FoxandHounds()
{

}

void FoxandHounds::play()
{

}

bool FoxandHounds::isLegal(const int from_row, const int from_col, const int to_row, const int to_col)
{
    char type = at(from_row,from_col).getType();
    if(type == '.')
        return false;

    switch(type)
    {
        case 'H':
                if((to_row == from_row - 1 && to_col == from_col -1) ||
                   (to_row == from_row - 1 && to_col == from_col + 1))
                {
                    return true;
                }
                return false;

            break;
        case 'F': if((to_row == from_row + 1 && to_col == from_col + 1) ||
                     (to_row == from_row - 1 && to_col == from_col -1) ||
                     (to_row == from_row + 1 && to_col == from_col - 1) ||
                     (to_row == from_row - 1 && to_col == from_col + 1))
                     {
                         return true;
                     }
                     return false;

            break;
        default: return false;
        break;
    }



}


void FoxandHounds::init()
{
    for(int i = 1; i < get_num_cols(); i = i + 2)
    {
        at(get_num_rows()-1,i).setType('H');
        at(get_num_rows()-1,i).setOwner('1');
    }

    at(0,get_num_cols()/2).setType('F');
    at(0,get_num_cols()/2).setOwner('2');
}

void FoxandHounds::move(int from_row,char from_col_char,int to_row,char to_col_char)
{
     from_row = from_row - 1;
     to_row = to_row - 1;

     int from_col = Game::mapLetterToInt(from_col_char);
     int to_col = Game::mapLetterToInt(to_col_char);



     if(from_row < get_num_rows() && from_row >= 0 && from_col < get_num_cols() && from_col >= 0 &&
       to_row < get_num_rows() && to_row >= 0 && to_col < get_num_cols() && to_col >= 0)
    {

        if(isLegal(from_row,from_col,to_row,to_col))
        {
            Game::movePiece(from_row,from_col,to_row,to_col);
        }
    }
}
