#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

int memoryElement(int stage, int number, vector<int> memory);

void startMemory() {
    int stage = 1;
    vector<int> memory;

    int k = 0;
    while (k < 15) {
        cout << "Did you make any mistake? (type y/n)" << endl;
        char ch;
        cin >> ch;
        if (ch == 'y') {
            stage = 1;
            memory.clear();
        }

        cout << "Enter the number at the screen" << endl;
        int number;
        cin >> number;

        memory.push_back(memoryElement(stage, number, memory));
        stage++;

        if (memory.size() == 5) break;

        k++;
    }
}

int memoryElement(int stage, int number, vector<int> memory) {
    int position, label;
    if (stage == 1) {
        if (number == 1 || number == 2) {
            cout << "second position" << endl;
            position = 2;
        }
        else if(number == 3) {
            cout << "third position" << endl;
            position = 3;
        }
        else if(number == 4) {
            cout << "fourth position" << endl;
            position = 4;
        }

        cout << "Enter the label" << endl;
        cin >> label;
    }
    else if(stage == 2) {
        switch (number) {
            case 1:
                cout << "Label 4" << endl;
                label = 4;
                cout << "Enter the position" << endl;
                cin >> position;
                break;
            case 2:
                position = memory[0] / 10;
                cout << "position: " << position << endl;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 3:
                cout << "position: 1" << endl;
                position = 1;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 4:
                position = memory[0] / 10;
                cout << "position: " << position << endl;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
        }
    }
    else if(stage == 3) {
        switch (number) {
            case 1:
                label = memory[1] % 10;
                cout << "Label: " << label << endl;
                cout << "Enter the position" << endl;
                cin >> position;
            break;
            case 2:
                label = memory[0] % 10;
                cout << "Label: " << label << endl;
                cout << "Enter the position" << endl;
                cin >> position;
                break;
            case 3:
                cout << "Position: 3" << endl;
                position = 3;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 4:
                cout << "Label: 4" << endl;
                label = 4;
                cout << "Enter the position" << endl;
                cin >> position;
                break;
        }
    }
    else if (stage == 4) {
        switch (number) {
            case 1:
                position = memory[0] / 10;
                cout << "position: " << position << endl;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 2:
                cout << "position: 1" << endl;
                position = 1;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 3:
                position = memory[1] / 10;
                cout << "position: " << position << endl;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
            case 4:
                position = memory[1] / 10;
                cout << "position: " << position << endl;
                cout << "Enter the label" << endl;
                cin >> label;
                break;
        }
    }
    else if (stage == 5) {
        switch (number) {
            case 1:
                label = memory[0] % 10;
                cout << "label: " << label << endl;
            break;
            case 2:
                label = memory[1] % 10;
                cout << "label: " << label << endl;
            break;
            case 3:
                label = memory[2] % 10;
                cout << "label: " << label << endl;
            break;
            case 4:
                label = memory[3] % 10;
                cout << "label: " << label << endl;
            break;
        }
    }

    return position*10+label;
}