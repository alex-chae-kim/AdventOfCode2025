#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long total = 0;
    string bank;
    while (cin >> bank) {
        int tens = -1;
        int ones = -1;
        cout << bank << endl;
        int n = bank.size();
        for (int i = 0; i < n; i++) {
            int cur = bank[i] - '0';
            if (cur > tens && i != n - 1) {
                tens = cur;
                ones = bank[i + 1] - '0';
            }
            else if (cur > ones) {
                ones = cur;
            }
        }
        total += 10*tens + ones;
        cout << 10*tens + ones << endl;
    }
    cout << total;
    return 0;
}