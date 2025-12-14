#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int dial = 50;
    int revolutions = 0;
    int previous = 0;
    string cur;
    while (cin >> cur) {
        char direction = cur[0];
        int clicks = stoi(cur.substr(1));;
        revolutions = abs(clicks / 100);
        total += revolutions;
        clicks = clicks % 100;
        for (int i = 0; i < clicks; i++) {
            int delta = direction == 'R' ? 1 : -1;
            dial += delta;
            if (dial == 100) {
                dial = 0;
            }
            if (dial == -1) {
                dial = 99;
            }
            if (dial == 0) {
                total ++;
            }
        }
    }
    cout << total;
    return 0;
}