#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;
    int total = 0;
    bool secondSection = false;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            secondSection = true;
            continue;
        }
        if (!secondSection) {
            int dash = line.find('-');
            long long start = stoll(line.substr(0, dash));
            long long end = stoll(line.substr(dash + 1));
            ranges.push_back({start, end});
        } else {
            long long curID = stoll(line);
            for (int i = 0; i < ranges.size(); i++) {
                if (curID >= ranges[i].first && curID <= ranges[i].second) {
                    total++;
                    break;
                }
            }

        }
    }
    cout << total;
    return 0;
}