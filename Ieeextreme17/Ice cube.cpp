//
// Created by JOHNSON on 2/20/2024.
// 100% score

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1005;

vector <vector<vector < long long>>>
memo;

long long solve(int i, int j, vector <vector<int>> &mat, int k, int b, int counter) {
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || counter >= k) {
        return INT_MIN;
    }

    if (i == mat.size() - 1 && j == mat[0].size() - 1) {
        if (mat[i][j] < b && (counter + 1) >= k) {
            return INT_MIN;
        }
        return mat[i][j];
    }

    if (memo[i][j][counter] != -1) {
        return memo[i][j][counter];
    }

    long long right = 0, down = 0, kk = counter;

    if (mat[i][j] < b) {
        kk += 1;
    } else {
        kk = 0;
    }

    right = solve(i, j + 1, mat, k, b, kk);
    down = solve(i + 1, j, mat, k, b, kk);

    memo[i][j][counter] = max(right, down) + mat[i][j];
    return memo[i][j][counter];
}

int main() {
    int n, m, t, k, b;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m >> k >> b;
        vector <vector<int>> mat(n, vector<int>(m));

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin >> mat[j][l];
            }
        }
        memo.resize(n + 1, vector < vector < long long >> (m + 1, vector<long long>(k + 1, -1)));

        int s = solve(0, 0, mat, k, b, 0);

        if (s < 0) {
            cout << "Case " << i + 1 << ": IMPOSSIBLE\n";
        } else {
            cout << "Case " << i + 1 << ": " << s << "\n";
        }


        memo.clear();
    }

    return 0;
}
