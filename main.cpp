#include <iostream>
#include "basicWire.h"
#include "button.h"
#include "maze.h"
#include "keypad.h"
#include "simonSays.h"


using namespace std;


int main() {

    cout << "1: Basic Wire" << endl << "2: Button" << endl << "3: Keypad" << endl;
    cout << "4: Simon Says" << endl;
    cout << "10 : Maze" << endl;
    int gameIndex;
    cout << "Select a game: ";
    cin >> gameIndex;
    cout << endl;


    switch (gameIndex) {
        case 1:
            startBasicWire();
            break;
        case 2:
            startButton();
            break;
        case 3:
            startKeypad();
            break;
        case 4:
            startSimonSays();
            break;
        case 10:
            startMaze();
            break;
        default:
            cout << "Game Not Found!" << endl;
            break;
    }

    return 0;
}
