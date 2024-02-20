//
// Created by JOHNSON on 2/20/2024.
// 53.69% score
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector <vector<vector < int>>>
dp;

int solve(int index, const string &s, vector<bool> &vis, int prev, bool great, int m, int n) {
    if (index == n) {
        return 1;
    }

    if (dp[index][prev][great] != -1) {
        return dp[index][prev][great];
    }

    int answer = 0;

    if (!great) {
        for (int i = prev + 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                answer = (answer + solve(index + 1, s, vis, i, s[m + 1] == '>', m + 1, n)) % MOD;
                vis[i] = false;
            }
        }
    } else {
        for (int i = 1; i < prev; i++) {
            if (!vis[i]) {
                vis[i] = true;
                answer = (answer + solve(index + 1, s, vis, i, s[m + 1] == '>', m + 1, n)) % MOD;
                vis[i] = false;
            }
        }
    }

    dp[index][prev][great] = answer;
    return answer;
}

int main() {
    int n;
    cin >> n;
    string ins;
    cin >> ins;
    vector<bool> vis(n + 1, false);

    dp.assign(n + 1, vector < vector < int >> (n + 1, vector<int>(2, -1)));

    int result = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = true;
        result = (result + solve(1, ins, vis, i, ins[0] == '>', 0, n)) % MOD;
        vis[i] = false;
    }

    cout << result << endl;
    return 0;
}

