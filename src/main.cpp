#include <iostream>

#include "../include/basicWire.h"
#include "../include/button.h"
#include "../include/maze.h"
#include "../include/keypad.h"
#include "../include/simonSays.h"
#include "../include/whosFirst.h"
#include "../include/memory.h"
#include "../include/morsCode.h"
#include "../include/complicatedWires.h"
#include "../include/wireSequences.h"
#include "../include/passwords.h"
#include <../include/knobs.h>


using namespace std;


int main() {

    cout << "1: Basic Wire" << endl << "2: Button" << endl << "3: Keypad" << endl;
    cout << "4: Simon Says" << endl << "5: Who's First" << endl << "6: Memory" << endl;
    cout << "7: Mors Code" << endl << "8: Complicated Wires" << endl << "9: Wire Sequences" << endl;
    cout << "10: Maze" << endl << "11: Passwords" << endl << "12: Knobs" << endl ;
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
        case 5:
            startWhosFirst();
            break;
        case 6:
            startMemory();
            break;
        case 7:
            startMorsCode();
            break;
        case 8:
            startComplicatedWires();
            break;
        case 9:
            startWireSequences();
            break;
        case 10:
            startMaze();
            break;
        case 11:
            startPasswords();
            break;
        case 12:
            startKnobs();
            break;
        default:
            cout << "Game Not Found!" << endl;
            break;
    }

    return 0;
}
