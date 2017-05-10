#include "player.h"

using namespace std;
Player::Player()
{
    ownedBy_ = 'b';
    type_ = '.';
}

Player::~Player()
{

}

bool Player::isLegal(tuple<int, int>move)
{
    //TODO
    return true;
}

void Player::setLegalMoves(set<tuple<int, int>>& moves)
{
    //TODO
}

tuple<int,int> Player::getLocation()
{
    return location_;
}

void Player::setLocation(tuple<int, int>newlocation)
{
    location_ = newlocation;
}


char Player::getType()
{
    return type_;
}

char Player::getOwner()
{
    return ownedBy_;
}
void Player::setType(char type)
{
    type_ = type;
}

void Player::setOwner(char owner)
{
    ownedBy_ = owner;
}


