#include <iostream>
#include <vector>
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

vector<vector<int>> Incrementor(int row, int col, vector<Map>& copiedMaps);

void Pathfinder(int pRow, int pCol, int tRow, int tCol, Map& map) {
    bool solved = false;

    vector<vector<int>> playerPoses = {{pRow, pCol}};

    vector<Map> copiedMaps;

    for (int i = 0; i < map.map.size(); i++) {
        for (int j = 0; j < map.map[i].size(); j++) {
            cout << map.map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "----------------------" << endl;

    int k = 0;
    while (k < 5) {

        cout << playerPoses.size() << endl;

        vector<vector<int>> newPlayerPoses;

        for (int i = 0; i < playerPoses.size(); i++) {

            vector<vector<int>> incremented = Incrementor(
                playerPoses[i][0], playerPoses[i][1], copiedMaps);

            for (int j = 0; j < incremented.size(); j++) {
                bool contains = false;
                for (int l = 0; l < newPlayerPoses.size(); l++) {
                    if(newPlayerPoses[l] == incremented[j]) {
                        contains = true;
                        break;
                    }
                }

                if (!contains) {
                    newPlayerPoses.push_back(incremented[j]);
                }
            }

            cout << playerPoses[i][0] << ' ' << playerPoses[i][1] << endl;

            for (int j = 0; j < incremented.size(); j++) {
                cout << incremented[j][0] << ' ' << incremented[j][1] << endl;
            }

            cout << "    0 1 2 3 4 5 6 7 8" << endl;
            cout << "    * * * * * * * * *" << endl;
            for (int i = 0; i < map.map.size(); i++) {
                cout << i << " - ";
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

        cout << "----------------------" << endl;



        k++;

    }
}

vector<vector<int>> Incrementor(int row, int col, vector<Map>& copiedMaps) {
    vector<vector<int>> list;

    for (int i = 0; i < copiedMaps.size(); i++) {
        Map map = copiedMaps[i];


        map.map[row][col] = 0;

        // Up
        if (map.map[row - 1][col] == 0) {
            if(map.map[row - 2][col] == 3) {
                cout << "Solved" << endl;
            }

            map.map[row - 1][col] =  map.map[row - 1][col] + 5;
            map.map[row - 2][col] = 2;

            std::vector<int> newList;
            newList.push_back(row - 2);
            newList.push_back(col);

            list.push_back(newList);
        }

        // Down
        if (map.map[row + 1][col] == 0) {
            if(map.map[row + 2][col] == 3) {
                cout << "Solved" << endl;
            }

            map.map[row + 1][col] =  map.map[row + 1][col] + 5;
            map.map[row + 2][col] = 2;

            std::vector<int> newList;
            newList.push_back(row + 2);
            newList.push_back(col);

            list.push_back(newList);
        }

        // Right
        if (map.map[row][col + 1] == 0) {
            if(map.map[row][col + 2] == 3) {
                cout << "Solved" << endl;
            }

            map.map[row][col + 1] =  map.map[row][col + 1] + 5;
            map.map[row][col + 2] = 2;

            std::vector<int> newList;
            newList.push_back(row);
            newList.push_back(col + 2);

            list.push_back(newList);
        }

        // Left
        if (map.map[row][col - 1] == 0) {
            if(map.map[row][col - 2] == 3) {
                cout << "Solved" << endl;
            }

            map.map[row][col - 1] =  map.map[row][col - 1] + 5;
            map.map[row][col - 2] = 2;

            std::vector<int> newList;
            newList.push_back(row);
            newList.push_back(col - 2);

            list.push_back(newList);
        }
    }
    return list;
}


void maze(int pRow, int pCol, int tRow, int tCol) {
    Map map1 = Map(pRow,pCol,tRow,tCol);


    Pathfinder(pRow, pCol, tRow, tCol, map1);
}

int main() {
    maze(1,1,1,2);
    return 0;
}
