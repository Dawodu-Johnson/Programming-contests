//
// Created by JOHNSON on 2/21/2024.
//
#include <bits/stdc++.h>

using namespace std;

void solve(int sum, long long product, long long p, vector<int> &factors, vector <vector<int>> &answer, vector<int> &temp) {
    if (product > p)return;
    if (answer.size() >= 1)return;

    if (product == p) {
        if (sum == 0) {
            answer.push_back(temp);
        } else if ((temp.size() + sum) <= 100) {
            int k = sum;
            while (k--) {
                temp.push_back(1);
            }
            answer.push_back(temp);
            k = sum;
            while (k--) {
                temp.pop_back();
            }
        }
        return;
    }

    for (int f: factors) {

        if ((sum - f) >= 0) {
            temp.push_back(f);
            solve(sum - f, product * f, p, factors, answer, temp);
            temp.pop_back();
        } else break;
    }
}


int main() {

    ifstream in{"sum_41_chapter_1_input.txt"};
    ofstream out{"output.txt"};
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    int t;
    in >> t;
    for (int i = 0; i < t; i++) {
        long long p;
        in >> p;
        vector<int> factors;

        for (int s = 2; s <= 41; s++) {
            if (p % s == 0) {
                factors.push_back(s);
            }
        }

        vector <vector<int>> answer;
        vector<int> temp;
        solve(41, 1ll, p, factors, answer, temp);
        if (answer.empty()) {
            out << "Case #" << i + 1 << ": " << -1 << "\n";
        } else {
            sort(answer.begin(), answer.end(), [](auto &one, auto &two) {
                return one.size() < two.size();
            });
            out << "Case #" << i + 1 << ": " << answer[0].size() << " ";
            for (int i = 0; i < answer[0].size(); i++) {
                out << answer[0][i] << " ";
            }
            out << "\n";
        }
    }
    return 0;
}
