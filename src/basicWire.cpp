#include <iostream>
#include <vector>
#include "basicWire.h"

using namespace std;

void startBasicWire () {

    cout << "Enter the wire count: ";
    int count;
    cin >> count;
    cout << endl;

    cout << "Enter the last digit of the serial number: ";
    int lastSerialNumber;
    cin >> lastSerialNumber;
    cout << endl;

    cout << "Enter the wire colors" << endl;

    vector<string> colors;


    for (int i = 0; i < count; i++) {
        string newChar;
        cin >> newChar;
        colors.push_back(newChar);
    }

    int redCount, blueCount, whiteCount, blackCount, yellowCount;

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < colors.size(); j++) {
            if (colors[j] == "red") {
                redCount++;
            } else if (colors[j] == "blue") {
                blueCount++;
            } else if (colors[j] == "white") {
                whiteCount++;
            } else if (colors[j] == "yellow") {
                yellowCount++;
            } else if (colors[j] == "black") {
                blackCount++;
            }
        }
    }

    if (count == 3) {
        if (redCount == 0) {
            cout << "second wire";
        }
        else if(colors[colors.size() - 1] == "white") {
            cout << "last wire";
        }
        else if(blueCount > 1) {
            cout << "last blue wire";
        }
        else {
            cout << "last wire";
        }
    }
    else if(count == 4) {
        if (redCount > 1 && lastSerialNumber % 2 == 1) {
            cout << "last red wire";
        }
        else if (colors[colors.size() - 1] == "yellow" && redCount == 0) {
            cout << "first wire";
        }
        else if (blueCount == 1) {
            cout << "first wire";
        }
        else if(yellowCount > 1) {
            cout << "last wire";
        }
        else {
            cout << "second wire";
        }
    }
    else if(count == 5) {
        if (colors[colors.size() - 1] == "black" && lastSerialNumber % 2 == 1) {
            cout << "fourth wire";
        }
        else if(redCount == 1 && yellowCount > 1) {
            cout << "first wire";
        }
        else if (blackCount == 0) {
            cout << "second wire";
        }
        else {
            cout << "first wire";
        }
    }
    else if(count == 6) {
        if (yellowCount == 0 && lastSerialNumber % 2 == 1) {
            cout << "third wire";
        }
        else if (yellowCount == 1 && whiteCount > 1) {
            cout << "fourth wire";
        }
        else if (redCount == 0) {
            cout << "last wire";
        }
        else {
            cout << "fourth wire";
        }
    }
}