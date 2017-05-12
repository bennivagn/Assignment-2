#include "player.h"

Player::Player() : score_(0)
{

}

Player::~Player()
{
    //dtor
}

void Player::setPlayer(char player)
{
    player_ = player;
}

char Player::getPlayer()
{
    return player_;
}


int Player::getScore()
{
    return score_;
}

void Player::setScore(int score)
{
    score_ = score;
}

void Player::incrementScore()
{
    score_++;
}
