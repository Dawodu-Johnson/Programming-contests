//
// Created by JOHNSON on 2/20/2024.
// 100% score

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1005;

int main() {
    int n, m;
    cin >> n >> m;

    vector <vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

    }

    vector <vector<double>> sum(n, vector<double>(m, 1.0));
    vector <vector<double>> allof(n, vector<double>(m, 1.0));

    vector <pair<int, int>> dir = {{0,  1},
                                   {0,  -1},
                                   {1,  0},
                                   {-1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x, y;
            double counter = 0;
            for (auto &d: dir) {
                x = i + d.first;
                y = j + d.second;
                if (x >= 0 && y >= 0 && x < n && y < m && matrix[i][j] > matrix[x][y]) {
                    counter += 1;
                }
            }
            if (counter > 0) {
                sum[i][j] = 1.0 / counter;
            }
        }
    }


    vector <vector<bool>> vis(n, vector<bool>(m, false));

    multimap<int, pair<int, int>, greater<int>> store1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            store1.insert({matrix[i][j], {i, j}});
        }
    }

    for (auto &f: store1) {
        auto k = f.second;
        for (auto &d: dir) {
            int x = k.first + d.first;
            int y = k.second + d.second;
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[k.first][k.second] > matrix[x][y]) {
                // cout << k.first << " " << k.second << " " << sum[k.first][k.second] << endl;
                //cout << "yeah\n";
                allof[x][y] += allof[k.first][k.second] * sum[k.first][k.second];
                //cout << x << " " << y << " " << allof[x][y] << endl;
            }

        }
    }

//    cout << allof[0][0] << endl;
    double answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer = max(allof[i][j], answer);
        }
    }
    // cout << sum[0][0] << endl;
    cout << fixed << setprecision(6) << answer << "\n";
    return 0;
}
