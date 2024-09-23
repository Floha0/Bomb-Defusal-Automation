#include <iostream>
#include "basicWire.h"
#include "button.h"
#include "maze.h"
#include "keypad.h"


using namespace std;


int main() {

    cout << "1: Basic Wire" << endl << "2: Button" << endl << "3: Keypad" << endl;
    cout << "10 : Maze" << endl;
    int gameIndex;
    cout << "Select a game: ";
    cin >> gameIndex;
    cout << endl;

    if (gameIndex == 1) {
        startBasicWire();
    }
    else if(gameIndex == 2) {
        startButton();
    }
    else if(gameIndex == 3) {
        startKeypad();
    }
    else if (gameIndex == 10) {
        startMaze();
    }
    else {
        cout << "Game Not Found!" << endl;
    }

    return 0;
}
