//
/**
 * @file B1
 * @author Dawodu Johnson
 * @date 10/18/2025
 */

//
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("final_product_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int lmao, a, b;
        cin >> lmao >> a >> b;
        cout << "Case #" << t << ": ";
        for (int i = 1; i < 2*lmao; i++) {
             cout <<  1 << " ";
        }
        cout << b << "\n";

    }
}
