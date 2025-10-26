//
// Created by JOHNSON on 2/21/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream in{"ready_go_part_1_input.txt"};
    ofstream out{"output.txt"};


    ios_base::sync_with_stdio(false);
    in.tie(nullptr);

    int t;
    in >> t;

    for (int l = 0; l < t; l++) {
        int a, b;
        in >> a >> b;
        vector <vector<char>> mat(a, vector<char>(b));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                in >> mat[i][j];
            }
        }
        vector <vector<bool>> vis(a, vector<bool>(b, false));
        vector <pair<int, int>> dir = {{0,  1},
                                       {0,  -1},
                                       {1,  0},
                                       {-1, 0}};

        function<void(int, int, vector <pair<int, int>> &)> dfs = [&](int r, int c, vector <pair<int, int>> &adj) {
            vis[r][c] = true;

            for (auto &d: dir) {
                int x = d.first + r, y = d.second + c;

                if (min(x, y) >= 0 and x < a and y < b and mat[x][y] != 'B' and !vis[x][y]) {
                    if (mat[x][y] == '.') {
                        vis[x][y] = true;
                        adj.push_back({x, y});

                    } else {
                        dfs(x, y, adj);
                    }
                }
            }
        };
        bool check = false;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (mat[i][j] == 'W' and !vis[i][j]) {
                    vector <pair<int, int>> store;
                    dfs(i, j, store);
                    //cout << store.size() << "\n";
                    if (store.size() == 1) {
                        check = true;
                        break;
                    }
                    for (auto &k: store)vis[k.first][k.second] = false;
                }
            }
        }

        if (check) out << "Case #" << l + 1 << ": " << "YES\n";
        else out << "Case #" << l + 1 << ": " << "NO\n";

    }
    return 0;
}
