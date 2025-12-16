#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long total = 0;
    string bank;
    while (cin >> bank) {
        long long curTotal = 0;
        int startIndex = 0;
        int lettersRemaining = 11;
        int n = bank.size();
        for (int l = 0; l < 12; l++) {
            int curMax = 0;
            for (int i = startIndex; i < n - lettersRemaining; i++) {
                int cur = bank[i] - '0';
                if (cur > curMax) {
                    curMax = cur;
                    startIndex = i + 1;
                    if (curMax == 9) {
                        break;
                    }
                }
            }
            curTotal += pow(10, lettersRemaining) * curMax;
            lettersRemaining--;
        }
        total += curTotal;
    }
    cout << total;
    return 0;
}