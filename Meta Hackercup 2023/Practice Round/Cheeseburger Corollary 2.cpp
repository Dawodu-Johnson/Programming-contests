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

int main() {

    ifstream in{"cheeseburger_corollary_2_input.txt"};
    ofstream out{"output.txt"};
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    int t;
    in >> t;

    function<long long(long long)> single = [](long long a) {
        return a;
    };

    function<long long(long long)> other = [](long long b) {
        if (b == 0) return 0ll;
        return 2ll * b - 1;
    };

    for (int k = 0; k < t; k++) {
        long long a, b, c;
        in >> a >> b >> c;
        long long answer = numeric_limits<long long>::min();
        answer = max(answer, single(c / a));
        answer = max(answer, other(c / b));

        for (int i = 1; i <= 10; i++) {
            if ((c - a) < 0)break;
            c -= a;
            answer = max(answer, i + (c / b) * 2);
        }
        out << "Case #" << k + 1 << ": " << answer << "\n";

    }
    return 0;
}
