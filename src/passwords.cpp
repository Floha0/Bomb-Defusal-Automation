#include <iostream>
#include <vector>
#include "../include/passwords.h"

using namespace std;

void startPasswords() {
    vector<string> passwords = {"about", "after", "again", "below",
        "could", "every", "first", "found", "great", "house",
        "large", "learn", "never", "other", "place", "plant",
        "point", "right", "small", "sound", "spell", "still",
        "study", "their", "there", "these", "thing", "think",
        "three", "water", "where", "which", "world", "would", "write"};

    vector<vector<char>> letterVectors;

    for (int i = 0; i < 5; i++) {
        vector<char> letters;
        letters.clear();
        while (true) {
            cout << "Enter the letters of the digit (will automaticly go to the next digit if the same char entered)"<< endl;
            char ch;
            cin >> ch;

            bool hasSame = false;
            for (int j = 0; j < letters.size(); j++) {
                if (letters[j] == ch) {
                    hasSame = true;
                    break;
                }
                cout << letters[j] << endl;
            }
            if (hasSame) break;
            letters.push_back(ch);
        }
        letterVectors.push_back(letters);

        vector<string> tmpPasswords;
        for (int j = passwords.size() -1; j >= 0; j--) {
            for (int k = 0; k < letters.size(); k++) {
                if (passwords[j].at(i) == letters[k]) {
                    tmpPasswords.push_back(passwords[j]);
                }
            }
        }
        passwords = tmpPasswords;

        for (int j = 0; j < passwords.size(); j++) {
            cout << passwords[j] << endl;
        }

        if (passwords.size() == 1) {
            cout << "Password is: " << passwords[0] << endl;
        }
    }
}
