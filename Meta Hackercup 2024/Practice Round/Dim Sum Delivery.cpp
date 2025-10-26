
#include <iostream>
#include<functional>
#include<fstream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;


int main() {
    ifstream in{"dim_sum_delivery_input.txt"};
    ofstream out{"output.txt"};

    int t;
    in >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        in >> a >> b >> c >> d;
        vector <pair<string, int>> store = {{"alice", a - 1},
                                            {"bob",   b - 1}};
        int mini = min(store[0].second, store[1].second);

        if (mini == store[0].second and mini == store[1].second) {
            out << "Case #" << i + 1 << ": NO\n";
        } else if (mini == store[1].second) {
            out << "Case #" << i + 1 << ": YES\n";
        } else {
            out << "Case #" << i + 1 << ": NO\n";
        }
    }

    return 0;
}