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

}

void Game::movePiece(const int from_row, const int from_col, const int to_row, const int to_col)
{
    if(onBoard(from_row,from_col) && onBoard(to_row,to_col))
    {
        at(to_row,to_col) = at(from_row,from_col);
        at(from_row,from_col).init();
    }
}

void Game::init()
{
    board_.clear();
    for(int i = 0; i < rows_*cols_; i++)
    {
        board_.push_back(new Piece());
    }
}

int Game::mapLetterToInt(char c)
{
    return c - 97;
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



