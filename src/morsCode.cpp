#include <iostream>
#include <map>
#include <vector>
#include "../include/morsCode.h"

using namespace std;

void startMorsCode(){
    vector<string> words = {"shell", "halls", "slick", "trick", "boxes",
        "leaks", "strobe", "bistro", "flick", "bombs", "break", "brick",
        "steak", "sting", "vector", "beats"};

    map<string, string> frequencies{
        {"shell", "3.505 MHz"},  {"halls", "3.515 MHz"}, {"slick", "3.522 MHz"},
        {"trick", "3.532 MHz"},  {"boxes", "3.535 MHz"}, {"leaks", "3.542 MHz"},
        {"strobe", "3.545 MHz"}, {"bistro", "3.552 MHz"}, {"flick", "3.555 MHz"},
        {"bombs", "3.565 MHz"},  {"break", "3.572 MHz"}, {"brick", "3.575 MHz"},
        {"steak", "3.582 MHz"},  {"sting", "3.592 MHz"}, {"vector", "3.595 MHz"},
        {"beats", "3.600 MHz"}
    };
    map<string, string> chars{
        {".-", "a"},    {"-...", "b"},  {"-.-.", "c"},  {"-..", "d"},  {".", "e"},
        {"..-.", "f"},  {"--.", "g"},   {"....", "h"},  {"..", "i"},   {".---", "j"},
        {"-.-", "k"},   {".-..", "l"},  {"--", "m"},    {"-.", "n"},   {"---", "o"},
        {".--.", "p"},  {"--.-", "q"},  {".-.", "r"},   {"...", "s"},  {"-", "t"},
        {"..-", "u"},   {"...-", "v"},  {".--", "w"},   {"-..-", "x"}, {"-.--", "y"},
        {"--..", "z"},  {"-----", "0"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"},
        {"....-", "4"}, {".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"},
        {"----.", "9"}
    };

    char letter;

    bool solved = false;
    int i = 0;
    while (!solved) {
        cout << "enter the first word. (use -/.)" << endl;
        string morse_code;
        cin >> morse_code;

        if (chars.find(morse_code) != chars.end()) {
            letter = chars[morse_code][0];
        }
        else {
            cout << morse_code << " is not a valid letter." << endl;
        }

        for (int j = words.size() - 1; j >= 0; j--) {
            if (words[j].at(i) != letter) {
                words.erase(words.begin() + j);
            }
        }

        for (int j = 0; j < words.size(); j++) {
            cout << words[j] << endl;
        }

        if (words.size() == 1) {
            solved = true;
        }

        i++;
    }

    cout << "word is: " << words[0] << ", frequency is: " << frequencies[words[0]] << endl;
}
