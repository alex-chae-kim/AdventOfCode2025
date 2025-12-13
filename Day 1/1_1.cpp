#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int dial = 50;
    int zeroes = 0;
    string cur;
    while (cin >> cur) {
        char direction = cur[0];
        int clicks = stoi(cur.substr(1));
        clicks = direction == 'R' ? clicks : -clicks;
        dial += clicks;
        zeroes = clicks / 100;
        dial = dial % 100;
        dial = dial < 0 ? dial + 100 : dial;
        if (dial == 0) {
            total++;
        }
    }
    cout << total;
    return 0;
}

// if dial >= 100, we passed 0
// if dial < 0, we passed 0