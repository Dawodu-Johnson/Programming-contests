#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("snake_scales_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        function<bool(int)> isPossible = [&] (int mid) {
            vector<bool> visited(N, false);
            queue<int> q;
            q.push(0);
            visited[0] = true;

            while (!q.empty()) {
                int i = q.front(); q.pop();
                if (i > 0 && abs(A[i] - A[i-1]) <= mid && !visited[i-1]) {
                    visited[i-1] = true;
                    q.push(i-1);
                }
                if (i < N-1 && abs(A[i] - A[i+1]) <= mid && !visited[i+1]) {
                    visited[i+1] = true;
                    q.push(i+1);
                }
            }
            return all_of(visited.begin(), visited.end(), [](bool v){ return v; });
        };

        int answer = 0;

        for (int i = 0; i <= 200; i++) {
             if (isPossible(i)) {
                 answer = i; break;
             }
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
}
