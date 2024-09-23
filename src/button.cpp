#include <iostream>
#include "button.h"

using namespace std;

void heldButton() {
    cout << "Hold the button and enter the glowing color" << endl;
    string glowColor;
    cin >> glowColor;

    if (glowColor == "blue") {
        cout << "Release when the countdown timer has a 4 in any position";
    }
    else if (glowColor == "white") {
        cout << "Release when the countdown timer has a 1 in any position";
    }
    else if (glowColor == "yellow") {
        cout << "Release when the countdown timer has a 5 in any position";
    }
    else {
        cout << "Release when the countdown timer has a 1 in any position";
    }
}

void startButton() {
    cout << "Enter the color of the button" << endl;
    string color;
    cin >> color;

    cout << "Enter the text on top of the button" << endl;
    string text;
    cin >> text;

    if (color == "blue" && text == "Abort") {
        heldButton();
    }
    else {
        cout << "Enter the batteryCount" << endl;
        int batteryCount;
        cin >> batteryCount;

        if (batteryCount > 1 && text == "Detonate") {
            cout << "Press and immediately release the button" << endl;
        }
        else {
            cout << "Is there any lit indicator with label CAR? (type y/n)" << endl;
            char choice;
            cin >> choice;
            bool carInd = (choice == 'y') ? true : false;

            if (color == "white" && carInd) {
                heldButton();
            }
            else {

                cout << "Is there any lit indicator with label FRK? (type y/n" << endl;
                char choice;
                cin >> choice;
                bool frkInd = (choice == 'y') ? true : false;

                if (batteryCount > 2 && frkInd) {
                    cout << "Press and immediately release the button" << endl;
                }
                else if (color == "yellow") {
                    heldButton();
                }
                else if (color == "red" && text == "Hold") {
                    cout << "Press and immediately release the button" << endl;
                }
                else {
                    heldButton();
                }
            }

        }
    }


}