#include <iostream>
#include <vector>
#include <piece.h>
#include <game.h>

using namespace std;

int main()
{
    Game g(4,7);
    g.at(0,0).setType('P');
    cout << g ;

    return 0;
}
