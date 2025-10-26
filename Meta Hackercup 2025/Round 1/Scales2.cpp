#include <bits/stdc++.h>
using namespace std;



int main() {
    freopen("snake_scales_chapter_2_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        auto isPossible = [&](const long long h) -> bool {
            vector<bool> visited(N, false);
            queue<int> q;

            for (int i = 0; i < N; ++i) {
                if (A[i] <= h) {
                    visited[i] = true;
                    q.push(i);
                }
            }
            while (!q.empty()) {
                const int i = q.front(); q.pop();

                if (i > 0 && !visited[i - 1] && abs(A[i] - A[i - 1]) <= h) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }
                if (i < N - 1 && !visited[i + 1] && abs(A[i] - A[i + 1]) <= h) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }
            }

            return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
        };

        long long l = 0, h = 1e9, answer = h;
        while (l <= h) {
            long long mid = (l + h) / 2;
            if (isPossible(mid)) {
                answer = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << "Case #" << t << ": " << answer << "\n";
    }
}
