#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        void setPlayer(char player);
        char getPlayer();
        int getScore();
        void setScore(int score);
        void incrementScore();

    protected:

    private:
        char player_;
        int score_;
};

#endif // PLAYER_H
