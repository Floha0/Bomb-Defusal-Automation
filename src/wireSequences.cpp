#include <iostream>
#include "../include/wireSequences.h"

using namespace std;

void startWireSequences() {
    int redCount = 0, blueCount = 0, blackCount = 0;


    while (true) {
        cout << "Enter the color. (Type \"q\" to quit)" << endl;
        string color;
        cin >> color;

        if(color == "q") return;

        cout << "Enter the letter" << endl;
        char letter;
        cin >> letter;

        if (color == "red") {
            redCount++;
            switch (redCount) {
                case 1:
                    if (letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 2:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 3:
                    if (letter == 'a') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 4:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 5:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 6:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 7:
                    if (letter == 'a' || letter == 'b' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 8:
                    if (letter == 'a' || letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 9:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                default:
                    cout << "No more red wire occurrences to handle." << endl;
                    break;
            }
        }
        else if (color == "blue") {
            blueCount++;
            switch (blueCount) {
                case 1:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 2:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 3:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 4:
                    if (letter == 'a') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 5:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 6:
                    if (letter == 'b' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 7:
                    if (letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 8:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 9:
                    if (letter == 'a') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                default:
                    cout << "No more blue wire occurrences to handle." << endl;
                    break;
            }
        }
        else if (color == "black") {
            blackCount++;
            switch (blackCount) {
                case 1:
                    if (letter == 'a' || letter == 'b' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 2:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 3:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 4:
                    if (letter == 'a' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 5:
                    if (letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 6:
                    if (letter == 'b' || letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 7:
                    if (letter == 'a' || letter == 'b') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 8:
                    if (letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                case 9:
                    if (letter == 'c') cout << "Cut the wire." << endl;
                    else cout << "Do not cut the wire." << endl;
                    break;
                default:
                    cout << "No more black wire occurrences to handle." << endl;
                    break;
            }
        }
    }
}
