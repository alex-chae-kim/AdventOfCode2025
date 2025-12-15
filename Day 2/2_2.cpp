#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

bool checkWord(string word) {
    bool works = true;
    int n = word.size();
    string cur;
    string prev;
    for (int j = 1; j <= n/2; j++) {
        works = true;
        if (n % j != 0) {
            continue;
        }
        prev = word.substr(0, j);
        for (int k = 0; k < n / j; k++) {
            cur = word.substr(k*j, j);
            if (cur != prev) {
                works = false;
            }
            prev = cur;
        }
        if (works) {
            return true;
        }
    }
    return false;
}

int main() {
    string range;
    long long total = 0;
    while (getline(cin, range, ',')) {
        //cout << range << endl; // log all ranges
        int dash = range.find('-');
        long long start = stoll(range.substr(0, dash));
        long long end = stoll(range.substr(dash + 1));
        for (long long i = start; i <= end; i++) {
            string cur = to_string(i);
            if (checkWord(cur)) {
                total += i;
                //cout << i << "   "; // log all invalid IDs
            }
        }
    }
    cout << total;
}