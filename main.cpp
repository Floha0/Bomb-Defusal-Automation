#include <iostream>
#include <vector>
#include<list>
#include <map>

using namespace std;


// 13 element. 0,2,4,6,8,10,12 duvar
// 1,3,5,7,9,11 boş

class Map {
private:
    int map1[2][2] = {
        {1,2},
        {2,2}
    };

public:
    vector<vector<int>> map;

    Map(int pRow, int pCol, int tRow, int tCol) {
        int row = 9, col = 9;
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


        for (int i = 0; i < 2; i++) {
            map[map1[i][0]][map1[i][1]] = 1;
        }

        map[pRow * 2 - 1][pCol * 2 - 1] = 2;    // player
        map[tRow * 2 - 1][tCol * 2 - 1] = 3;    // target

    }
};

vector<vector<int>> Incrementor(int row, int col, Map& map);

void Pathfinder(int pRow, int pCol, int tRow, int tCol, Map& map) {
    bool solved = false;

    vector<vector<int>> playerPoses = {{pRow, pCol}};

    int k = 0;
    while (k < 5) {

        cout << playerPoses.size() << endl;

        if (playerPoses.size() <= 0) {
            cout << "Labyrinth solved!" << endl;
            break;
        }

        for (int j = 0; j < playerPoses.size(); j++) {
            cout << playerPoses[j][0] << ' ' << playerPoses[j][1] << endl;
        }

        vector<vector<int>> newPlayerPoses;

        for (int i = 0; i < playerPoses.size(); i++) {

            newPlayerPoses = Incrementor(playerPoses[i][0], playerPoses[i][1], map);

            // playerPoses = Incrementor(playerPoses[i][0], playerPoses[i][1], map);


            for (int i = 0; i < map.map.size(); i++) {
                for (int j = 0; j < map.map[i].size(); j++) {
                    cout << map.map[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        playerPoses = newPlayerPoses;

        for (int j = 0; j < playerPoses.size(); j++) {
            cout << playerPoses[j][0] << ' ' << playerPoses[j][1] << endl;
        }

        cout << "-------------" << endl;



        k++;

    }
}

vector<vector<int>> Incrementor(int row, int col, Map& map) {
    vector<vector<int>> list;

    map.map[row][col] = 0;

    // Up
    if (map.map[row - 1][col] == 0) {
        map.map[row - 1][col] =  map.map[row - 1][col] + 5;

        std::vector<int> newList;
        newList.push_back(row - 2);
        newList.push_back(col);

        list.push_back(newList);
    }

    // Down
    if (map.map[row + 1][col] == 0) {
        map.map[row + 1][col] =  map.map[row + 1][col] + 5;

        std::vector<int> newList;
        newList.push_back(row + 2);
        newList.push_back(col);

        list.push_back(newList);
    }

    // Right
    if (map.map[row][col + 1] == 0) {
        map.map[row][col + 1] =  map.map[row][col + 1] + 5;

        std::vector<int> newList;
        newList.push_back(row);
        newList.push_back(col + 2);

        list.push_back(newList);
    }

    // Left
    if (map.map[row][col - 1] == 0) {
        map.map[row][col - 1] =  map.map[row][col - 1] + 5;

        std::vector<int> newList;
        newList.push_back(row);
        newList.push_back(col - 2);

        list.push_back(newList);
    }

    return list;
}


void labyrinth(int pRow, int pCol, int tRow, int tCol) {
    Map map1 = Map(pRow,pCol,tRow,tCol);


    Pathfinder(pRow, pCol, tRow, tCol, map1);
}

int main() {
    labyrinth(1,1,1,2);
    return 0;
}
