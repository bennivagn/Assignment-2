#include "breakthrough.h"
#include <vector>
#include <string>

using namespace std;

Breakthrough::Breakthrough() : Game(8,8)
{
    init();
}

Breakthrough::~Breakthrough()
{
    //dtor
}
void Breakthrough::init()
{
    setName("Breakthrough");
    Game::init();


    for(int i = 0; i < get_num_cols(); i++)
    {
        at(get_num_rows()-1,i).setType('P');
        at(get_num_rows()-2,i).setType('P');
        at(get_num_rows()-1,i).setOwner(&player1_);
        at(get_num_rows()-2,i).setOwner(&player1_);
    }

    for(int i = get_num_cols()-1; i >= 0; i--)
    {
        at(0,i).setType('P');
        at(1,i).setType('P');
        at(0,i).setOwner(&player0_);
        at(1,i).setOwner(&player0_);
    }


}

bool Breakthrough::isLegal(const int from_row, const int from_col, const int to_row, const int to_col)
{
    if(gameWon_ == true)
    {
        return false;
    }
    char type = at(from_row,from_col).getType();
    if(type == '.')
        return false;

    switch(currentPlayer_->getPlayer())
    {
        case '0':

                if((to_row == from_row + 1 && to_col == from_col -1 && onBoard(to_row,to_col)) ||
                   (to_row == from_row + 1 && to_col == from_col + 1 && onBoard(to_row,to_col))||
                   (to_row == from_row + 1 && to_col == from_col && onBoard(to_row,to_col) && isEmpty(to_row,to_col)))
                   {
                        return true;
                   }
                return false;
            break;

        case '1':
                if((to_row == from_row - 1 && to_col == from_col -1 && onBoard(to_row,to_col)) ||
                   (to_row == from_row - 1 && to_col == from_col + 1 && onBoard(to_row,to_col))||
                   (to_row == from_row - 1 && to_col == from_col && onBoard(to_row,to_col) && isEmpty(to_row,to_col)))
                {
                    return true;
                }
                return false;
                break;

        default: return false;
        break;
    }
}


bool Breakthrough::move(int from_row, char from_col_char, int to_row, char to_col_char)
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

Player* Breakthrough::checkWinner()
{
    for(int j = 0; j < get_num_cols(); j++)
    {
        if(at(get_num_rows()-1,j).getOwner() != nullptr && at(get_num_rows()-1,j).getOwner()->getPlayer() == player0_.getPlayer())
        {
            gameWon_ = true;
            return at(get_num_rows()-1,j).getOwner();
        }

        if(at(0,j).getOwner() != nullptr && at(0,j).getOwner()->getPlayer() == player1_.getPlayer())
        {
            gameWon_ = true;
            return at(0,j).getOwner();
        }
    }

    if(Game::remainingPieces(player0_) == 0)
    {
        gameWon_ = true;
        return &player1_;
    }
    if(Game::remainingPieces(player1_) == 0)
    {
        gameWon_ = true;
        return &player0_;
    }

    return nullptr;


}

std::vector<string> Breakthrough::legal()
{
    vector<string> legalmoves;
    string s = "";

    for(int i = 0; i < get_num_rows(); i++)
        {
            for(int j = 0; j < get_num_cols(); j++)
            {
                if(at(i,j).getOwner() != nullptr)
                {
                    if(at(i,j).getOwner()->getPlayer() == player0_.getPlayer() && currentPlayer_->getPlayer() == player0_.getPlayer())
                    {
                        if(isLegal(i,j,i+1,j+1))
                        {
                            s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j+1) + to_string(i+2);
                            legalmoves.push_back(s);
                        }

                        if(isLegal(i,j,i+1,j))
                        {
                            s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j) + to_string(i+2);
                            legalmoves.push_back(s);
                        }

                        if(isLegal(i,j,i+1,j-1))
                        {
                            s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j-1) + to_string(i+2);
                            legalmoves.push_back(s);
                        }

                    }
                    else if(at(i,j).getOwner()->getPlayer() == player1_.getPlayer() && currentPlayer_->getPlayer() == player1_.getPlayer())
                    {
                        if(isLegal(i,j,i-1,j+1))
                        {
                            s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j+1) + to_string(i);
                            legalmoves.push_back(s);
                        }

                        if(isLegal(i,j,i-1,j))
                        {
                            s = Game::mapIntToLetter(j) + to_string(i+1) + Game::mapIntToLetter(j) + to_string(i);
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
        }
    return legalmoves;
}

void Breakthrough::retract()
{
    if(!moves_.empty() && gameWon_!= true)
    {
        switchPlayer();
        tuple<int,int,int,int,Piece> m = moves_.top();
        moves_.pop();
        bool val = true;
        Game::movePiece(get<2>(m),get<3>(m),get<0>(m),get<1>(m),val);
        at(get<2>(m), get<3>(m)) = get<4>(m);

    }
}
