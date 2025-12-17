#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<long long, long long>> ranges;
    long long total = 0;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        int dash = line.find('-');
        long long start = stoll(line.substr(0, dash));
        long long end = stoll(line.substr(dash + 1));
        ranges.push_back({start, end});
    }
    sort(ranges.begin(), ranges.end());
    vector<pair<long long, long long>> mergedRanges;
    long long curStart = ranges[0].first;
    long long curEnd = ranges[0].second;
    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first <= curEnd) {
            curEnd = max(curEnd, ranges[i].second);
        } else {
            mergedRanges.push_back({curStart, curEnd});
            curStart = ranges[i].first;
            curEnd = ranges[i].second;
        }
    }
    mergedRanges.push_back({curStart, curEnd});
    for (int i = 0; i < mergedRanges.size(); i++) {
        total += (mergedRanges[i].second - mergedRanges[i].first) + 1;
    }
    cout << total;
    return 0;
}