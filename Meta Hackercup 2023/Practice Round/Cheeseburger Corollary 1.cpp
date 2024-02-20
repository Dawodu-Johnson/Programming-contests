//
// Created by JOHNSON on 2/21/2024.
//
#include <iostream>
#include<functional>
#include<fstream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;

// Hackercup submissions
int main() {
    ifstream in{"cheeseburger_corollary_1_input.txt"};
    ofstream out{"output.txt"};

    int t;
    in >> t;

    for (int i = 0; i < t; i++) {
        int s, d, k;
        in >> s >> d >> k;

        if ((2 * s + 2 * d) >= k + 1 and (2 * d + s) >= k) {
            out << "Case #" << i + 1 << ": YES\n";
        } else {
            out << "Case #" << i + 1 << ": NO\n";
        }
    }

    return 0;
}

