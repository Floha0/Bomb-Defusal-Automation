#include <iostream>
#include "../include/complicatedWires.h"

using namespace std;

char findCode(string color, bool hasStar, bool ledOn);

void startComplicatedWires() {
    cout << "Enter battery count" << endl;
    int batteryCount;
    cin >> batteryCount;

    bool hasPort = false;
    cout << "Does the bomb have parallel port? (type y/n)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'y') hasPort = true;

    bool lastEven = false;
    cout << "Enter the last digit of the serial number" << endl;
    int lastDigit;
    cin >> lastDigit;
    if(lastDigit % 2 == 0) lastEven = true;


    while(true) {
        cout << "Enter the color(s) (type red/blue/both)" << endl;
        string color;
        cin >> color;

        bool hasStar = false;
        cout << "Does the wire have star? (type y/n)" << endl;
        char ch;
        cin >> ch;
        if (ch == 'y') hasStar = true;

        bool ledOn = false;
        cout << "Does the led is on? (type y/n)" << endl;
        cin >> ch;
        if (ch == 'y') ledOn = true;

        switch(findCode(color, hasPort, ledOn)) {
            case 'c':
                cout << "Cut the wire" << endl;
                break;
            case 'd':
                cout << "Do not cut the wire" << endl;
            case 's':
                if (lastEven) {
                    cout << "Cut the wire" << endl;
                }
                else {
                    cout << "Do not cut the wire" << endl;
                }
                break;
            case 'p':
                if (hasPort) {
                    cout << "Cut the wire" << endl;
                }
                else {
                    cout << "Do not cut the wire" << endl;
                }
                break;
            case 'b':
                if (batteryCount >= 2) {
                    cout << "Cut the wire" << endl;
                }
                else {
                    cout << "Do not cut the wire" << endl;
                }
                break;
        }
    }
}

char findCode(string color, bool hasStar, bool ledOn) {

    if (color == "red") {
        if (hasStar) {
            if (ledOn) {
                return 'b';
            }
            else {
                return 'c';
            }
        }
        else {
            if (ledOn) {
                return 'b';
            }
            else {
                return 's';
            }
        }
    }
    else if (color == "blue") {
        if (hasStar) {
            if (ledOn) {
                return 'p';
            }
            else {
                return 'd';
            }
        }
        else {
            if (ledOn) {
                return 'p';
            }
            else {
                return 's';
            }
        }
    }
    else if (color == "both") {
        if (hasStar) {
            if (ledOn) {
                return 'd';
            }
            else {
                return 'p';
            }
        }
        else {
            if (ledOn) {
                return 's';
            }
            else {
                return 'd';
            }
        }
    }
    else {
        if (hasStar) {
            if (ledOn) {
                return 'b';
            }
            else {
                return 'c';
            }
        }
        else {
            if (ledOn) {
                return 'd';
            }
            else {
                return 'c';
            }
        }
    }
}
