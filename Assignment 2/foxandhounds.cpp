#include "foxandhounds.h"

FoxandHounds::FoxandHounds() : Game(8,8)
{
    init();
}

FoxandHounds::~FoxandHounds()
{

}

int FoxandHounds::checkWinner()
{
    for(int i = 0; i < get_num_cols(); i++)
    {
        if(at(get_num_rows()-1,i).getType() == 'F')
        {
            return 0;
        }
    }

    /*std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_+1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_-1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_-1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_+1) << std::endl;
    std::cout << std::endl;
    std::cout << foxlocrow_ << " " << foxloccol_ << std::endl;*/

    if((isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_+1) == false)&&
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_-1) == false)&&
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_-1) == false)&&
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_+1) == false))
    {
        return 1;
    }

    return -1;
}

bool FoxandHounds::isLegal(const int from_row, const int from_col, const int to_row, const int to_col)
{
    char type = at(from_row,from_col).getType();
    if(type == '.')
        return false;

    switch(type)
    {
        case 'H':
                if((to_row == from_row - 1 && to_col == from_col -1 && onBoard(to_row,to_col) &&isEmpty(to_row,to_col)) ||
                   (to_row == from_row - 1 && to_col == from_col + 1 && onBoard(to_row,to_col) &&isEmpty(to_row,to_col)))
                {
                    return true;
                }
                return false;

            break;
        case 'F': if((to_row == from_row + 1 && to_col == from_col + 1 &&onBoard(to_row,to_col) && isEmpty(to_row,to_col)) ||
                     (to_row == from_row - 1 && to_col == from_col -1 &&onBoard(to_row,to_col) && isEmpty(to_row,to_col))  ||
                     (to_row == from_row + 1 && to_col == from_col - 1 &&onBoard(to_row,to_col) && isEmpty(to_row,to_col)) ||
                     (to_row == from_row - 1 && to_col == from_col + 1 &&onBoard(to_row,to_col) && isEmpty(to_row,to_col)))
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
    setName("Fox and Hounds");
    Game::init();

    for(int i = 1; i < get_num_cols(); i = i + 2)
    {
        at(get_num_rows()-1,i).setType('H');
        at(get_num_rows()-1,i).setOwner('0');
    }

    at(0,get_num_cols()/2).setType('F');
    at(0,get_num_cols()/2).setOwner('1');

    foxlocrow_ = 0;
    foxloccol_ = get_num_cols()/2;

}

bool FoxandHounds::move(int from_row,char from_col_char,int to_row,char to_col_char)
{
    from_row = from_row - 1;
    to_row = to_row - 1;

    int from_col = Game::mapLetterToInt(from_col_char);
    int to_col = Game::mapLetterToInt(to_col_char);

    if(onBoard(from_row,from_col) && onBoard(to_row,to_col))
    {
        if(isLegal(from_row,from_col,to_row,to_col))
        {
            Game::movePiece(from_row,from_col,to_row,to_col);
            if(at(to_row,to_col).getType() == 'F')
            {
                foxlocrow_ = to_row;
                foxloccol_ = to_col;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
