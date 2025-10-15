//
/**
 * @file zoneIn
 * @author Dawodu Johnson
 * @date 10/12/2025
 */
#include <bits/stdc++.h>
using namespace std;

struct union_find{
    int n, connect;
    vector<int>parent, rank;

    explicit union_find (int n) : n(n) {
        parent.resize(n);
        connect = n;
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n,1);
    }

    int find(int a){
        if(parent[a] == a)return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b){
        a = find(a), b = find(b);

        if(a == b)return;

        if(rank[a] < rank[b]){
            parent[a] = b;
            rank[b] += rank[a];
        }
        else{
            parent[b] = a;
            rank[a] += rank[b];
        }
        connect -= 1;
    }

    int getConnect() const {
        return connect;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("zone_in_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    vector<pair<int, int>>directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int t = 0; t < T; t++) {
        int R, C, S; cin >> R >> C >> S;

        queue<pair<int, int>> q;
        union_find disjointSet(R*C + C + 1);
        vector<vector<char>> grid(R, vector<char>(C));
        vector<vector<int>>  distance(R, vector<int>(C, 1e9));
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }


        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '.') {
                    distance[i][j] = min({i + 1, j + 1, R - i, C - j});
                }
                else {
                    distance[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (const auto& [fx, fy] : directions) {
                const int nx = fx + i, ny = fy + j;
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == '.') {
                    if ((1 + distance[i][j]) < distance[nx][ny]) {
                        distance[nx][ny] = 1 + distance[i][j];
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '#'  || (distance[i][j]-1) < S) continue;
                visited[i][j] = true;
                int flattenCoordinate = i * C + j;

                for (const auto& [fx, fy] : directions) {
                    const int nx = fx + i, ny = fy + j;
                    int otherCoordinate = nx * C + ny;
                    if (nx >= 0 and nx < R and ny >= 0 and ny < C and grid[nx][ny] == '.' and (distance[nx][ny]-1) >= S) {
                        disjointSet.unite(flattenCoordinate, otherCoordinate);
                    }
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < R; i++) {
             for (int j = 0; j < C; j++) {
                 if (visited[i][j]) {
                     int flattenCoordinate = i * C + j;
                     int root = disjointSet.find(flattenCoordinate);
                     answer = max(answer, disjointSet.rank[root]);
                 }
             }
        }

        cout << "Case #" << t+1 << ": " << answer << endl;

    }

    return 0;
}

