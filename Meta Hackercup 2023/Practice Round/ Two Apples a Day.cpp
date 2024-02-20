//
// Created by JOHNSON on 2/21/2024.
//
#include <iostream>
#include<functional>
#include<fstream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;


int calc(int sum, unordered_map<int, int> &val, vector<int> &value) {
    vector<int> cant_find;

    for (int i = 0; i < value.size(); i++) {
        if (val[value[i]] > 0) {
            val[value[i]]--;

            if (val[value[i]] == 0) {
                val.erase(value[i]);
            }

            if (val[sum - value[i]] > 0) {
                val[sum - value[i]]--;
                if (val[sum - value[i]] == 0) {
                    val.erase(sum - value[i]);
                }
            } else {
                cant_find.push_back(value[i]);
            }
        }
    }
    if (cant_find.size() > 1)return INT_MAX;
    else if ((sum - cant_find[0]) <= 0)return INT_MAX;
    else return (sum - cant_find[0]);
};

int main() {

    ifstream in{"two_apples_a_day_input.txt"};
    ofstream out{"output.txt"};
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    int t;
    in >> t;

    for (int k = 0; k < t; k++) {
        int n;
        in >> n;
        vector<int> value;
        int val;

        for (int i = 0; i < (2 * n - 1); i++) {
            in >> val;
            value.push_back(val);
        }
        sort(value.begin(), value.end());
        if (n == 1) {
            out << "Case #" << k + 1 << ": " << 1 << "\n";
            continue;
        } else {
            // the max can be outside
            int answer = INT_MAX;
            unordered_map<int, int> case1;
            for (int val: value)case1[val] += 1;
            unordered_map<int, int> case2 = case1, case3 = case1;

            int maxi = value[1] + value[value.size() - 1];   // max is outside
            answer = min(answer, calc(maxi, case1, value));
            maxi = value[0] + value[value.size() - 2];       // min is outside
            answer = min(answer, calc(maxi, case2, value));
            maxi = value[0] + value[value.size() - 1];       // both min and max are inside
            answer = min(answer, calc(maxi, case3, value));
            if (answer == INT_MAX) {
                out << "Case #" << k + 1 << ": " << -1 << "\n";
            } else {
                out << "Case #" << k + 1 << ": " << answer << "\n";
            }
        }
    }
    return 0;
}
