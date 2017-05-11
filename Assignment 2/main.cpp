#include <iostream>
#include <vector>
#include <piece.h>
#include <game.h>
#include <foxandhounds.h>

using namespace std;

void play(Game* game)
{
    char fromcol,tocol;
    int fromint = 0,toint = 0;
    while(true)
    {
        cout << *game << endl;
        cin >> fromcol;
        cin >> fromint;
        cin >> tocol;
        cin >> toint;
        game->move(fromint,fromcol,toint,tocol);

    }
}

int main()
{
    FoxandHounds* game = new FoxandHounds();
    play(game);


    return 0;
}
