#include <iostream>
#include <vector>
#include <map>

#include "../include/knobs.h"

using namespace std;

void startKnobs() {
    map<vector<int>, string> knobs{
    {{356,12346},"Up"}, {{135,2356},"Up"},
        {{236,12346},"Down"},{{135,26},"Down"},
{{5,1456},"Left"},{{5,45},"Left"},
{{13456,1235},"Right"},{{134,1235},"Right"}
    };

    vector<int> ledConfiguration;

    cout << "Enter the first led configuration" << endl;
    int c1;
    cin >> c1;
    ledConfiguration.push_back(c1);

    cout << "Enter the second led configuration" << endl;
    int c2;
    cin >> c2;
    ledConfiguration.push_back(c2);

    if (knobs.find(ledConfiguration) != knobs.end() ) {
        cout << "The rotation is: " << knobs[ledConfiguration] << endl;
    }
    else {
        cout << "No such configuration" << endl;
    }
}
