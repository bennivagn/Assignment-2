#include "game.h"
using namespace std;

Game::Game(int rows,int cols)
{
    if(rows <= MAXSIZE && rows > 0 && cols <= MAXSIZE && cols > 0)
    {
        rows_ = rows;
        cols_ = cols;

        for(int i = 0; i < rows*cols; i++)
        {
            board_.push_back(new Piece());
        }
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
void Game::play()
{

}

const int Game::get_num_rows()
{
    return rows_;
}

const int Game::get_num_cols()
{
    return cols_;
}

