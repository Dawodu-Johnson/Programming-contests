#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("warm_up_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        vector<int> A(n), B(n);
        for (int &x : A) cin >> x;
        for (int &y : B) cin >> y;

        unordered_map<int, vector<int>> mapA;
        for (int i = 0; i < n; i++) mapA[A[i]].push_back(i + 1);

        bool possible = true;
        for (int i = 0; i < n; i++) if (A[i] > B[i]) possible = false;
        for (int i = 0; i < n && possible; i++) if (mapA.find(B[i]) == mapA.end()) possible = false;

        if (!possible) {
            cout << "Case #" << t + 1 << ": -1\n";
            continue;
        }

        unordered_map<int, vector<int>> need;
        for (int i = 0; i < n; i++) if (A[i] != B[i]) need[B[i]].push_back(i + 1);

        vector<pair<int,int>> pairs;
        vector<int> targets;
        for (auto &[target, _] : need) targets.push_back(target);
        sort(targets.begin(), targets.end());

        for (int target : targets) {
            if (mapA.find(target) == mapA.end()) {
                possible = false;
                break;
            }
            int src = mapA[target][0];
            for (int idx : need[target]) pairs.emplace_back(src, idx);
        }

        if (!possible) {
            cout << "Case #" << t + 1 << ": -1\n";
            continue;
        }

        cout << "Case #" << t + 1 << ": " << pairs.size() << "\n";
        for (auto &[a,b] : pairs) cout << min(a,b) << " " << max(a,b) << "\n";
    }

    return 0;
}
