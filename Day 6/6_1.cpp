#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    vector<vector<int>> nums;
    vector<char> ops;

    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> tempNums;
        string token;

        while (iss >> token) {
            if (token == "+" || token == "*") {
                ops.push_back(token[0]);
            } else {
                tempNums.push_back(std::stoi(token));
            }
        }
        if (!tempNums.empty()) {
            nums.push_back(tempNums);
        }
    }
    long long total = 0;
    for (int j = 0; j < nums[0].size(); j++) {
        char op = ops[j];
        long long tempTotal = op == '+' ? 0 : 1;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i][j] << " ";
            if (op == '+') {
                tempTotal += nums[i][j];
            } else {
                tempTotal *= nums[i][j];
            }
        }
        cout << op << "  " << tempTotal << endl;
        total += tempTotal;
    }
    cout << total;
}