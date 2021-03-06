#include "foxandhounds.h"
#include <vector>
#include <string>
using namespace std;

FoxandHounds::FoxandHounds() : Game(8,8)
{
    init();
}

FoxandHounds::~FoxandHounds()
{

}

Player* FoxandHounds::checkWinner()
{
    for(int i = 0; i < get_num_cols(); i++)
    {
        if(at(get_num_rows()-1,i).getType() == 'F')
        {
            gameWon_ = true;
            return at(get_num_rows()-1,i).getOwner();
        }
    }

    /*std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_+1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_-1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_-1) << std::endl;
    std::cout << isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_+1) << std::endl;
    std::cout << std::endl;
    std::cout << foxlocrow_ << " " << foxloccol_ << std::endl;*/

    if((isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_+1) == false)||
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_-1) == false)||
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_-1) == false)||
       (isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_+1) == false))
    {
        gameWon_ = true;
        return at(foxlocrow_,foxloccol_).getOwner();
    }

    return nullptr;
}

std::vector<string> FoxandHounds::legal()
{
    vector<string> legalmoves;
    string s = "";
    if(currentPlayer_ == &player0_)
    {
       if(isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_+1))
       {
            s = Game::mapIntToLetter(foxloccol_) + to_string(foxlocrow_+1) + Game::mapIntToLetter(foxloccol_+1) + to_string(foxlocrow_+2);
            legalmoves.push_back(s);
       }
       if(isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_-1))
       {
            s = Game::mapIntToLetter(foxloccol_) + to_string(foxlocrow_+1) + Game::mapIntToLetter(foxloccol_-1) + to_string(foxlocrow_);
            legalmoves.push_back(s);
       }
       if(isLegal(foxlocrow_,foxloccol_,foxlocrow_+1,foxloccol_-1))
       {
            s = Game::mapIntToLetter(foxloccol_) + to_string(foxlocrow_+1) + Game::mapIntToLetter(foxloccol_-1) + to_string(foxlocrow_+2);
            legalmoves.push_back(s);
       }
       if(isLegal(foxlocrow_,foxloccol_,foxlocrow_-1,foxloccol_+1))
       {
            s = Game::mapIntToLetter(foxloccol_) + to_string(foxlocrow_+1) + Game::mapIntToLetter(foxloccol_+1) + to_string(foxlocrow_);
            legalmoves.push_back(s);
       }

      return legalmoves;

    }
    else
    {
        for(int i = 0; i < get_num_rows(); i++)
        {
            for(int j = 0; j < get_num_cols(); j++)
            {
                if(at(i,j).getType() == 'H')
                {
                    if(isLegal(i,j,i-1,j+1))
                    {
                        s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j+1) + to_string(i);
                        legalmoves.push_back(s);
                    }

                    if(isLegal(i,j,i-1,j-1))
                    {
                        s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j-1) + to_string(i);
                        legalmoves.push_back(s);
                    }



                }
            }
        }
        return legalmoves;
    }

}

bool FoxandHounds::isLegal(const int from_row, const int from_col, const int to_row, const int to_col)
{
    if(gameWon_ == true)
    {
        return false;
    }
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
        at(get_num_rows()-1,i).setOwner(&player1_);
    }

    at(0,get_num_cols()/2).setType('F');
    at(0,get_num_cols()/2).setOwner(&player0_);

    foxlocrow_ = 0;
    foxloccol_ = get_num_cols()/2;

}

bool FoxandHounds::move(int from_row,char from_col_char,int to_row,char to_col_char)
{
    from_row = from_row - 1;
    to_row = to_row - 1;

    int from_col = Game::mapLetterToInt(from_col_char);
    int to_col = Game::mapLetterToInt(to_col_char);

    if(currentPlayer_ != at(from_row,from_col).getOwner())
    {
        return false;
    }

    if(onBoard(from_row,from_col) && onBoard(to_row,to_col))
    {
        if(isLegal(from_row,from_col,to_row,to_col))
        {
            Game::movePiece(from_row,from_col,to_row,to_col);
            switchPlayer();
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
void FoxandHounds::retract()
{

    if(!moves_.empty() && gameWon_!= true)
    {
        switchPlayer();
        tuple<int,int,int,int,Piece> m = moves_.top();
        moves_.pop();
        bool val = true;
        Game::movePiece(get<2>(m),get<3>(m),get<0>(m),get<1>(m),val);

    }

}



