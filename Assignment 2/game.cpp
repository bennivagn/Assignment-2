#include "game.h"
#include <stdexcept>
#include <string>
using namespace std;

Game::Game(int rows,int cols)
{
    if(rows <= MAXSIZE && rows > 0 && cols <= MAXSIZE && cols > 0)
    {
        rows_ = rows;
        cols_ = cols;
        debug_ = false;

        init();
    }

    else
    {
        throw std::out_of_range("Game board too big");
    }
}

Game::~Game()
{
    for(auto it = board_.begin(); it != board_.end(); ++it)
    {
        delete *it;
    }

    delete &player0_;
    delete &player1_;

}

void Game::movePiece(const int from_row, const int from_col, const int to_row, const int to_col,bool retract)
{

    if(onBoard(from_row,from_col) && onBoard(to_row,to_col))
    {
        at(to_row,to_col) = at(from_row,from_col);
        at(from_row,from_col).init();
        if(retract == false)
        {
            moves_.push(make_tuple(from_row,from_col,to_row,to_col));
        }


    }
}

void Game::init()
{
    board_.clear();
    while(!moves_.empty()){
        moves_.pop();
    }
    for(int i = 0; i < rows_*cols_; i++)
    {
        board_.push_back(new Piece());
    }

    player0_.setPlayer('0');
    player1_.setPlayer('1');

    currentPlayer_ = &player0_;
    gameWon_ = false;

}

int Game::mapLetterToInt(char c)
{
    return c - 97;
}

char Game::mapIntToLetter(int num)
{
    return num + 97;
}


const int Game::get_num_rows()
{
    return rows_;
}

const int Game::get_num_cols()
{
    return cols_;
}

bool Game::isEmpty(int row,int col)
{
    return at(row,col).getType() == '.';
}

bool Game::onBoard(int row, int col)
{
    if(row < get_num_rows() && row >= 0 && col < get_num_cols() && col >= 0)
    {
        return true;
    }
    return false;

}

Piece& Game::at(int row, int col )
{
    if(row <= rows_ && row >= 0 && col <= cols_ && col >= 0)
    {
        return *board_[row * cols_ + col];
    }
    else
    {
        throw new std::out_of_range("Out of range");
    }
}

void Game::setName(std::string name)
{
    name_ = name;
}

std::string Game::getName()
{
    return name_;
}

bool Game::getDebug()
{
    return debug_;
}

void Game::setDebug(bool debug)
{
    debug_ = debug;
}

int Game::remainingPieces(Player& player)
{
    int count = 0;
    for(int i = 0; i < get_num_rows(); i++)
    {
        for(int j = 0; j < get_num_cols(); j++)
        {
            if(at(i,j).getOwner() != nullptr && at(i,j).getOwner()->getPlayer() == player.getPlayer())
                count++;
        }
    }
    return count;
}

void Game::switchPlayer()
{
    if(currentPlayer_ == &player0_)
    {
        currentPlayer_ = &player1_;
    }
    else
    {
        currentPlayer_ = &player0_;
    }
}

Player* Game::getPlayer_0()
{
    return &player0_;
}

Player* Game::getPlayer_1()
{
    return &player1_;
}

Player* Game::getCurrentPlayer()
{
    return currentPlayer_;
}

std::ostream& operator<<(std::ostream& os, Game& g)
{
     int count = g.get_num_rows();
            std::string characters = "abcdefghijklmnopqrstuv";
            for ( int row = g.get_num_rows()-1 ; row >= 0; --row )
            {
                os << count << " ";
                count--;
                for ( int col = 0; col < g.get_num_cols() ; ++col )
                {
                    if(g.at(row,col).getOwner() == g.getPlayer_1())
                    {
                        os << (char)tolower(g.at(row,col).getType());
                    }
                    else
                    {
                        os << g.at(row,col);
                    }
                }
                os << std::endl;
            }

            os << "  ";
            for(int i = 0; i < g.get_num_cols(); i++)
            {
                os << characters.at(i);
            }

            os << std::endl;
            os << g.getCurrentPlayer()->getPlayer() << std::endl;
            os << g.remainingPieces(*g.getPlayer_0()) << " " << g.remainingPieces(*g.getPlayer_1());

            return os;
}




