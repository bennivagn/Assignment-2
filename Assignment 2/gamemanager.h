#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include <game.h>
#include <foxandhounds.h>
#include <breakthrough.h>



class Gamemanager
{
    public:
        Gamemanager();
        virtual ~Gamemanager();
        void UI();

    protected:

    private:
        void list();
        void game();
        void start();
        void move();
        void commands();
        std::vector<Game*> games_;
        int selectedGame;

};

#endif // GAMEMANAGER_H
