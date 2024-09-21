#include <iostream>
#include <vector>
#include "basicWire.h"
#include "maze.h"


using namespace std;


int main() {

    cout << "1: Maze" << endl << "2: Basic Wire" << endl;
    int gameIndex;
    cout << "Select a game: ";
    cin >> gameIndex;
    cout << endl;

    if (gameIndex == 1) {
        startMaze();
    }
    else if(gameIndex == 2) {
        startBasicWire();
    }
    else {
        cout << "Game Not Found!" << endl;
    }

    return 0;
}
