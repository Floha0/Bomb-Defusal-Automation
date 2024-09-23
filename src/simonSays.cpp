#include <iostream>

using namespace std;

void startSimonSays() {
    bool cont = true;

    bool containsVowel = false;
    cout << "Does the serial number contains vowel? (type y/n)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y') containsVowel = true;

    while (cont) {
        cout << "Enter strike count: " << endl;
        int strikeCount;
        cin >> strikeCount;

        cout << "Enter color" << endl;
        string color;
        cin >> color;

        string pressColor;

        if (containsVowel) {
            if (color == "red") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "blue";
                        break;
                    case 1:
                        pressColor = "yellow";
                        break;
                    case 2:
                        pressColor = "green";
                        break;
                }
            }
            else if (color == "blue") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "red";
                    break;
                    case 1:
                        pressColor = "green";
                    break;
                    case 2:
                        pressColor = "red";
                    break;
                }
            }
            else if (color == "green") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "yellow";
                    break;
                    case 1:
                        pressColor = "blue";
                    break;
                    case 2:
                        pressColor = "yellow";
                    break;
                }
            }
            else if (color == "yellow") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "green";
                    break;
                    case 1:
                        pressColor = "red";
                    break;
                    case 2:
                        pressColor = "blue";
                    break;
                }
            }
        }
        else {
            if (color == "red") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "blue";
                    break;
                    case 1:
                        pressColor = "red";
                    break;
                    case 2:
                        pressColor = "yellow";
                    break;
                }
            }
            else if (color == "blue") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "yellow";
                    break;
                    case 1:
                        pressColor = "blue";
                    break;
                    case 2:
                        pressColor = "green";
                    break;
                }
            }
            else if (color == "green") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "green";
                    break;
                    case 1:
                        pressColor = "yellow";
                    break;
                    case 2:
                        pressColor = "blue";
                    break;
                }
            }
            else if (color == "yellow") {
                switch (strikeCount) {
                    case 0:
                        pressColor = "red";
                    break;
                    case 1:
                        pressColor = "green";
                    break;
                    case 2:
                        pressColor = "red";
                    break;
                }
            }
        }
        cout << "press the " << pressColor << endl;
        cout << "Do you want to continue? (type y/n)" << endl;
        char ch1;
        cin >> ch1;
        if (ch1 != 'y' && ch1 != 'Y') cont = false;
    }
}
