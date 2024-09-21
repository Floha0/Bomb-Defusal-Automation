#include <iostream>
#include <vector>
#include "maze.h"

using namespace std;

class Map {
/*
 * total 13 element
 * even numbers represent wall
 * odd numbers represent empty places
*/
private:
    int map1[48][2] = {
        {1, 6},
        {2,2}, {2,3}, {2,4}, {2,6}, {2,8}, {2,9}, {2,10}, {2,11},
        {3, 2}, {3, 6},
        {4, 2}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {4, 10},
        {5, 2}, {5, 6},
        {6, 2}, {6, 3}, {6, 4}, {6,8}, {6,9}, {6,10},
        {7, 2}, {7, 8},
        {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {8, 10},
        {9, 6}, {9, 10},
        {10, 2}, {10, 3}, {10, 4}, {10, 8}, {10, 9}, {10,10},
        {11, 4}, {11, 8}
    };


public:
    vector<vector<int>> map;
    vector<int> playerPos;
    vector<int> directions;

    Map(int pRow, int pCol, int tRow, int tCol) {
        playerPos = {pRow * 2 - 1, pCol * 2 - 1};

        int row = 13, col = 13;
        map.resize(row);
        for (int i = 0; i < row; i++) {
            map[i].resize(col);
        }

        for (int i=0; i < map.size(); i++) {
            map[0][i] = 1;
            map[i][0] = 1;
            map[map.size() - 1][i] = 1;
            map[i][map.size() - 1] = 1;
        }


        for (int i = 0; i < 48; i++) {
            map[map1[i][0]][map1[i][1]] = 1;
        }

        map[pRow * 2 - 1][pCol * 2 - 1] = 2;    // player
        map[tRow * 2 - 1][tCol * 2 - 1] = 3;    // target

    }
};

void AltPaths(int row, int col, vector<Map>& copiedMaps, bool& solved) {
    /*
    * Incrementorda yapılacaklar:
    * yol açıksa player pos'un yerini değiştirip mapi bir listeye kaydetcek
    * sonda her liste elemanı için for loop ile parametredeki map listesine map eklenecek
    */

    vector<Map> newMaps;

    for (int i = 0; i < copiedMaps.size(); i++) {
        Map map = copiedMaps[i];

        row = map.playerPos[0];
        col = map.playerPos[1];

        map.map[row][col] = 0;

        // Up
        if (map.map[row - 1][col] == 0) {

            Map newMap = map;

            newMap.directions.push_back(1);

            cout << "Up" << endl;

            if(newMap.map[row - 2][col] == 3) {
                copiedMaps.clear();
                copiedMaps.push_back(newMap);

                solved = true;

                break;
            }


            newMap.map[row - 1][col] =  newMap.map[row - 1][col] + 5;
            newMap.map[row - 2][col] = 2;

            newMap.playerPos = {row - 2, col};

            newMaps.push_back(newMap);
        }

        // Down
        if (map.map[row + 1][col] == 0) {

            Map newMap = map;

            newMap.directions.push_back(2);

            cout << "Down" << endl;

            if(map.map[row + 2][col] == 3) {
                copiedMaps.clear();
                copiedMaps.push_back(newMap);

                solved = true;

                break;
            }


            newMap.map[row + 1][col] =  newMap.map[row + 1][col] + 5;
            newMap.map[row + 2][col] = 2;

            newMap.playerPos = {row + 2, col};

            newMaps.push_back(newMap);
        }

        // Right
        if (map.map[row][col + 1] == 0) {

            Map newMap = map;

            newMap.directions.push_back(3);

            cout << "Right" << endl;

            if(map.map[row][col + 2] == 3) {
                copiedMaps.clear();
                copiedMaps.push_back(newMap);

                solved = true;

                break;
            }


            newMap.map[row][col + 1] =  newMap.map[row][col + 1] + 5;
            newMap.map[row][col + 2] = 2;

            newMap.playerPos = {row, col + 2};

            newMaps.push_back(newMap);
        }

        // Left
        if (map.map[row][col - 1] == 0) {

            Map newMap = map;

            newMap.directions.push_back(4);

            cout << "Left" << endl;

            if(map.map[row][col - 2] == 3) {
                copiedMaps.clear();
                copiedMaps.push_back(newMap);

                solved = true;

                break;
            }


            newMap.map[row][col - 1] =  newMap.map[row][col - 1] + 5;
            newMap.map[row][col - 2] = 2;

            newMap.playerPos = {row, col - 2};

            newMaps.push_back(newMap);
        }
    }

    if (!solved) {
        copiedMaps = newMaps;
    }

}

void Pathfinder(int pRow, int pCol, int tRow, int tCol, Map& map) {
    bool solved = false;

    vector<vector<int>> playerPoses = {{pRow, pCol}};

    vector<Map> copiedMaps;
    copiedMaps.push_back(map);

    for (int i = 0; i < map.map.size(); i++) {
        for (int j = 0; j < map.map[i].size(); j++) {
            cout << map.map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "----------------------" << endl;

    int k = 0;
    while (k < 10 || !solved) {
        AltPaths(pRow, pCol, copiedMaps, solved);

        if (solved) {
            map = copiedMaps[0];
            break;
        }

        vector<Map> tmpMaps = copiedMaps;
        copiedMaps.clear();

        for (int i = 0; i < tmpMaps.size(); i++) {
            bool contains = false;
            for (int j = 0; j < copiedMaps.size(); j++) {
                if (copiedMaps[j].playerPos == tmpMaps[i].playerPos){
                    contains = true;
                }
            }
            if (!contains) {
                copiedMaps.push_back(tmpMaps[i]);
            }
        }

        cout << copiedMaps.size() << endl;

        for (int i = 0; i < copiedMaps.size(); i++) {

            cout << endl;

            cout << endl;

            for (int k = 0; k < copiedMaps[i].map.size(); k++) {
                for (int j = 0; j < copiedMaps[i].map[i].size(); j++) {
                    cout << copiedMaps[i].map[k][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << endl << "----------------------" << endl;

        k++;

    }

    cout << endl << endl;

    for (int i = 0; i < map.map.size(); i++) {
        for (int j = 0; j < map.map[i].size(); j++) {
            cout << map.map[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "-------------------------------------------------" << endl;

    for (int i = 0; i < map.directions.size(); i++) {
        string direction;
        switch (map.directions[i]) {
            case 1:
                direction = "Up";
                break;
            case 2:
                direction = "Down";
                break;
            case 3:
                direction = "Right";
                break;
            case 4:
                direction = "Left";
                break;
        }
        cout << direction;
        if (i < map.directions.size() -1 ) {
            cout << " - ";
        }
    }
    cout << endl;
}

void maze(int pRow, int pCol, int tRow, int tCol) {
    Map map = Map(pRow,pCol,tRow,tCol);

    Pathfinder(pRow, pCol, tRow, tCol, map);
}

void startMaze() {
    int map1[2][2] = {{2, 1}, {3, 6}};

    int sign1Row, sign1Col, sign2Row, sign2Col;

    cout << "Please enter first sign's row number: ";
    cin >> sign1Row;
    cout << endl;

    cout << "Please enter second sign's column number: ";
    cin >> sign1Col;
    cout << endl;

    cout << "Please enter second sign's row number: ";
    cin >> sign2Row;
    cout << endl;

    cout << "Please enter second sign's column number: ";
    cin >> sign2Col;
    cout << endl;

    if (sign1Row == map1[0][0] && sign1Col == map1[0][1] &&
        sign2Row == map1[1][0] && sign2Col == map1[1][1]) {
        cout << "Map found!" << endl << endl;
        }
    else if(sign1Row == map1[1][0] && sign1Col == map1[1][1] &&
        sign2Row == map1[0][0] && sign2Col == map1[0][1]) {
        cout << "Map found!" << endl << endl;
        }
    else {
        cout << "Map doesn't exist!" << endl;
        return;
    }

    int pRow, pCol, tRow, tCol;

    cout << "Please enter your row number: ";
    cin >> pRow;
    cout << endl;

    cout << "Please enter your column number: ";
    cin >> pCol;
    cout << endl;

    cout << "Please enter target's row number: ";
    cin >> tRow;
    cout << endl;

    cout << "Please enter target's column number: ";
    cin >> tCol;
    cout << endl;

    maze(pRow,pCol,tRow,tCol);
}