#include "breakthrough.h"

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

}


bool Breakthrough::move(int from_row, char from_col_char, int to_row, char to_col_char)
{
    return false;
}

Player* Breakthrough::checkWinner()
{
    return nullptr;
}

void Breakthrough::legal()
{

}

void Breakthrough::retract()
{

}
