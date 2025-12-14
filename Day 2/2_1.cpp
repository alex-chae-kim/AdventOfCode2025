#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string range;
    long long total = 0;
    while (getline(cin, range, ',')) {
        //cout << range << endl;
        int dash = range.find('-');
        long long start = stoll(range.substr(0, dash));
        long long end = stoll(range.substr(dash + 1));
        for (long long i = start; i <= end; i++) {
            string cur = to_string(i);
            int n = cur.size();
            if (!(n%2 == 0)) {
                continue;
            }
            string first_half = cur.substr(0, n/2);
            string second_half = cur.substr(n/2);
            if (first_half == second_half) {
                total+=i;
            }
        }
    }
    cout << total;
}