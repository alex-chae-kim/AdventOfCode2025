#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkAdjacent(int r, int c, vector<vector<int>> &diagram, const int &rMax, const int &cMax) {
    int total = 0;
    int deltaR[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    int deltaC[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < 8; i++) {
        int newR = r + deltaR[i];
        int newC = c + deltaC[i];
        if (newR >= 0 && newR < rMax && newC >= 0 && newC < cMax) {
            if (diagram[newR][newC] == 1) {
                total++;
            }
        }
        if (total > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> diagram;
    long long total = 0;
    string line;
    while (cin >> line) {
        vector<int> curRow;
        for (char c : line) {
            int cur = c == '@' ? 1 : 0;
            curRow.push_back(cur);
        }
        diagram.push_back(curRow);
    }
    int rMax = diagram.size();
    int cMax = diagram[0].size();
    bool repeat = true;
    while (repeat) {
        int thisIterationTotal = 0;
        for (int r = 0; r < rMax; r++) {
            for (int c = 0; c < cMax; c++) {
                if (diagram[r][c] == 1 && checkAdjacent(r, c, diagram, rMax, cMax)) {
                    diagram[r][c] = 0;
                    thisIterationTotal++;
                }
            }
        }
        total += thisIterationTotal;
        if (thisIterationTotal == 0) {
            repeat = false;
        }
    }
    cout << total;
    return 0;
}