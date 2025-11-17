//
/**
 * @file B
 * @author Dawodu Johnson
 * @date 11/15/2025
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("defining_prizes_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        long long answer = 0;
        for (int i = 0; i < M; i++) {
            int b;
            cin >> b;
            answer += b;
        }

        map<int, int> countScore;
        for (int score : A) {
            countScore[score]++;
        }

        vector<long long> groups;
        for (auto it = countScore.rbegin(); it != countScore.rend(); ++it) {
            groups.push_back(it->second);
        }

        int G = groups.size();
        int max_k = min(G, M);

        vector<long long> prefixSum(max_k + 1, 0);
        vector<long long> weightSum(max_k + 1, 0);

        for (int i = 0; i < max_k; i++) {
            prefixSum[i + 1] = prefixSum[i] + groups[i];
            weightSum[i + 1] = weightSum[i] + (long long)i * groups[i];
        }

        int result = 0;
        int left = 0, right = max_k;

        while (left <= right) {
            int mid = (left + right) / 2;

            long long needed = (long long)mid * prefixSum[mid] - weightSum[mid];

            if (needed <= answer) {
                result = prefixSum[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}