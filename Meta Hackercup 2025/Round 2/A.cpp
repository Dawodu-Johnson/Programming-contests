//
/**
 * @file A
 * @author Dawodu Johnson
 * @date 11/15/2025
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("deciding_points_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        long long N, M;
        cin >> N >> M;

        bool check = false;

        if (M == 1) {
            if (N >= 2 && N % 2 == 0) {
                check = true;
            }
        } else {

            if (N >= M && N <= 2 * M - 2) {
                check = true;
            }
            else if (N >= 2 * M && N % 2 == 0) {
                check = true;
            }
        }

        cout << "Case #" << t << ": " << (check ? "YES" : "NO") << endl;
    }
}
