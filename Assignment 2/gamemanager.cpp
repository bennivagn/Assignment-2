#include "gamemanager.h"
#include <string>
#include <iostream>
using namespace std;

Gamemanager::Gamemanager()
{
    games_.push_back(new FoxandHounds());
    //games_.push_back(new Breakthrough());
    //games_.push_back(new MegaBreakthrough());
    selectedGame = 0;

    cout << "Welcome." << endl;
    UI();
}

Gamemanager::~Gamemanager()
{
    for(auto g : games_)
    {
        delete g;
    }
}

void Gamemanager::commands()
{
    cout << endl;
    cout << "Type in any of the follwing commands: " << endl;
    cout << "list " << endl;
    cout << "game" << endl;
    cout << "start " << endl;
    cout << "legal " << endl;
    cout << "move" << endl;
    cout << "retract " << endl;
    cout << "display " << endl;
    cout << "evaluate " << endl;
    cout << "go" << endl;
    cout << "level " << endl;
    cout << "debug " << endl;
    cout << "help" << endl;
    cout << "quit " << endl;
    cout << endl;
}

void Gamemanager::list()
{
    int counter = 0;
    for(auto g : games_)
    {
        counter++;
        cout << counter << "." << g ->getName() << endl;
    }
}

void Gamemanager::game()
{
    list();
    cout << "What game do you want to play?: ";
    cin >> selectedGame;

    selectedGame--;

}

void Gamemanager::start()
{
    games_.at(selectedGame)->init();
}

void Gamemanager::legal()
{

}

void Gamemanager::move()
{
    char fromcol,tocol;
    int fromint = 0,toint = 0;
    int winner = -1;
    std::cin >> fromcol;
    std::cin >> fromint;
    std::cin >> tocol;
    std::cin >> toint;
    if(games_.at(selectedGame)->move(fromint,fromcol,toint,tocol) == false)
    {
        cout << "Illegal move!" << endl;
        cin.clear();
    }


    winner = games_.at(selectedGame)->checkWinner();

    if(winner != -1)
    {
        std::cout << std::endl;
        std::cout << "Winner is player: " << winner;
    }


}



void Gamemanager::UI()
{
    string input;
    commands();
    do
    {
        cout << endl;
        cin >> input;

        if(input == "list")
        {
            list();
        }
        else if(input == "game")
        {
            game();
        }
        else if(input == "start")
        {
            start();
        }
        else if(input == "legal")
        {
            legal();
        }
        else if(input == "move")
        {
            move();
        }
        else if(input == "retract")
        {
            //TODO
        }
        else if(input == "display")
        {
            cout << *games_.at(selectedGame);
        }
        else if(input == "evaluate")
        {

        }
        else if(input == "go")
        {

        }
        else if(input == "level")
        {

        }
        else if(input == "debug")
        {
            if(games_.at(selectedGame)->getDebug() == true)
            {
                games_.at(selectedGame)->setDebug(false);
                cout << "Debug Mode off!" << endl;
            }
            else
            {
                games_.at(selectedGame)->setDebug(true);
                cout << "Debug Mode on!" << endl;
            }

        }

        else
        {
            commands();
        }


    }while(input != "quit");


}

