#include <iostream>
#include <vector>
#include "keypad.h"

using namespace std;

void startKeypad() {
    cout << "Choose the symbols:" << endl;

    string symbols[] = {
        "1- Mirror",
        "2- A and T intertwined",
        "3- reverse y with a line on bottom",
        "4- reverse thunder",
        "5- Spider",
        "6- H with a tail",
        "7- dot inside reverse C",
        "8- reverse E with diaeresis",
        "9- O but 540 degree",
        "10 - I between K and Mirrored K",
        "11- reverse question mark",
        "12- c in a circle",
        "13- w with ' at top",
        "14- half 3 with tail",
        "15- empty star",
        "16- 6",
        "17- reverse p",
        "18- b and T intertwined",
        "19- happy face",
        "20- trident",
        "21- dot inside c",
        "22- full 3 with tail and hat",
        "23- full star",
        "24- dumbbell",
        "25- æ",
        "26- reverse N",
        "27- ohm symbol"
    };

    for (const auto& symbol : symbols) {
        cout << symbol << endl;
    }

    vector<vector<int>> vecs = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 1, 7, 9, 15, 6, 11},
        {12, 13, 9, 10, 14, 3, 15},
        {16, 17, 18, 5, 10, 11, 19},
        {20, 19, 18, 21, 17, 22, 23},
        {16, 8, 24, 25, 20, 26, 27}
    };

    vector<int> vin;
    int sym;
    cout << "Enter the number of symbols: ";
    cin >> sym;
    vin.push_back(sym);
    cin >> sym;
    vin.push_back(sym);
    cin >> sym;
    vin.push_back(sym);
    cin >> sym;
    vin.push_back(sym);

    // vin.size() must be 4
    for(int i = 0; i < 4; i++) {
        cout << vin[i] << " ";
    }

    // vin.size() must be 4



    int index = -1;
    int x = 0;
    for (int i = 0; i < 6; i++) {   // vector count
        for (int j = 0; j < 7; j++) {   // inside vector count
            for (int k = 0; k < 4; k++) { // input count
                if (vecs[i][j] == vin[k]) {
                    x++;
                }
            }
            if (x == 4) {
                break;
            }
        }
        if (x == 4) {
            index = i;
            break;
        }
        x = 0;
    }

    cout << "vector index is: " << index << endl;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (vecs[index][i] == vin[j]) {
                cout << "index is: " << symbols[vecs[index][i] - 1] << endl;
            }
        }
    }
}
